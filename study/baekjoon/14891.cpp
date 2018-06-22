#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

vector<int> first;
vector<int> second;
vector<int> third;
vector<int> fourth;
vector<vector<int> > wheels;
int N; int T;
vector<pair<int, int> > moves;
vector<pair<int, int> > rotateInfoR;
vector<pair<int, int> > rotateInfoL;

//for debugging purpose
void printer(int num){
	int firstSize = wheels[num - 1].size();
	for (int i = 0; i < firstSize; ++i){
		cout << wheels[num - 1][i];
	}
	cout << endl;
}
/*
//for debugging purpose
void printer2(){
	for (int i = 0; i < moves.size(); ++i){
		cout << moves[i].first << moves[i].second << endl;
	}
}
*/

void rotateCCW(int num){
    //cout << "CCW " << num << endl;
	int firstOne = wheels[num][0];
    wheels[num].erase(wheels[num].begin());
	wheels[num].push_back(firstOne);
}

void rotateCW(int num){
 	int lastOne = wheels[num][wheels[num].size() - 1];
	wheels[num].insert(wheels[num].begin(), lastOne);
	wheels[num].erase(wheels[num].end() - 1);
    //printer(2);
}

void doNext(int curWheel, int rotation){
    int index = curWheel + 1;
    for (int i = index; i < 4; ++i){
        rotation = rotation * -1;
        if (wheels[i][6] != wheels[i - 1][2]){
            rotateInfoR.push_back(make_pair(i, rotation));
        }
        else{
            break;
        }
    }
}

void doPrev(int curWheel, int rotation){
    int index = curWheel - 1;
    for (int i = index; i >= 0; --i){
        rotation = rotation * -1;
        if (wheels[i][2] != wheels[i + 1][6]){
            rotateInfoL.push_back(make_pair(i, rotation));
        }
        else{
            break;
        }
    }
}

void rotateWheel(int cur, int rotation){
    for (int i = 0; i < rotateInfoL.size(); ++i){
        if (rotateInfoL[i].second == 1){
            rotateCW(rotateInfoL[i].first);
        }
        else if (rotateInfoL[i].second == -1){
            rotateCCW(rotateInfoL[i].first);
        }
    }
    for (int i = 0; i < rotateInfoR.size(); ++i){
        if (rotateInfoR[i].second == 1){
            rotateCW(rotateInfoR[i].first);
        }
        else if (rotateInfoR[i].second == -1){
            rotateCCW(rotateInfoR[i].first);
        }
    }
    if (rotation == 1)
        rotateCW(cur);
    else if (rotation == -1)
        rotateCCW(cur);
}

void solve(){
    for (int i = 0; i < moves.size(); ++i){
        doNext(moves[i].first - 1, moves[i].second);
        doPrev(moves[i].first - 1, moves[i].second);
        rotateWheel(moves[i].first - 1, moves[i].second);
        rotateInfoL.clear();
        rotateInfoR.clear();
    }
}

void calculate(int num){
    int score = 0;
    if (wheels[0][0] == 1){
        score += 1;
    }
    if (wheels[1][0] == 1){
        score += 2;
    }
    if (wheels[2][0] == 1){
        score += 4;
    }
    if (wheels[3][0] == 1){
        score += 8;
    }
    cout << "#" << num << " " << score << endl;
}
int main(){
    //ifstream cin("input.txt");
    cin >> T;
    for (int i = 0; i < T; ++i){
        cin >> N;
        wheels.clear(); first.clear(); second.clear(); third.clear(); fourth.clear(); moves.clear(); rotateInfoR.clear(); rotateInfoL.clear();
	wheels.push_back(first); wheels.push_back(second); wheels.push_back(third); wheels.push_back(fourth);
    char number; char garbage;
	int threePos, ninePos;
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 8; ++j){
			cin >> number;
			wheels[i].push_back(number - '0');
		}
	}
        //printer(1);
        
	int fi, se;
	for (int i = 0; i < N; ++i){
		cin >> fi >> se;
        moves.push_back(make_pair(fi, se));
	}
	solve();
    calculate(i + 1);
        
    }
	return 0;
}

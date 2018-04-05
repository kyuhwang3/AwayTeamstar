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
int N;
vector<pair<int, int> > moves;

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
	int firstOne = wheels[num - 1][0]; wheels[num - 1].erase(wheels[num - 1].begin() + 1);
	wheels[num - 1].push_back(firstOne);
}

void rotateCW(int num){
	int lastOne = wheels[num - 1][wheels[num - 1].size() - 1];
	wheels[num - 1].insert(wheels[num - 1].begin(), lastOne);
	wheels[num - 1].erase(wheels[num - 1].end() - 1);
}

//wheelNum == wheel number must be > 0, ex)1,2,3
void doNext(int wheelNum, int prevRotate)
{
	cout << "next start" << endl;
	while (wheelNum < 4){
		if (wheels[wheelNum][6] != wheels[wheelNum - 1][2]){
			break;
		}
		else{
			prevRotate = prevRotate * -1;
			if (prevRotate == 1)
				rotateCW(wheelNum + 1);
			else
				rotateCCW(wheelNum + 1);
		}
		wheelNum ++;
		cout << "-----------------------------------" << endl;
		printer(1); printer(2); printer(3); printer(4);
	}
}

void doPrev(int wheelNum, int prevRotate)
{
	cout << "prev start" << endl;
	while (wheelNum > 0){
		if (wheels[wheelNum][2] != wheels[wheelNum + 1][6]){
			break;
		}
		else{
			prevRotate = prevRotate * -1;
			if (prevRotate == 1)
				rotateCW(wheelNum + 1);
			else
				rotateCCW(wheelNum + 1);
		}
		wheelNum --;
		cout << "-----------------------------------" << endl;
		printer(1); printer(2); printer(3); printer(4);
	}
}

void solve(){
	/*
	printer(1);
	rotateCCW(1);
	printer(1);
	rotateCCW(1);
	printer(1);
	*/
	for (int i = 0; i < moves.size(); ++i){
		int curRotate;
		if (moves[i].second == 1){
			//rotate CW
			curRotate = 1;
			rotateCW(moves[i].first);
		}
		else if (moves[i].second == -1){
			//rotate CCW
			curRotate = -1;
			rotateCW(moves[i].first);
		}
		cout << "begin cycle" << endl;
		cout << "-----------------------------------" << endl;
		printer(1); printer(2); printer(3); printer(4);
		doNext(moves[i].first, curRotate);
		doPrev(moves[i].first - 1, curRotate);
		cout << "done" << endl;
	}
	int score = 0;
	if (wheels[0][0] == 1)
		score += 1;
	if (wheels[1][0] == 1)
		score += 2;
	if (wheels[2][0] == 1)
		score += 4;
	if (wheels[3][0] == 1)
		score += 8;

	cout << score << endl;
}

int main(){
	wheels.push_back(first); wheels.push_back(second); wheels.push_back(third); wheels.push_back(fourth);
	ifstream cin("input.txt");
	char number;
	int threePos, ninePos;
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 8; ++j){
			cin >> number;
			wheels[i].push_back(number - '0');
		}
	}
	cin >> N;
	int fi, se;
	for (int i = 0; i < N; ++i){
		cin >> fi >> se;
		moves.push_back(make_pair(fi, se));
	}
	solve();

	return 0;
}

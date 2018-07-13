#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<pair<int, int> > candidates;
int N, M, H;
int myMap[35][15];
int minAnswer = 7;

void printer(int myMap[35][15]){
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j < N; ++j){
            cout << myMap[i][j];
        }
        cout << '\n';
    }
}

int solve(int sol[], int trial, int ladder[35][15]){
    int ladderCount = 0;
    for (int i = 0; i < trial; ++i){
        if (ladder[candidates[sol[i]].first][candidates[sol[i]].second] == 0){
            ladderCount ++;
        }
        ladder[candidates[sol[i]].first][candidates[sol[i]].second] = 1;
        //cout << candidates[sol[i]].first << " " << candidates[sol[i]].second << '\n';
    }
    
    vector<int> answer;
    for (int k = 1; k <= N; ++k){
        int curLoc = k;
        for (int i = 1; i <= H; ++i){
            if (ladder[i][curLoc] == 1){
                curLoc ++;
            }
            else if (curLoc - 1 >= 1 && ladder[i][curLoc - 1] == 1){
                curLoc --;
            }
        }
        answer.push_back(curLoc);
    }
    int checker = 1;
    for (int i = 0; i < answer.size(); ++i){
        if (i + 1 == answer[i]){
            continue;
        }
        else {
            checker = 0;
        }
    }
    if (checker){
        if (minAnswer > ladderCount){
            minAnswer = ladderCount;
        }
    }
}

void doProcess(int sol[], int num, int sizeCheck, int trial){
    if (num == trial){
        int copyMap[35][15];
        for (int i = 1; i <= H; ++i){
            for (int j = 1; j < N; ++j){
                copyMap[i][j] = myMap[i][j];           
            }
        }
        
        solve(sol, trial, copyMap);
        return;
    }
    for (int i = 0; i < sizeCheck; ++i){
        sol[num] = i;
        doProcess(sol, num + 1, sizeCheck, trial);
    }
}

int main(){
    cin >> N >> M >> H;
    int x, y;
    for (int i = 0; i < M; ++i){
        cin >> x >> y;
        myMap[x][y] = 1;
    }
    for (int i = 1; i <= H; ++i){
        for (int j = 1; j < N; ++j){
            if (myMap[i][j] == 0){
                candidates.push_back(make_pair(i, j));
            }           
        }
    }


    vector<int> answer;
    for (int k = 1; k <= N; ++k){
        int curLoc = k;
        for (int i = 1; i <= H; ++i){
            if (myMap[i][curLoc] == 1){
                curLoc ++;
            }
            else if (curLoc - 1 >= 1 && myMap[i][curLoc - 1] == 1){
                curLoc --;
            }
        }
        answer.push_back(curLoc);
    }
    int checker = 1;
    for (int i = 0; i < answer.size(); ++i){
        if (i + 1 == answer[i]){
            continue;
        }
        else {
            checker = 0;
        }
    }
    if (checker){
        cout << 0 << endl;
    }
    else{
        int sol[350];
        doProcess(sol, 0, candidates.size(), 3);
        if (minAnswer > 3){
            cout << -1 << endl;
        }
        else{
            cout << minAnswer << endl;
        }
        //printer();
    }
    return 0;
}
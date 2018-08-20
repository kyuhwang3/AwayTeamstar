#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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

int solve(vector<int> sol, int trial, int ladder[35][15]){
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
    if (sol[0] == 13 && sol[1] == 15){
        for (int i = 0 ; i < sol.size(); ++i){
            cout << sol[i] << " , ";
        }
        cout << '\n';
        for (int i = 0; i < answer.size(); ++i){
            cout << answer[i] << " , ";
        }
        cout << '\n';
        printer(ladder);
    }
    if (checker){
        if (minAnswer > ladderCount){
            minAnswer = ladderCount;
        }
    }   
}

void doProcess(vector<bool> v, int n, int r){
    fill(v.begin(), v.begin() + r, true);
    /*
    for (int i = 0; i < r; ++i){
        cout << v[i];
    }
    cout << endl;
    */

   do {
       vector<int> sol;
       for (int i = 0; i < n; ++i) {
           if (v[i]) {
               sol.push_back(i);
           }
       }
        int copyMap[35][15];
        for (int i = 1; i <= H; ++i){
            for (int j = 1; j < N; ++j){
                copyMap[i][j] = myMap[i][j];           
            }
        }
        /*
        for (int i = 0; i < r; ++i){
            cout << sol[i] << " , " ;
        }
        cout << '\n';
        */
        //cout << "R:" << r << endl;
        solve(sol, r, copyMap);
   } while (prev_permutation(v.begin(), v.end()));
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
        //int sol[500];
        vector<bool> sol(candidates.size());
        for (int t = 0; t < candidates.size(); ++t){
            sol[t] = false;
        }

        cout << "done--------------------------------------" << endl;
        doProcess(sol, candidates.size(), 2);
        if (minAnswer == 2){
            cout << 2 << endl;
            return 0;
        }

        for (int t = 0; t < candidates.size(); ++t){
            sol[t] = false;
        }      
        cout << "done--------------------------------------" << endl;
        doProcess(sol, candidates.size(), 3);
        if (minAnswer == 3){
            cout << 3 << endl;
            return 0;
        }
        
        for (int t = 0; t < candidates.size(); ++t){
            sol[t] = false;
        }

        cout << "done--------------------------------------" << endl;
        return 0;
        doProcess(sol, candidates.size(), 1);
        //return 0;
        if (minAnswer == 1){
            cout << 1 << endl;
            return 0;
        }
   
        cout << minAnswer << endl;
        cout << -1 << endl;
        
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N = 0;
int K = 0;
int ultCount = 0;
vector<vector<int> > myData(50, vector<int>(26));

void solve(vector<int> answer){
    int totalCount = 0;
    for (int i = 0; i < N; ++i){
        int know = 0;
        int letterCount = 0;
        for (int j = 0; j < 26; ++j){
            if (j != 0 && j != 2 && j != 8 && j != 13 && j != 19){
                //cout << "j=" << j << endl;
                if (myData[i][j] == 1){
                    letterCount ++;
                    for (int k = 0; k < answer.size(); ++k){
                        if (answer[k] == j){
                            //cout << "i Know" << endl;
                            know ++;
                            break;
                        }
                    }
                }
            }
        }
        //cout << letterCount << " " << know << endl;
        if (letterCount == know){
            totalCount ++;
        }
    }
    /*
    for (int i = 0; i < answer.size(); ++i){
        cout << answer[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 26; ++i){
        cout << myData[0][i] << " ";
    }
    cout << endl;
    */
    if (totalCount > ultCount){
        ultCount = totalCount;
    }
}

void doProcess(vector<int> candidates){
    vector<bool> answer(candidates.size());
    int count = 0;
    vector<int> sol(K);
    sol.clear();
    fill(answer.begin(), answer.begin() + K - 5, true);
    do{
        for (int i = 0; i < candidates.size(); ++i){
            if (answer[i]){
                sol.push_back(candidates[i]);
            }
        }
        /*
        for (int a = 0; a < sol.size(); ++a){
            cout << sol[a] << " ";
        }
        cout << endl;
        */
        solve(sol);
        sol.clear();
    } while(prev_permutation(answer.begin(), answer.end()));
}

int main(){
    cin >> N >> K;
    string tmp;
    vector<int> alphabets(26, 0);
    for (int i = 0; i < N; ++i){
        cin >> tmp;
        for (int j = 0; j < tmp.size(); ++j){
            myData[i][tmp[j] - 'a'] = 1;
            alphabets[tmp[j] - 'a'] = 1;
        }
    }
    alphabets[0] = 0;
    alphabets[2] = 0;
    alphabets[8] = 0;
    alphabets[13] = 0;
    alphabets[19] = 0;

    vector<int> candidates;
    for (int i = 0; i < 26; ++i){
        if (alphabets[i]){
            candidates.push_back(i);
        }
    }
    
    if (K >= 5){
        doProcess(candidates);
    }
    cout << ultCount << endl;
    return 0;
}
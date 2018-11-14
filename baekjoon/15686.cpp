#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int myMap[55][55];
int chickenCount = 0;
int houseCount = 0;
int ultChicken = 2e9;
vector<pair<int, int> > houseLoc;
vector<pair<int, int> > chickenLoc;

int absValue(int a, int b){
    if (a > b){
        return a - b;
    }
    else{
        return (a - b) * (-1);
    }
}

void printer(vector<int> answer, int n){
    for (int i = 0; i < n; ++i){
        cout << answer[i] << " ";
    }
    cout << '\n';
}

int calcDistance(vector<int> chickens, int n){
    int totalChickenDistance = 0;
    for (int i = 0; i < houseCount; ++i){
        int minChickenDistance = 2e9;
        for (int j = 0; j < n; ++j){
            int chickenDistance = absValue(houseLoc[i].first, chickenLoc[chickens[j]].first) + absValue(houseLoc[i].second, chickenLoc[chickens[j]].second);
            if (chickenDistance < minChickenDistance){
                minChickenDistance = chickenDistance;
            }
        }
        totalChickenDistance += minChickenDistance;
    }
    if (ultChicken > totalChickenDistance){
        ultChicken = totalChickenDistance;
    }
    return totalChickenDistance;
}

void combi(int n, int r){
    vector<bool> myData(n);
    fill(myData.begin(), myData.begin() + r, true);
    vector<int> answer(r);
    answer.clear();
    do {
        for (int i = 0; i < n; ++i){
            if (myData[i]){
                answer.push_back(i);
            }
        }
        //printer(answer, r);
        calcDistance(answer, r);
        answer.clear();
    } while(prev_permutation(myData.begin(), myData.end()));
}

int main(){
    int N, M, tmp;
    cin >> N >> M;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> tmp;
            myMap[i][j] = tmp;
            if (tmp == 2){
                chickenCount ++;
                chickenLoc.push_back(make_pair(i, j));
            }
            else if (tmp == 1){
                houseCount ++;
                houseLoc.push_back(make_pair(i, j));
            }
        }
    }
    //cout << "houseCount: " << houseCount << endl;
    //cout << "chickenCount: " << chickenCount << endl;
    for (int i = 1; i <= M; ++i){
        combi(chickenCount, i);
    }
    cout << ultChicken << endl;
    return 0;
}
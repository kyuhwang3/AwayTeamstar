#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
int myMap[10][10];
int K, N, T;
int maxCount;
vector<pair<int, int> > topPoints;
int nx[] = {-1, 1, 0, 0};
int ny[] = {0, 0, 1, -1};

void solve(int **tmpMap, int visited[][10], int x, int y, bool used, int curCount, int digging){
    for (int i = 0; i < 4; ++i){
        int newX = x + nx[i];
        int newY = y + ny[i];
        if (newX >= 0 && newX < N && newY >= 0 && newY < N){
            if (!visited[newY][newX]){
                //cout << curCount << endl;
                if (tmpMap[y][x] > tmpMap[newY][newX]){
                    visited[y][x] = 1;
                    solve(tmpMap, visited, x + nx[i], y + ny[i], false, curCount + 1, digging);
                    visited[y][x] = 0;
                }
                else {
                    if (!used){
                        visited[y][x] = 1;
                        //digging = tmpMap[y + ny[i]][x + nx[i]] - tmpMap[y][x] + 1;
                        tmpMap[y + ny[i]][x + nx[i]] = tmpMap[y][x] + 1;
                        solve(tmpMap, visited, x + nx[i], y + ny[i], true, curCount + 1, digging);
                        tmpMap[y + ny[i]][x + nx[i]] = myMap[y + ny[i]][x + nx[i]];
                        visited[y][x] = 0;
                    }
                }
                
                if (maxCount < curCount){
                    maxCount = curCount;
                }
            }
        }
    }
    cout << "---------------------"<<endl;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << tmpMap[i][j];
        }
        cout << endl;
    }
    cout << used << endl;
    cout << "----------------------" << endl;
}

int main(){
    ifstream cin("input.txt");
    cin >> T;
    cin >> N;
    cin >> K;
    for (int k = 0; k < T; ++k){
        int curMax = -1;
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                cin >> myMap[i][j];
                if (myMap[i][j] > curMax)
                    curMax = myMap[i][j];
            }
        }
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < N; ++j){
                if (myMap[i][j] == curMax){
                    topPoints.push_back(make_pair(j, i));
                }
            }
        }
        maxCount = 0;
        for (int i = 0; i < topPoints.size(); ++i){
            //maxCount = 0;
            int visited[10][10] = { 0 };
            //cout << topPoints[i].first << " " << topPoints[i].second << endl;
            int **tmpMap;
            tmpMap = new int*[10];
            for (int i = 0; i < 10; ++i){
                tmpMap[i] = new int[10];
                memcpy(tmpMap[i], myMap[i], sizeof(char) * 10);
            }
            //copy(myMap, myMap + 10 * 10, tmpMap);
            //tmpMap[1][1] = 100;

            //cout << myMap[1][1] << tmpMap[1][1] << endl;
            for (int i = 0; i < N; ++i){
                for (int j = 0; j < N; ++j){
                    cout << myMap[i][j];
                }
            }
            solve(tmpMap, visited, topPoints[i].first, topPoints[i].second, false, 0, 0);
            for (int i = 0; i < N; ++i){
                delete[] tmpMap[i];
            }
            delete[] tmpMap;
        }
        cout << maxCount << endl;
    }
    return 0;
}
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
using namespace std;

int R, C, N;
int sr, sc;
int cur_level;
char myMap[1005][1005];
int visited[1005][1005];
int myX[] = {-1,1,0,0};
int myY[] = {0,0,1,-1};
queue<pair<int, int> > bfsQueue;
queue<int> counter;
int totalCount = 0;

void mapPrinter(){
    for (int i = 0; i < C; ++i){
        for (int j = 0; j < R; ++j){
            cout << myMap[i][j];
            if (myMap[i][j] - '0' == 1){
                cout << myMap[i][j];
            }
        }
        cout << endl;
    }
}

void solve(int x, int y){
    //cout << "asd"<< endl;
    bfsQueue.push(make_pair(x, y));
    counter.push(0);
    visited[y][x] = 1;
    int target = 1;
    while (!bfsQueue.empty()){
        if (target > N){
            totalCount = counter.front();
            return;
        }
        pair<int, int> tmp = bfsQueue.front();
        int cur_count = counter.front(); counter.pop();
        bfsQueue.pop();
        //cout << "asdasdsad" << endl;
        //cout << myMap[tmp.second][tmp.first] - '0' << " " << target << endl;
        
        if (myMap[tmp.second][tmp.first] - '0' == target){
            //cout << "asd " << target << endl;
            target ++;
            //clear visited;
            //int visited[1005][1005] = {0};
            while (!bfsQueue.empty()){
                bfsQueue.pop();
                counter.pop();
            }
            for (int i = 0; i < 1005; ++i){
                for (int j = 0; j < 1005; ++j){
                    visited[i][j] = 0;
                }
            }
            bfsQueue.push(make_pair(tmp.first, tmp.second));
            counter.push(cur_count);
            /*
            for (int i = 0; i < 4; ++i){
                cout << tmp.first << tmp.second << endl;
                cout << "visited " << visited[tmp.second + myY[i]][tmp.first + myX[i]] << endl;
                cout << tmp.first + myX[i] << " " << tmp.second + myY[i] << endl;
                if (tmp.first + myX[i] >= 0 && tmp.first + myX[i] < C && tmp.second + myY[i] >= 0 && tmp.second + myY[i] < R && myMap[tmp.second + myY[i]][tmp.first + myX[i]] != 'X' && visited[tmp.second + myY[i]][tmp.first + myX[i]] == 0){
                    cout << "asdasdasdas" << endl;
                    visited[tmp.second + myY[i]][tmp.first + myX[i]] = 1;
                    bfsQueue.push(make_pair(tmp.first + myX[i], tmp.second + myY[i]));
                }
            }
             */
            continue;
        }
        else{
            //cout << "--------------------" << endl;
            for (int i = 0; i < 4; ++i){
                //cout << tmp.first + myX[i] << " " << tmp.second + myY[i] << endl;

                if (tmp.first + myX[i] >= 0 && tmp.first + myX[i] < C && tmp.second + myY[i] >= 0 && tmp.second + myY[i] < R && myMap[tmp.second + myY[i]][tmp.first + myX[i]] != 'X' && visited[tmp.second + myY[i]][tmp.first + myX[i]] == 0){

                    visited[tmp.second + myY[i]][tmp.first + myX[i]] = 1;
                    bfsQueue.push(make_pair(tmp.first + myX[i], tmp.second + myY[i]));
                    counter.push(cur_count + 1);

                }
            }
        }
    }
}

int main(){
    ifstream cin("input.txt");
    cin >> R >> C >> N;
    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            cin >> myMap[i][j];
            if (myMap[i][j] - 'S' == 0){
                sr = i;
                sc = j;
            }
        }
    }
    //cout << sr << " " << sc << endl;
    solve(sc, sr);
    cout << totalCount << endl;
    //mapPrinter();
}

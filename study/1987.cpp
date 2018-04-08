#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int R, C;
int mymap[25][25];
int visited[30] = {0};
int xs[4] = {-1, 1, 0, 0};
int ys[4] = {0, 0, -1, 1};
int maxCount = 1;
int answer = 1;

void printMap(){
    for (int i = 0; i < 30; ++i){
        cout << visited[i] << " ";
    }
    cout << endl;
}

void dfs(int x, int y){
    //cout << x << " " << y << endl;
    visited[mymap[y][x]] = 1;
    //cout << "visited " << mymap[y][x] << endl;
    //printMap();
    for (int i = 0; i < 4; ++i){
        int myX = x + xs[i];
        int myY = y + ys[i];
        //cout << myX << " " << myY << " " << endl;
        if (myX >= 0 && myX < C && myY >= 0 && myY < R && !visited[mymap[myY][myX]]){
            answer = max(++maxCount, answer);
            dfs(myX, myY);
        }
    }
    --maxCount;
    visited[mymap[y][x]] = 0;
}

void printer(){
    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            cout << mymap[i][j];
        }
        cout << endl;
    }
}

int main(){
    //ifstream cin("input.txt");
    cin >> R >> C;
    char temp;
    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            cin >> temp;
            mymap[i][j] = temp - 'A';
        }
    }
    dfs(0, 0);
    cout << answer << endl;
    //printer();
}

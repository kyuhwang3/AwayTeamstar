#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
#include <map>
#include <fstream>
using namespace std;

int C;
int R;
int K;
vector<int> answer;
int mymap[105][105] = {0};
int visited[105][105] = {0};
int ny[] = {1, -1, 0, 0};
int nx[] = {0, 0, -1, 1};

void printer(){
    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            cout << mymap[i][j];
        }
        cout << endl;
    }
}

void bfs(int y, int x){
    //printer();
    //cout << "bfs" << endl;
    queue<pair<int, int> > myqueue;
    myqueue.push(make_pair(y, x));
    mymap[y][x] = 1;
    int area = 0;
    while (!myqueue.empty()){
        y = myqueue.front().first;
        x = myqueue.front().second; myqueue.pop();
        area ++;
        for (int i = 0; i < 4; ++i){
            int myx = x + nx[i];
            int myy = y + ny[i];
            if (myx >= 0 && myx < C && myy < R && myy >= 0 && !mymap[myy][myx]){
                mymap[myy][myx] = 1;
                myqueue.push(make_pair(myy, myx));
            }
        }
    }
    answer.push_back(area);
    //cout << area << endl;
    //printer();
}

void fillUp(int lx, int ly, int tx, int ty){
    for (int i = ly; i < ty; ++i){
        for (int j = lx; j < tx; ++j){
            mymap[i][j] = 1;
        }
    }
}

int main(){
    //ifstream cin("input.txt");
    cin >> R >> C >> K;
    int leftBotX;
    int leftBotY;
    int rightTopX;
    int rightTopY;
    for (int i = 0; i < K; ++i){
        cin >> leftBotX >> leftBotY >> rightTopX >> rightTopY;
        fillUp(leftBotX, leftBotY, rightTopX, rightTopY);
    }
    //printer();
    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            if (!mymap[i][j]){
                //cout << i << " " << j;
                bfs(i, j);
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); ++i){
        cout << answer[i] << " ";
    }
    cout << endl;
    
    return 0;
}
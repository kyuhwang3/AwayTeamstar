#include <iostream>
#include <queue>
using namespace std;
int N;
int myMap[105][105];
int visited[105];
int target;

void solve(){
    queue<int> myQueue;
    myQueue.push(target);
    visited[target] = 1;

    while (!myQueue.empty()){
        int cur = myQueue.front();
        myQueue.pop();

        for (int i = 0; i < N; ++i){
            if (myMap[cur][i] && !visited[i]){
                myQueue.push(i);
                visited[i] = 1;
            }
        }
    }
}


int main(){
    cin >> N;
    cin >> target;
    int x, y;
    for (int i = 0; i < N; ++i){
        cin >> x >> y;
        myMap[y][x] = 1;
    }
    solve();
}
#include <iostream>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
int N;
int myMap[105][105];
int visited[105][105];
int target;

void solve(){
    queue<int> myQueue;
    myQueue.push(1);

    while (!myQueue.empty()){
        int cur = myQueue.front();
        myQueue.pop();

        for (int i = 1; i <= N; ++i){
            if (myMap[cur][i] && !visited[cur][i]){
                myQueue.push(i);
                visited[cur][i] = 1;
            }
        }
    }
}


int main(){
    //ifstream cin("input.txt");
    cin >> N;
    cin >> target;
    int x, y;
    for (int i = 0; i < target; ++i){
        cin >> x >> y;
        myMap[y][x] = 1;
        //cout << "hee" << endl;
    }
    //cout << "hee" << endl;
    solve();
}
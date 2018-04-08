#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

int N;
int T;
int myMap[21][21], ans;
int visited[21];
#define INF 2e9
int abs(int a){
    return a > 0 ? a : -a;
}
int min(int a, int b){
    return a > b ? b : a;
}
void solve(int total, int count, int curA){
    if (count == total){
        int A = 0, B = 0;
        for (int i = 0; i < total; ++i){
            for (int j = 0; j < total; ++j){
                if (i == j) continue;
                if (visited[i] == 1 && visited[j] == 1){
                    A += myMap[i][j];
                }
                if (visited[i] == 2 && visited[j] == 2){
                    B += myMap[i][j];
                }
            }
        }
        ans = min(ans, abs(A - B));
        return;
    }
    if (curA > 0){
        visited[count] = 1; //mark as A
        solve(total, count + 1, curA - 1);
    }
    visited[count] = 2; //mark as B
    solve(total, count + 1, curA);
    for (int i = 0; i < total; ++i){
        cout << visited[i];
    }
    cout << endl;
}

int main()
{
    ifstream cin("input.txt");
    cin >> N;
    for (int i = 0; i < N; ++i){
        cin >> T;
        for (int j = 0; j < T; ++j){
            for (int k = 0; k < T; ++k){
                cin >> myMap[j][k];
            }
        }
        ans = INF;
        solve(T, 0, T / 2);
        cout << "#" << i + 1 << " " << ans << endl;
    }
    return 0;
}

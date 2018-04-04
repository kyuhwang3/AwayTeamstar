#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N, L;
int mymap[101][101];
int ans;
void printer(){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << mymap[i][j];
        }
        cout << endl;
    }
}

void solve(){
    int prev, count;
    for (int i = 0; i < N; ++i){
        prev = mymap[i][0];
        count = 1;
        int row_check = 1;
        for (int j = 1; j < N; ++j){
            if (mymap[i][j] == prev + 1){
                //cout << "A" << count << endl;
                //prev check if L
                if (count >= L) {
                    count = 1;
                    prev = mymap[i][j];
                    continue;
                }
                else{
                    //fail
                    row_check = -1;
                    break;
                }
            }
            else if (mymap[i][j] + 1 == prev){
                //cout << "B" << endl;
                //post check if L
                int check = 1;
                for (int k = j; k < j + L; ++k){
                    if (k >= N || mymap[i][k] != mymap[i][j])
                        check = -1;
                }
                if (check == -1){
                    row_check = -1;
                    break;
                }
                else{
                    count = 0;
                    j = j + L - 1;
                    prev = mymap[i][j];
                    //cout << j << endl;
                    continue;
                }
            }
            else if (mymap[i][j] == prev){
                //cout << "C" << endl;
                count ++;
            }
            else{
                row_check = -1;
            }
        }
        if (row_check == 1){
            //cout << i << endl;
            ans ++;
        }
        else{
            //cout << "-----------" << endl;
        }
    }
}


void solve2(){
    int prev, count;
    for (int i = 0; i < N; ++i){
        prev = mymap[0][i];
        count = 1;
        int row_check = 1;
        for (int j = 1; j < N; ++j){
            if (mymap[j][i] == prev + 1){
                //cout << "A" << count << endl;
                //prev check if L
                if (count >= L) {
                    count = 1;
                    prev = mymap[j][i];
                    continue;
                }
                else{
                    //fail
                    row_check = -1;
                    break;
                }
            }
            else if (mymap[j][i] + 1 == prev){
                //cout << "B" << endl;
                //post check if L
                int check = 1;
                for (int k = j; k < j + L; ++k){
                    if (k >= N || mymap[k][i] != mymap[j][i])
                        check = -1;
                }
                if (check == -1){
                    row_check = -1;
                    break;
                }
                else{
                    count = 0;
                    j = j + L - 1;
                    prev = mymap[j][i];
                    //cout << j << endl;
                    continue;
                }
            }
            else if (mymap[j][i] == prev){
                //cout << "C" << endl;
                count ++;
            }
            else{
                row_check = -1;
            }
        }
        if (row_check == 1){
            //cout << i << endl;
            ans ++;
        }
        else{
            //cout << "-----------" << endl;
        }
    }
}



int main(){
    ans = 0;
    //ifstream cin("input.txt");
    cin >> N >> L;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> mymap[i][j];
        }
    }
    solve();
    solve2();
    cout << ans << endl;
    return 0;
}
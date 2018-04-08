#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int sny[17][17];
int ans;

void DoProcess(int tot, int rem, bool *check){
    if(rem == 0){
        int A, B;
        A = 0;
        B = 0;
        
        for(int i = 1; i <= tot; i++){
            for(int j = 1; j <= tot; j++){
                if(i == j){
                    continue;
                }else if(check[i-1] == true && check[j-1] == true){
                    A += sny[i][j];
                }else if(check[i-1] == false && check[j-1] == false){
                    B += sny[i][j];
                }
            }
        }
        
        int dif;
        if(A > B){
            dif = A-B;
        }else{
            dif = B-A;
        }
        if(ans > dif){
            ans = dif;
        }
        
        return;
    }
    
    for(int i = 1; i <= tot; i++){
        if(check[i-1] != true){
            check[i-1] = true;
            DoProcess(tot, rem-1, check);
            check[i-1] = false;
        }
    }
    for (int i = 0; i < tot; ++i){
        cout << check[i];
    }
    cout << endl;
}


int main(){
    int T, N;
    ifstream cin("input.txt");
    cin >> T;
    
    for(int i = 1; i <= T; i++){
        cin >> N;
        
        ans = 2147000000;
        memset(sny, 0, sizeof(int)*17*17);
        
        bool *check = new bool[N];
        
        memset(check, 0, sizeof(bool)*N);
        
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                cin >> sny[j][k];
            }
        }
        
        DoProcess(N, N/2, check);
        
        cout << "#" << i << " " << ans << '\n';
    }
    
    return 0;
}
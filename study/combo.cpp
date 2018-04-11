#include <iostream>
#include <cstring>

using namespace std;

int count = 0;
int N;

void Comb(int tot, int rem, bool* check, int cur){
        if(rem == 0){
                count += 1;
                cout << "#" << count << " ";
                for(int i = 0; i < tot; i++){
                        cout << check[i] << " ";
                }
                cout << '\n';
                return;
        }

        for(int i = cur; i < tot; i++){
                if(check[i] != true){
                        check[i] = true;
                        Comb(tot, rem-1, check, i+1);
                        check[i] = false;
                }
        }
}

int main(){
        cin >> N;

        bool *check = new bool[N];
        memset(check, 0, sizeof(bool)*N);

        Comb(N, N/2, check, 0);

        delete[] check;

        return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
int T;
int dp[13];
int data[12];
int price[5];
int minNumber(int a, int b){
    if (a > b)
        return b;
    return a;
}

void solve(int cur){
    int threeSum = 0;
    for (int i = 0; i < 11; ++i){
        if (i < 10){
            threeSum = dp[i] + dp[i + 1] + dp[i + 2];
        }
        else if (i == 10){
            threeSum = dp[i] + dp[i + 1];
        }
        if (threeSum > price[2]){
            dp[i] = price[2];
            dp[i + 1] = 0;
            if (i != 10)
                dp[i + 2] = 0;
            i = i + 2;
        }
    }/*
      for (int i = 0; i < 12; ++i)
      cout << dp[i] << " ";
      cout << endl;*/
    int total = 0;
    for (int i = 0; i < 12; ++i){
        total += dp[i];
    }
    cout << "#" << cur << " " << minNumber(total, price[3]) << endl;
}

int main(){
    ifstream cin("input.txt");
    cin >> T;
    for (int j = 0; j < T; ++j){
        for (int i = 0; i < 4; ++i){
            cin >> price[i];
        }
        for (int i = 0; i < 12; ++i){
            cin >> data[i];
        }
        for (int i = 0; i < 12; ++i){
            dp[i] = minNumber(data[i] * price[0], price[1]);
        }
        /*
         for (int i = 0; i < 12; ++i)
         cout << dp[i] << " ";
         cout << endl;*/
        solve(j + 1);
    }
}

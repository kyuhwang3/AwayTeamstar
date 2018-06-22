#include <iostream>
#include <fstream>
using namespace std;
int T;
int dp[13][1];
int data[12];
int price[5];

int minNumber(int a, int b){
    if (a > b)
        return b;
    return a;
}

int threeMinNumber(int a, int b, int c){
	return minNumber(minNumber(a, b), c);
}

void solve(){

	
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
	/*
        for (int i = 0; i < 12; ++i){
            dp[i] = minNumber(data[i] * price[0], price[1]);
        }
	*/
        /*
         for (int i = 0; i < 12; ++i)
         cout << dp[i] << " ";
         cout << endl;*/  
	/*need to check if 3 month boutht*/
	dp[0] = threeMinNumber(data[i] * price[0], price[1], price[2]);
	if (dp[0] == price[2])
		dp[0][0] = 1;
	else{
		dp[0][0] = 0;
	}
        solve(j + 1);
    }
}

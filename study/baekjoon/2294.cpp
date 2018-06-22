#include <iostream>
#include <algorithm>
using namespace std;

int coinTypes[105];
int memo[100000];
int N, K;
//N = number of coins
//K = amount
void doProcess(){
	for (int i = 1; i <= K; ++i){
		for (int j = 0; j < N; ++j){
			if (i - coinTypes[j] >= 0){
				if (memo[i - coinTypes[j]] != -1){
					if (memo[i] != -1)
						memo[i] = min(memo[i - coinTypes[j]] + 1, memo[i]);
					else
						memo[i] = memo[i - coinTypes[j]] + 1;
				}
			}
		}
	}
	/*
	   for (int i = 1; i <= K; ++i){
	   cout << i << ":" << memo[i] << endl;
	   }
	*/
	cout << memo[K] << endl;
	return;
}

int main(){
	for (int i = 0; i < 100000; ++i){
		memo[i] = -1;
	}
	cin >> N >> K;
	for (int i = 0; i < N; ++i){
		cin >> coinTypes[i];
	}
	int tmp;
	for (int i = 0; i < N; ++i){
		tmp = coinTypes[i];
		memo[tmp] = 1;
		//memo[coinTypes[i]] = 1;
	}
	
	/*
	   for (int i = 1; i <= K; ++i)
	   cout << i << ":" << memo[i] << endl;
	 */
	doProcess();
	return 0;
}

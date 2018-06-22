#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
long long nums[105];
long long memo[105][25];
int N;

void printer(){
	for (int i = N-1; i < N; ++i){
		for (int j = 0; j <= 20; ++j){
			cout << j<<": "<< memo[i][j] << endl;
		}
	}
	cout << "-----------------------------" << endl;
}
void solve(){
	memset(memo, 0, 105 * 25 * sizeof(long long));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j <= 20; ++j){
			memo[i][j] = 0;
		}
	}
	memo[0][nums[0]] = 1;
	if (nums[1] <= nums[0])
		memo[1][nums[0] - nums[1]] = 1;
	if (nums[1] + nums[0] <= 20)
		memo[1][nums[1] + nums[0]] = 1;
	for (int i = 2; i < N; ++i){
		for (int j = 0; j <= 20; ++j){
			if (memo[i - 1][j] == 0)
				continue;
			if (nums[i] <= j && j - nums[i] <= 20){
				memo[i][j - nums[i]] += memo[i - 1][j];
			}
			if (nums[i] + j >= 0 && nums[i] + j <= 20){
				memo[i][nums[i] + j] += memo[i - 1][j];
			}
		}
	}
	cout << memo[N-2][nums[N-1]] << endl;
	return;
}
int main(){
	//ifstream cin("input.txt");
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> nums[i];
	}
	solve();
	return 0;
}

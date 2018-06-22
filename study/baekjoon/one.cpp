#include <iostream>
#include <algorithm>
using namespace std;

void solve(long num) 
{
	int *memo = new int[num + 1];
	memo[1] = 0;
	memo[2] = 1;

	for (long i = 3; i < num + 1; i++) {
		if ((i % 3 == 0) && (i % 2 == 0)) {
			memo[i] = min(min(memo[i / 3], memo[i / 2]), memo[i - 1]) + 1;
		}
		else if (i % 3 == 0) {
			memo[i] = min(memo[i / 3], memo[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			memo[i] = min(memo[i / 2], memo[i - 1]) + 1;
		}
		else {
			memo[i] = memo[i - 1] + 1;
		}
	}
	cout << memo[num] << endl;
	delete(memo);
}

int main(void)
{
	long N;
	cin >> N;

	solve(N);
	
	return 0;
}

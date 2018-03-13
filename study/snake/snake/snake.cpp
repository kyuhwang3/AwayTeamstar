#include <iostream>
#include <vector>
#include <string>
using namespace std;

int answer = 0;
/*
void solve(int digit, int *numArr, int maxDigit) {
	if (digit == maxDigit) {
		answer++;
		return;
	}
	else if (digit == 0) {
		numArr[digit] = 1;
		solve(digit + 1, numArr, maxDigit);
	}
	else {
		if (numArr[digit - 1] == 1) {

			numArr[digit] = 0;
			solve(digit + 1, numArr, maxDigit);
		}
		else if (numArr[digit - 1] == 0) {

			numArr[digit] = 0;
			solve(digit + 1, numArr, maxDigit);
			numArr[digit] = 1;
			solve(digit + 1, numArr, maxDigit);
		}
	}
}
*/

long solveDP(int num) {
	long **memoize = new long*[num];
	for (int i = 0; i < num; i++) {
		memoize[i] = new long[3];
	}

	memoize[0][0] = 1;
	memoize[0][1] = 1;
	
	for (int i = 1; i < num; i++) {
		memoize[i][0] = memoize[i - 1][0] + memoize[i - 1][1];
		memoize[i][1] = memoize[i - 1][0];
	}
	return memoize[num - 1][1];
}

int main()
{
	int N;
	cin >> N;

	//solve(0, numArr, N);
	long answer = solveDP(N);
	cout << answer << endl;
	return 0;
}
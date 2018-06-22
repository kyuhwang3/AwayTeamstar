#include <iostream>
using namespace std;
/*
long long solve(int N) {
	long long**memoize = new long long*[N + 1];

	for (int i = 0; i < N + 1; i++) {
		memoize[i] = new long long[3];
	}

	memoize[1][1] = 1; memoize[1][2] = 0;
	memoize[2][1] = 1; memoize[2][2] = 1;

	for (int i = 3; i < N + 1; i++) {
		memoize[i][1] = memoize[i - 1][1] + memoize[i - 1][2];
		memoize[i][2] = memoize[i - 2][1] + memoize[i - 2][2];
	}
	return memoize[N][1] + memoize[N][2];
}
*/

int solve(int N)
{
	long long *memoize = new long long[N + 1];
	memoize[0] = 0;
	memoize[1] = 1;
	memoize[2] = 2;
	for (int i = 3; i < N + 1; i++)
	{
		memoize[i] = ((memoize[i - 1] % 10007) + (memoize[i - 2] % 10007)) % 10007;
	}
	return memoize[N];
}
int main(void)
{
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << endl;
		return 0;
	}
	int ans = solve(N);
	cout << ans << endl;
	return 0;
}

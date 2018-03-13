#include <iostream>
#include <algorithm>
using namespace std;

void solve(int *data, int len)
{
	int memo[len];
	memo[0] = data[0];

	for (int i = 1; i < len; i++)
	{
		memo[i] = max(memo[i - 1] + data[i], data[i]);
	}
	int maxSum = -1000;
	for (int i = 0; i < len; i++)
	{
		if (memo[i] > maxSum) {
			maxSum = memo[i];
		}
	}
	cout << maxSum;
}

int main(void)
{
	int N;
	cin >> N;
	int *data = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> data[i];
	}
	solve(data, N);
	return 0;
}

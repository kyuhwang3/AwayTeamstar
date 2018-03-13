#include <iostream>
#include <algorithm>

using namespace std;

void solve(int *dataInput, int dataSize)
{
	int *memo = new int[dataSize];
	for (int i = 0; i < dataSize; i ++) {
		memo[i] = 1;
	}

	for (int i = 0; i < dataSize; i++) {
		for (int j = 0; j < i; j++) {
			if (dataInput[i] > dataInput[j] && memo[i] < memo[j] + 1) {
				memo[i] = memo[j] + 1;
			}
		}
	}
	int maxCount = 0;
	for (int i = 0; i < dataSize; i++) {
		if (memo[i] > maxCount) {
			maxCount = memo[i];
		}
	}
	cout << maxCount << endl;
}

int main(void)
{
	int N;
	cin >> N;
	int *num = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	solve(num, N);
	delete(num);
	return 0;
}

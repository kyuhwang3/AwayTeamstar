#include <iostream>

using namespace std;

void solve(int *data, int length)
{
	int *memo = new int[length];
	for (int i = 0; i < length; i++) {
		memo[i] = data[i];
	}
	for (int i = 1; i < length; i++) {
		if (memo[i-1] < data[i]) {
			memo[i] = data[i];
		}
		else {
			memo[i] = memo[i - 1] + data[i];
		}
	}
	cout << memo[length - 1] << endl;
	delete(memo);
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
	delete(data);
	return 0;
}

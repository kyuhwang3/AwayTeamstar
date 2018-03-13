#include <iostream>
#include <algorithm>

using namespace std;

int recur(int *data, int N, int isConse, int target)
{
	if (target >= N)
		return 0;
	else {
		if (isConse >= 2)
			return recur(data, N, 0, target + 1);
		else
			return max(recur(data, N, isConse + 1, target + 1) + data[target], recur(data, N, 0, target + 1));
	}
}
/*
void solve(int *data, int N)
{
	int memo[N][3];
	memo[0][0] = 0;
	memo[0][1] = data[0];
	memo[0][2] = 0;
	for (int i = 1; i < N; i++)
	{
		memo[i][0] = max(memo[i - 1][1], memo[i - 1][2]);
		memo[i][1] = memo[i - 1][0] + data[i];
		memo[i][2] = memo[i - 1][1] + data[i];
	}
	cout << max(max(memo[N - 1][1], memo[N - 1][2]), memo[N - 1][0]) << endl;
}
*/

void memo(int *data, int N)
{
	int storage[N + 1];
	for (int i = 1; i < N + 1; i++)
		storage[i] = 0;
	storage[0] = 0;
	storage[1] = data[1];
	storage[2] = data[1] + data[2];
	for (int i = 3; i < N + 1; i++)
	{
		storage[i] = max(max(storage[i - 1], storage[i - 2] + data[i]), storage[i - 3] + data[i - 1] + data[i]);
	}
	cout << storage[N] << endl;
}

int main(void)
{
	int N;
	cin >> N;
	int *wineCap = new int[N + 1];
	for (int i = 1; i < N + 1; i++)
	{
		cin >> wineCap[i];
	}
	//int sol = recur(wineCap, N, 0, 0);
	memo(wineCap, N);
}

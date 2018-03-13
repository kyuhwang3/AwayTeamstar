#include <iostream>

using namespace std;

void solve(int digit)
{
	long **memo = new long *[digit + 1];
	for (int i = 0; i < digit + 1; i++)
	{
		memo[i] = new long[10];
	}

	memo[1][0] = 0;
	for (int i = 1; i < 10; i++)
	{
		memo[1][i] = 1;
	}
	//

	for (int i = 2; i < digit + 1; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) 
			{
				memo[i][j] = memo[i - 1][j + 1] % 1000000000;
			}
			else if (j == 9)
			{
				memo[i][j] = memo[i - 1][j - 1] % 1000000000;
			}
			else
			{
				memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	long ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += memo[digit][i];
	}
	cout << ans % 1000000000 << endl;
}

int main(void)
{
	int N;
	cin >> N;
	solve(N);
	return 0;
}

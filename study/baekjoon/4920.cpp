#include <iostream>

using namespace std;
int N;
int blocks[1005][1005];

void inputHandler()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> blocks[i][j];
		}
	}
}

void solve()
{
	
}

int main(void)
{
	inputHandler();
	solve();
	return 0;
}

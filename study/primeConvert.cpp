#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int memo[10000];
	
	for (int i = 0; i < 10000; i++)
		memo[i] = 1;
	memo[0] = memo[1] = 0;
	for (int i = 2; i < 10000; i++)
	{
		if (memo[i] == 1) {
			for (int j = i + i; j < 10000; j = j + i)
			{
				memo[j] = 0;
			}
		}
	}
	cout << memo[N] << endl;
	return 0;
}

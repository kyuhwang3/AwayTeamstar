#include <iostream>
#include <cstring>
using namespace std;

int MAX = 3000000;


int main()

{
	int num;
	int count;
	int *memo = new int[MAX];
	for (int i = 0; i < MAX; i++)
		memo[i] = 0;
	memo[0] = 1;
	memo[1] = 1;
	for (int i = 2; i < MAX; i++)
	{
		if (!memo[i])
		{
			for (int j = i + i; j < MAX; j = j + i)
				memo[j] = 1;
		}
	}
	
	cin >> num;


	while (num > 0) {
		count = 0;
		for (int i = num + 1; i <= 2 * num; i++) {
			if (!memo[i])
				count++;
		}
		cout << count << endl;
		cin >> num;
	}
	
	return 0;
}

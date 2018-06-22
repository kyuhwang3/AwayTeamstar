#include <iostream>
using namespace std;

int main(void)
{
	double N;
	cin >> N;

	int count = 1;
	N--;
	while (N >= 1)
	{
		N = N - count * 6;
		count++;
	}
	cout << count << endl;
	return 0;
}

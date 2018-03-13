#include <iostream>
#include <algorithm>
using namespace std;
/*
int solve(int sugar)
{
	if (sugar == 0) {
		return 0;
	}
	else if (sugar < 0) {
		return 50000;
	}
	else {
		return min(solve(sugar - 3) + 1, solve(sugar - 5) + 1);
	}
}
*/

int solve(int cap)
{
	int *sugar = new int[cap + 1];
	sugar[0] = 50000; sugar[1] = 50000; sugar[2] = 50000; sugar[3] = 1; sugar[4] = 50000; sugar[5] = 1;
	for (int i = 6; i < cap + 1; i++) {
		sugar[i] = min(sugar[i - 3], sugar[i - 5]) + 1;
	}
	return sugar[cap];
}
int main(void)
{
	int N;
	cin >> N;
	int minCount = solve(N);
	if (minCount >= 50000) {
		minCount = -1;
	}
	cout << minCount << endl;
	return 0;
}

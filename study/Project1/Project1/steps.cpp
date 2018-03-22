#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;				//	계단의 개수
int P[310];		//	P[i]: i 계단을 밟았을 때 얻는 점수
int maxCount = 0;
void Solve(int curStep, int cons, int score) {
	if (curStep == N - 1) {
		if (score > maxCount) {
			maxCount = score;
		}
		return;
	}
	else if (curStep >= N) {
		return;
	}
	if (cons >= 3) {
		cout << "one die" << curStep + 1 << endl;
		return;
	}
	else {
		cout << "one " << curStep + 1 << endl;
		Solve(curStep + 1, cons + 1, score + P[curStep + 1]);
		cout << "two "<< curStep + 2 << endl;
		Solve(curStep + 2, 0, score + P[curStep + 2]);
	}
}

int dpStep() {
	int memoize[310][2];


	for (int i = 1; i <= 3 && i <= N; i++)
		if (i != 3)
			memoize[i][0] = memoize[i - 1][0] + P[i];
		else
			memoize[i][0] = max(P[i] + memoize[i - 2][0], P[i] + P[i - 1]);


	for (int i = 4; i <= N; i++) {
		memoize[i][0] = max(P[i] + P[i-1] + memoize[i - 3][0], P[i] + memoize[i - 2][0]);
	}
	return memoize[N][0];
}

void InputData() {
	ifstream cin("in.txt");
	cin >> N;
	for (int i = 1; i<=N; i++) {
		cin >> P[i];
	}
}

int main() {
	InputData();					//	입력 함수

	int ans = dpStep();

	cout << ans << endl;		//	정답 출력
	return 0;
}

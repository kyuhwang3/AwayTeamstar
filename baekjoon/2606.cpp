#include <iostream>
#include <queue>
using namespace std;
int N, K;
int myMap[105][105];
int visited[105];
void doProcess(){
	queue<int> myQueue;
	myQueue.push(1);
	while (!myQueue.empty()){
		int cur = myQueue.front();
		myQueue.pop();
		for (int i = 1; i <= N; ++i){
			if (myMap[cur][i] && !visited[i]){
				myQueue.push(i);
			}
			if (myMap[i][cur] && !visited[i]){
				myQueue.push(i);
			}
		}
		visited[cur] = 1;
	}
}

int main(){
	int x, y;
	cin >> N >> K;
	for (int i = 0; i < K; ++i){
		cin >> x >> y;
		myMap[x][y] = 1;
	}
	doProcess();
	int count = 0;
	for (int i = 2; i <= N; ++i){
		if (visited[i]){
			count ++;
		}
	}
	cout << count << '\n';
	return 0;
}

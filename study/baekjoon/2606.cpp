#include <iostream>
#include <queue>
#include <map>
using namespace std;
int N, L;
int myMap[105][105];
int visited[105];

int doProcess(){
	queue<int> myQueue;
	myQueue.push(1);
	while (!myQueue.empty()){
		int curNode = myQueue.front();
		for (int i = 1; i <= N; ++i){
			if (myMap[curNode][i] == 1 && visited[curNode] == 0){
				myQueue.push(i);
			}
		}
		visited[curNode] = 1;
	}
	return 0;
}

int main(){
	int a, b;
	cin >> N >> L;
	for (int i = 0; i < L; ++i){
		cin >> a >> b;
		myMap[a][b] = 1;
	}
	doProcess();
	return 0;
}

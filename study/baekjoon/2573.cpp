#include <iostream>
#include <queue>
#include <map>
using namespace std;
int N, M;
int myMap[305][305];
int visited[305][305];
int totalCount = 0;
void doProcess(){
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			int zeroCount = 0;
			if (myMap[i][j] != 0){
				if (i - 1 >= 0){
					if (myMap[i-1][j] == 0){
						zeroCount ++;
					}
				}
				if (i + 1 < M){
					if (myMap[i+1][j] == 0){
						zeroCount ++;
					}
				}
				if (j - 1 >= 0){
					if (myMap[i][j-1] == 0){
						zeroCount ++;
					}
				}
				if (j + 1 < N){
					if (myMap[i][j+1] == 0){
						zeroCount ++;
					}
				}
			}
			if (myMap[i][j] - zeroCount < 0){
				myMap[i][j] = 0;
			}
			else{
				myMap[i][j] = myMap[i][j] - zeroCount;
			}
		}
	}
	return;
}

void isOne(){
	int x = -1;
	int y = -1;
	for (int i =0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			if (myMap[i][j] != 0){
				x = j;
				y = i;
			}
		}
	}
	if (x == -1){
		return;
	}
	queue<pair<int, int> > myQueue;
	myQueue.push(make_pair(x, y));
	while (!myQueue.empty()){
		pair<int, int> myPair = myQueue.front();
		myQueue.pop();
		int y = myPair.second;
		int x = myPair.first;
		if (y-1 >= 0 && myMap[y-1][x] != 0){
			myQueue.push(make_pair(y-1, x));
		}
		if (y+1 < M && myMap[y+1][x] != 0){
			myQueue.push(make_pair(y+1, x));
		}
		if (x-1 >= 0 && myMap[y][x-1] != 0){
			myQueue.push(make_pair(y, x-1));
		}
		if (x+1 < N && myMap[y][x+1] != 0){
			myQueue.push(make_pair(y, x+1));
		}
		visited[y][x] = 1;
	}
	return;
}

int main(){
	cin >> N >> M;
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
			cin >> myMap[i][j];
			if (myMap[i][j] != 0){
				totalCount ++;
			}
		}
	}
	doProcess();
	isOne();
	for (int i = 0; i < M; ++i){
		for (int j = 0; j < N; ++j){
		
		}
	}
	return 0;
}

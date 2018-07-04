#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
int myMap[5][5];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
queue<pair<int, int> > myQueue;

void doProcess(int x, int y, int curMap[5][5]){
	for (int i = 0; i < 4; ++i){
		if (x + dx[i] >)
	}
}

int main(){
	int x, y;
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			cin >> myMap[i][j];
			if (myMap[i][j] == 0){
				if (i - 1 >= 0){
					x = i - 1;
					y = j;
					myQueue.push(make_pair(x, y));
				}
				if (j - 1 >= 0){
					x = i;
					y = j - 1;
					myQueue.push(make_pair(x, y));
				}
				if (i + 1 < 3){
					x = i + 1;
					y = j;
					myQueue.push(make_pair(x, y));
				}
				if (j + 1 < 3){
					x = i;
					y = j + 1;
					myQueue.push(make_pair(x, y));
				}
			}
		}
	}
	while (!myQueue.empty()){
		pair<int, int> cur = myQueue.front();
		myQueue.pop();
		int locMap[5][5];
		int visited[5][5];
		for (int i = 0; i < 3; ++i){
			for (int j = 0; j < 3; ++j){
				locMap[i][j] = myMap[i][j];
				visited[i][j] = 0;
			}
		}
		doProcess(cur.first, cur.second, locMap, visited);
	}
	return 0;
}

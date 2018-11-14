#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int myMap[25][25];
int N;
int x, y, weight;
vector<pair<pair<int, int>, pair<int, int> > > candidates;   /*<x, y> <dist, weight>*/
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int getDistance(){
	queue<pair<int, int> > myQueue;
	queue<int> weightQ;
	int visited[25][25];
	for (int i = 0; i < 25; ++i){
		for (int j = 0; j < 25; ++j){
			visited[i][j] = 0;
		}
	}
	myQueue.push(make_pair(x, y));
	myQueue.push(make_pair(0, 0));
	weightQ.push(weight);
	visited[x][y] = 1;
	while (!myQueue.empty()){
		pair<int, int> cur = myQueue.front(); myQueue.pop();
		pair<int, int> curStepP = myQueue.front(); myQueue.pop(); int curStep = curStepP.first;
		int curWeight = weightQ.front(); weightQ.pop();
		for (int i = 0; i < 4; ++i){
			int toX = cur.first + dx[i];
			int toY = cur.second + dy[i];
			for (int j = 0; j < candidates.size(); ++j){
				if (candidates[j].first.first == toX && candidates[j].first.second == toY){
					candidates[j].second.first = curStep + 1;
					candidates[j].second.second = curWeight;
				}
			}


			if (toX >= 0 && toX < N && toY >= 0 && toY < N && !visited[toX][toY]){
				if (curWeight >= myMap[toX][toY]){
					visited[toX][toY] = 1;
					myQueue.push(make_pair(toX, toY));	
					myQueue.push(make_pair(curStep + 1, 0));
					if (myMap[toX][toY] > 0){
						weightQ.push(curWeight + 1);
					}
				}
			}
		}
	}
}

void printer(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cout << myMap[i][j] << " ";
		}
		cout << '\n';
	}
}

void candidatePrinter(){
	for (int i = 0; i < candidates.size(); ++i){
		cout << candidates[i].first.first << " " << candidates[i].first.second << " : " << candidates[i].second.first << candidates[i].second.second << '\n';
	}
}

int main(){
	weight = 2;
	cin >> N;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cin >> myMap[i][j];
			if (myMap[i][j] == 9){
				x = i;
				y = j;
			}
			else if (myMap[i][j] != 0){
				candidates.push_back(make_pair(make_pair(i, j), -1));
			}
		}
	}
	getDistance();	
	candidatePrinter();
	return 0;
}

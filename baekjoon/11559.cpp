#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

#define RNUM 12
#define CNUM 6
char myMap[RNUM + 1][CNUM + 1];
int visited[RNUM + 1][CNUM + 1];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void printer(){
	for (int i = 0; i < RNUM; ++i){
		for (int j = 0; j < CNUM; ++j){
			cout << myMap[i][j];
		}
		cout << '\n';
	}	
}

pair<int, int> findOne(){
	for (int i = 0; i < RNUM; ++i){
		for (int j = 0; j < CNUM; ++j){
			if (myMap[i][j] != '.' && !visited[i][j]){
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

void doProcess(int a, int b, int *count, int locVisited[][CNUM+1]){
	locVisited[a][b] = 1;
	visited[a][b] = 1;
	for (int i = 0; i < 4; ++i){
		if (a + dy[i] >= 0 && a + dy[i] < RNUM && b + dx[i] >= 0 && b + dx[i] < CNUM){
			if (myMap[a][b] == myMap[a + dy[i]][b + dx[i]] && !locVisited[a + dy[i]][b + dx[i]]){
				locVisited[a + dy[i]][b + dx[i]] = 1;
				visited[a + dy[i]][b + dx[i]] = 1;
				*count = *count + 1;
				doProcess(a + dy[i], b + dx[i], count, locVisited);
			}
		}
	}
}

void pullDown(){
	for (int i = RNUM - 1; i >= 0; --i){
		for (int j = CNUM - 1; j >= 0; --j){
			if (myMap[i][j] != '.'){
				int saveI = i;
				while (i + 1 < RNUM && myMap[i+1][j] == '.'){
					myMap[i + 1][j] = myMap[i][j];
					myMap[i][j] = '.';
					i ++;
				}
				i = saveI;
			}
		}
	}
}

int main(){
	for (int i = 0; i < RNUM; ++i){
		for (int j = 0; j < CNUM; ++j){
			cin >> myMap[i][j];
		}
	}
	pair<int, int> target = findOne();
	int conseCount = 0;
	int checker = 0;
	while (target.first != -1){
		if (target.first != -1){
			int count = 1;
			int localVisited[RNUM+1][CNUM+1] = {};
			doProcess(target.first, target.second, &count, localVisited);
			if (count >= 4){
				checker ++;
				for (int i = 0; i < RNUM; ++i){
					for (int j = 0; j < CNUM; ++j){
						if (localVisited[i][j]){
							myMap[i][j] = '.';
						}
					}
				}
			}
			else{

			}
		}
		target = findOne();
		if (target.first == -1){
			if (checker == 0){
				cout << conseCount << '\n';
				return 0;
			}
			pullDown();
			checker = 0;
			conseCount ++;
			
			for (int i = 0; i < RNUM; ++i){
				for (int j = 0; j < CNUM; ++j){
					visited[i][j] = 0;
				}
			}
			
			target = findOne();
		}
	}
	cout << conseCount << '\n';
	return 0;
}

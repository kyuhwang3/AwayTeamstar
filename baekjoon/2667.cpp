#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int myMap[30][30];
int visited[30][30];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void printer(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cout << visited[i][j];
		}
		cout << '\n';
	}
}

pair<int, int> searchForOne(){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (myMap[i][j]){
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

void doProcess(int x, int y, int num){
	visited[x][y] = num;
	myMap[x][y] = 0;
	for (int i = 0; i < 4; ++i){
		if (x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < N && !visited[x + dx[i]][y + dy[i]]){
			if (myMap[x + dx[i]][y + dy[i]]){
				//cout << "num: " << num << endl;
				visited[x + dx[i]][y + dy[i]] = num;
				//printer();
				myMap[x + dx[i]][y + dy[i]] = 0;
				doProcess(x + dx[i], y + dy[i], num);
			}
		}
	}
}

int main(){
	cin >> N;
	string s;
	for (int i = 0; i < N; ++i){
		cin >> s;
		for (int j = 0; j < N; ++j){
			myMap[i][j] = s[j] - '0';
		}
	}
	pair<int, int> starting = searchForOne();
	vector<int> answer;
	int curNum = 1;
	//cout << starting.first << " " << starting.second << '\n';	
	while (starting.first != -1){
		doProcess(starting.first, starting.second, curNum);
		starting = searchForOne();

		int totalCount = 0;
		for (int i = 0; i < N; ++i){
			for (int j = 0; j < N; ++j){
				if (visited[i][j] == curNum){
					totalCount ++;
				}
			}
		}
		answer.push_back(totalCount);
		curNum ++;
		//cout << starting.first << " " << starting.second << '\n';	
		//printer();
	}
	cout << curNum - 1 << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); ++i){
		cout << answer[i] << '\n';
	}
	//pair<int, int> test = searchForOne();
	//cout << test.first << " " << test.second << '\n';
	//printer();
	return 0;
}

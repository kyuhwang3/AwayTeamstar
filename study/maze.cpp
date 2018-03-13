#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int n, m;
int maze[105][105];
int visited[105][105];

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	q.push(make_pair(1, 1));
	visited[x][y] = 1;
	while (!q.empty())
	{

		pair<int, int> cur = q.front(); q.pop();
		pair<int, int> count = q.front(); q.pop();
		//cout << cur.first << " " << cur.second << endl;
		if (cur.first == n && cur.second == m)
		{
			cout << count.first << endl;
		}
		//north
		//cout << cur.first + 1 << " " << maze[cur.first + 1][cur.second] << " " << visited[cur.first + 1][cur.second] << endl;
		if (cur.second + 1 <= m && maze[cur.first][cur.second + 1] && visited[cur.first][cur.second + 1] != 1) {
			q.push(make_pair(cur.first, cur.second + 1));
			q.push(make_pair(count.first + 1, 0));
			visited[cur.first][cur.second + 1] = 1;
		}
		if (cur.second - 1 >= 1 && maze[cur.first][cur.second - 1] && visited[cur.first][cur.second - 1] != 1) {
			q.push(make_pair(cur.first, cur.second - 1));
			q.push(make_pair(count.first + 1, 0));
			visited[cur.first][cur.second - 1] = 1;
		}
		if (cur.first + 1 <= n && maze[cur.first + 1][cur.second] && visited[cur.first + 1][cur.second] != 1) {
			q.push(make_pair(cur.first + 1, cur.second));
			q.push(make_pair(count.first + 1, 0));
			visited[cur.first + 1][cur.second] = 1;
		}
		if (cur.first - 1 >= 1 && maze[cur.first - 1][cur.second] && visited[cur.first - 1][cur.second] != 1) {
			q.push(make_pair(cur.first - 1, cur.second));
			q.push(make_pair(count.first + 1, 0));
			visited[cur.first - 1][cur.second] = 1;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(1, 1);
}
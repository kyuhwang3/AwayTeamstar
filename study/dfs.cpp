#include <iostream>

using namespace std;

int map[10010][10010];
int visited[1001];
int queue[3000];
int N, M, V;

void DFS(int start)
{
	visited[start] = 1;
	cout << start << " ";
	for (int i = 1; i < N + 1; i++)
	{
		if ((map[start][i] == 1) && !visited[i]) {
			DFS(i);
		}
	}
}

void BFS(int start) 
{
	int front = 1, rear = 1;
	queue[1] = start;
	rear++;

	visited[start] = 1;
	int cur;
	while (front < rear)
	{
		cur = queue[front];
		front++;
		cout << cur << " ";
		for (int i = 1; i < N + 1; i++)
		{
			if (map[cur][i] && !visited[i]) {
				queue[rear] = i;
				rear++;
				visited[i] = 1;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i <= 10010; i++)
		for (int j = 0; j <= 10010; j++)
			map[i][j] = 0;
	for (int i = 1; i <= 1001; i++)
		visited[i] = 0;

	cin >> N >> M >> V;

	int start, end;
	for (int i = 1; i < M + 1; i++)
	{
		cin >> start >> end;
		map[start][end] = 1;
	}
	DFS(V);
	cout << endl;
	for (int i = 1; i <= 1001; i++)
		visited[i] = 0;
	BFS(V);
	return 0;
}

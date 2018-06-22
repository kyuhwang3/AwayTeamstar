#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;


int n,m,v;

int col, row;

int **adj;
int vis[1000005];

int maps[1005][1005];

struct cell
{
	int x;
	int dis;
	int destroyed;
};

void dfs(int cur)
{
	cout << cur << " ";
	if (cur == row * col - 1){
		return;
	}
	vis[cur]=1;
	for(int i=1; i<=n; ++i){
		if(adj[cur][i] && !vis[i]){
			dfs(i);
		}   
	}
}

int bfs(int src)
{
	queue<cell> q;
	cell t;
	t.x = src;
	t.dis = 1;
	t.destroyed = 0;

	q.push(t);
	vis[src]=2;
	int destroyed = 0;

	while(!q.empty()){
		cell cur=q.front();
		//printf("%d:%d ",cur.x, cur.destroyed);
		q.pop();
		for(int i=0; i < n; ++i){
			if(adj[cur.x][i] == 1 && vis[i]!=2){
				vis[i] = 2;
				cell t;
				t.x = i;
				t.dis = cur.dis + 1;
				t.destroyed = cur.destroyed;

				q.push(t);
				if (t.x == row * col - 1){
					return t.dis;
				}
			}
			// reachable
			else if (cur.destroyed == 0 && adj[cur.x][i] == 0 && vis[i]!=2){
				vis[i] = 2;
				cell t;
				t.x = i;
				t.dis = cur.dis + 1;
				t.destroyed = 1;
				q.push(t);
				//cout << "hello world" << endl;
			}
		}
	}
}

void build_graph(){
	//0 north 1 south 2 east 3 west
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			if (j + 1 < col){
				if (maps[i][j + 1] == 0){//south
					adj[i * col + j][i * col + j + 1] = 1;
				}
				else{
					adj[i * col + j][i * col + j + 1] = 0;
				}
			}
			if (j - 1 >= 0){
				if (maps[i][j - 1] == 0){//north
					adj[i * col + j][i * col + j - 1] = 1;
				}
				else{
					adj[i * col + j][i * col + j - 1] = 0;
				}
			}
			if (i + 1 < row){
				if (maps[i + 1][j] == 0){//east
					adj[i * col + j][(i + 1) * col + j] = 1;
				}
				else{
					adj[i * col + j][(i + 1) * col + j] = 0;
				}
			}
			if (i - 1 >= 0){
				if (maps[i - 1][j] == 0){//west
					adj[i * col + j][(i - 1) * col + j] = 1;
				}
				else{
					adj[i * col + j][(i - 1) * col + j] = 0;
				}
			}
		}
	}
}

int main()
{
	//ifstream cin("input.txt");
	cin >> row >> col;
	char str[1005];

	adj = new int *[row * col + 5];
	for (int i = 0; i < row * col + 5; ++i){
		adj[i] = new int[row * col + 5];
	}
	for (int i = 0; i < row; ++i){
		cin >> str;
		for (int j = 0; j < col; ++j){
			maps[i][j] = str[j] - '0';
		}
	}
	for (int i = 0; i < row * col; ++i){
		for (int j = 0; j < row * col; ++j){
			adj[i][j] = -1;
		}
	}


	build_graph();
	n = row * col;
	int ans = bfs(0);
	//cout << endl;
	cout << ans << endl;
	/*
	   for (int i = 0; i < row; ++i){
	   for (int j = 0; j < col; ++j){
	   cout << maps[i][j];
	   }
	   cout << endl;
	   }

	 */
	/*
	   for (int i = 0; i < row * col; ++i){
	   for (int j = 0; j < row * col; ++j){
	   cout << adj[i][j];
	   }
	   cout << endl;
	   }
	 */	
	return 0;
}

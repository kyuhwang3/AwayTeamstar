#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;


int source, target;
//int adj[100005];
int dist[100005];
int vis[100005];
int counter;
struct node{
	int cur;
	int count;
};
/*
int iterateQueue(queue<node> q){
	int count = 1;
	while (!q.empty()){
		node temp = q.front(); q.pop();
		if (temp.count = minLength - 1){
		if (temp.cur + 1 == target || temp.cur - 1 == target || temp.cur * 2 == target){
			count ++;
		}
		}
	}
	return count;
}
*/
void dfs(int cur)
{
	//cout << cur << " ";
	vis[cur] = 2;
	if (cur - 1 >= 0 && vis[cur - 1] != 2){
		if (cur - 1 == target){
			counter ++;
		}
		dfs(cur - 1);
	}
	if (cur + 1 <= 100000 && vis[cur + 1] != 2){
		if (cur + 1 == target){
			counter ++;
		}
		dfs(cur + 1);
	}
	if (cur * 2  <= 100000 && vis[cur * 2] != 2){
		if (cur * 2 == target){
			counter ++;
		}
		dfs(cur * 2);
	}
}

void bfs(int src)
{
	queue<node> q;
	node tempNode;
	tempNode.cur = src;
	tempNode.count = 0;
	q.push(tempNode);
	dist[src] = 0;
	vis[src] = 1;
	while(!q.empty()){
		node cur=q.front(); q.pop();
		tempNode.count = cur.count + 1;

		if (cur.cur - 1 >= 0 && vis[cur.cur - 1] != 1){
			if (dist[cur.cur] + 1 < dist[cur.cur - 1]){
				dist[cur.cur - 1] = cur.count + 1;
			} 

			tempNode.cur = cur.cur - 1;
			vis[cur.cur - 1] = 1;
			if (cur.cur - 1 == target){
				dist[target] = cur.count + 1;
				return;
			}
			q.push(tempNode);
		}
		if (cur.cur + 1 <= 100000 && vis[cur.cur + 1] != 1){
			if (dist[cur.cur] + 1 < dist[cur.cur + 1]){
				dist[cur.cur + 1] = cur.count + 1;
			} 			
			
			tempNode.cur = cur.cur + 1;
			vis[cur.cur + 1] = 1;
			if (cur.cur + 1 == target){
				dist[target] = cur.count + 1;
				return;
			}
			q.push(tempNode);

		}
		if (cur.cur * 2 <= 100000 && vis[cur.cur * 2] != 1){
			if (dist[cur.cur] + 1 < dist[cur.cur * 2]){
				dist[cur.cur * 2] = cur.count + 1;
			} 
			
			tempNode.cur = cur.cur * 2;
			vis[cur.cur * 2] = 1;
			if (cur.cur * 2 == target){
				dist[target] = cur.count + 1;
				return;
			}
			q.push(tempNode);
		}
	}
}

int main()
{
	counter = 1;
	for (int i = 0; i < 100005; ++i){
		dist[i] = 100005;
		vis[i] = 0;
	}

	cin >> source >> target;
	dfs(source);
	bfs(source);
	/*
	bfs(source);
	for (int i = 0; i <= 25; ++i){
		cout << i << ": " << propCount[i] << endl;
	}
	*/
	cout << dist[target] << endl;
	cout << counter << endl;;
}

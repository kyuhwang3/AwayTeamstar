#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;


int source, target;
//int adj[100005];
int dist[100005];
int prop[100005];
int vis[100005];
int counter;
struct node{
	int cur;
	int count;
};

int calc(){
	int ans = 1;
	if (target - 1 >= 0 && dist[target - 1] == dist[target] - 1){
		ans += prop[target - 1];
	}
	else if (target + 1 <= 100000 && dist[target + 1] == dist[target] - 1){
		ans += prop[target + 1];
	}
	else if (target % 2 == 0 && dist[target / 2] == dist[target] - 1){
		ans += prop[target / 2];
	}
	return ans;
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
		if (cur.cur - 1 >= 0){
		 	if ((vis[cur.cur - 1] == 1 && dist[cur.cur - 1] == dist[cur.cur]) || (vis[cur.cur - 1] != 1)){
				if (dist[cur.cur] + 1 < dist[cur.cur - 1]){
					dist[cur.cur - 1] = cur.count + 1;
				} 

				tempNode.cur = cur.cur - 1;
				if (cur.cur - 1 == target){	
					dist[target] = cur.count + 1;
					prop[target] = calc();
					return;
				}
				q.push(tempNode);
				vis[cur.cur - 1] = 1;
			}
			prop[cur.cur - 1] ++;
		}
		if (cur.cur + 1 <= 100000){
			if ((vis[cur.cur + 1] == 1 && dist[cur.cur + 1] == dist[cur.cur]) || (vis[cur.cur + 1] != 1)){
				if (dist[cur.cur] + 1 < dist[cur.cur + 1]){
					dist[cur.cur + 1] = cur.count + 1;
				} 			
				
				tempNode.cur = cur.cur + 1;
				if (cur.cur + 1 == target){
					dist[target] = cur.count + 1;
					prop[target] = calc();
					return;
				}
				q.push(tempNode);
				vis[cur.cur + 1] = 1;
			}
			prop[cur.cur + 1] ++;
		}
		if (cur.cur * 2 <= 100000){
			if ((vis[cur.cur * 2] == 1 && dist[cur.cur * 2] == dist[cur.cur]) || vis[cur.cur * 2] != 1){
				if (dist[cur.cur] + 1 < dist[cur.cur * 2]){
					dist[cur.cur * 2] = cur.count + 1;
				} 
				
				tempNode.cur = cur.cur * 2;
				if (cur.cur * 2 == target){
					dist[target] = cur.count + 1;
					prop[target] = calc();
					return;
				}
				q.push(tempNode);
				vis[cur.cur * 2] = 1;
			}
			prop[cur.cur * 2] ++;
		}
	}
}

int main()
{
	counter = 0;
	for (int i = 0; i < 100005; ++i){
		dist[i] = 100005;
		vis[i] = 0;
		prop[i] = 0;
	}

	cin >> source >> target;
	bfs(source);
	//counter = 0;
	//dfs(source, 0);
	/*
	bfs(source);
	for (int i = 0; i <= 25; ++i){
		cout << i << ": " << propCount[i] << endl;
	}
	*/
	cout << dist[target] << endl;
	
	if (source == target){
		cout << 0 << endl;
	}
	else{
		cout << prop[target] << endl;
	}
	
}

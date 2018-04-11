#include <iostream>
#include <queue>
#include <map>
using namespace std;
int N, K;
int visited[200010];
int count[200010];
int dist[200010];

//dist
int compdist(int s, int t){
	if (dist[t] == dist[s] + 1){
		count[t] = count[s] + count[t];
	}
	else if (dist[t] > dist[s] + 1){
		count[t] = count[s];
		dist[t] = dist[s] + 1;
	}
}

void solve(){
	queue<pair<int, int> > myQueue;
	myQueue.push(make_pair(N, 0));
	visited[N] = 1; count[N] = 1; dist[N] = 0;
	pair<int, int> cur;
	while (!myQueue.empty()){
		cur = myQueue.front(); myQueue.pop();
		//cout << cur.first << " " << cur.second << endl;
		if (cur.first == K){
			cout << dist[K] << endl;
			cout << count[K] << endl;
		}
		if (cur.first + 1 <= 100000){
			if (!visited[cur.first + 1]){
				visited[cur.first + 1] = 1;
				count[cur.first + 1] = count[cur.first];
				dist[cur.first + 1] = dist[cur.first] + 1;
				visited[cur.first + 1] = visited[cur.first] + 1;
				myQueue.push(make_pair(cur.first + 1, cur.second + 1));				
			}
			else{
				compdist(cur.first, cur.first + 1);
			}
		} 
		if (cur.first - 1 >= 0){
			if (!visited[cur.first - 1]){
				visited[cur.first - 1] = 1;
				count[cur.first - 1] = count[cur.first];
				dist[cur.first - 1] = dist[cur.first] + 1;
				visited[cur.first - 1] = visited[cur.first] + 1;
				myQueue.push(make_pair(cur.first - 1, cur.second + 1));	
			}
			else{
				compdist(cur.first, cur.first - 1);
			}
		} 
		if (cur.first * 2 <= 200000){
			if (!visited[cur.first * 2]){
				visited[cur.first * 2] = 1;
				count[cur.first * 2] = count[cur.first];
				dist[cur.first * 2] = dist[cur.first] + 1;
				visited[cur.first * 1] = visited[cur.first] + 1;
				myQueue.push(make_pair(cur.first * 2, cur.second + 1));	
			}
			else{
				compdist(cur.first, cur.first * 2);
			}
		} 
	}
}
int main(){
	cin >> N >> K;
	solve();
}
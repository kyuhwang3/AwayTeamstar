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
		//cout << cur.second << " " << cur.second << endl;
		if (cur.second == K){
			cout << dist[K] << endl;
			cout << count[K] << endl;
		}
		if (cur.second + 1 <= 100000){
			if (!visited[cur.second + 1]){
				visited[cur.second + 1] = 1;
				count[cur.second + 1] = count[cur.second];
				dist[cur.second + 1] = dist[cur.second] + 1;
				visited[cur.second + 1] = visited[cur.second] + 1;
				myQueue.push(make_pair(cur.first + 1, cur.second + 1));				
			}
			else{
				compdist(cur.second, cur.second + 1);
			}
		} 
		if (cur.second - 1 >= 0){
			if (!visited[cur.second - 1]){
				visited[cur.second - 1] = 1;
				count[cur.second - 1] = count[cur.second];
				dist[cur.second - 1] = dist[cur.second] + 1;
				visited[cur.second - 1] = visited[cur.second] + 1;
				myQueue.push(make_pair(cur.first - 1, cur.second + 1));	
			}
			else{
				compdist(cur.second, cur.second - 1);
			}
		} 
		if (cur.second * 2 <= 200000){
			if (!visited[cur.second * 2]){
				visited[cur.second * 2] = 1;
				count[cur.second * 2] = count[cur.second];
				dist[cur.second * 2] = dist[cur.second];
				visited[cur.second * 1] = visited[cur.second] + 1;
				myQueue.push(make_pair(cur.first * 2, cur.second + 1));	
			}
			else{
				compdist(cur.second, cur.second * 2);
			}
		} 
	}
}
int main(){
	cin >> N >> K;
	solve();
}
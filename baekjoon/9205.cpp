#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int T, N;
vector<pair<int, int> > myMap;
int visited[105];
int x, y, tx, ty, endx, endy;
int sol = 0;
int absValue(int xa, int ya, int xb, int yb){
	int ans = 0;
	if (xa - xb > 0){
		ans = xa - xb;
	}
	else {
		ans = xb - xa;
	}
	if (ya - yb > 0){
		ans = ans + (ya - yb);
	}
	else{
		ans = ans + (yb - ya);
	}
	return ans;
}
void doProcess(int locX, int locY){
	queue<pair<int, int> > myQueue;
	myQueue.push(make_pair(locX, locY));
	while (!myQueue.empty()){
		pair<int, int> cur = myQueue.front();
		myQueue.pop();
		if (1000 >= absValue(cur.first, cur.second, endx, endy)){
			sol = 1;
			return;
		}
		for (int i = 0; i < N; ++i){
			if (!visited[i]){
				if (1000 >= absValue(cur.first, cur.second, myMap[i].first, myMap[i].second)){
					myQueue.push(make_pair(myMap[i].first, myMap[i].second));
					visited[i] = 1;
				}
			}
		}
	}
}
/*
void doProcess(int locX, int locY){
	if (sol == 1)
		return;
	for (int i = 0; i < N; ++i){
		if (sol == 1)
			return;
		if (1000 >= absValue(locX, locY, endx, endy)){
			//cout << locX << " " << locY << " " << endx << " " << endy << '\n';
			//cout << absValue(locX, locY, endx, endy) << '\n';
			sol = 1;
			return;
		}
		if (1000 >= absValue(myMap[i].first, myMap[i].second, locX, locY)){
			if (!visited[i]){
				visited[i] = 1;
				doProcess(myMap[i].first, myMap[i].second);
				visited[i] = 0;
			}
		}
	}	
}
*/
int main(){
	cin >> T;
	for (int i = 0; i < T; ++i){
		myMap.clear();
		for (int j = 0; j < 105; ++j){
			visited[j] = 0;
		}
		cin >> N;
		cin >> x >> y;
		for (int j = 0; j < N; ++j){
			cin >> tx >> ty;
			myMap.push_back(make_pair(tx, ty));
		}
		cin >> endx >> endy;
		doProcess(x, y);
		//cout << sol << '\n';
		if (sol == 1){
			cout << "happy" << '\n';
		}
		else{
			cout << "sad" << '\n';
		}
		sol = 0;
	}
	return 0;
}

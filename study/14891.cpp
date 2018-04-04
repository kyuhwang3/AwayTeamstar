#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

queue<int> first;
queue<int> second;
queue<int> third;
queue<int> fourth;
int N;
vector<pair<int, int> > moves;

void printer(){
	int firstSize = first.size();
	for (int i = 0; i < firstSize; ++i){
		cout << first.front();
		first.push(first.front());
		first.pop();
	}
	cout << endl;
}

void printer2(){
	for (int i = 0; i < moves.size(); ++i){
		cout << moves[i].first << moves[i].second << endl;
	}
}

queue<int> rotateCCW(queue<int> q){
	int firstOne = q.front(); q.pop();
	q.push(firstOne);
	return q;
}

queue<int> rotateCW(queue<int> q){
	int lastOne = q.back();
	q.push(lastOne);
	for (int i = 0; i < 7; ++i){
		int tmp = q.front(); q.pop();
		q.push(tmp);
	}
	q.pop();
	return q;
}

void solve(){
	printer();
	first = rotateCCW(first);
	printer();
	first = rotateCCW(first);
	printer();
	first = rotateCW(first);
	printer();
	first = rotateCW(first);
	printer();
}

int main(){
	ifstream cin("input.txt");
	char number;
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 8; ++j){
			cin >> number;
			if (i == 0)
				first.push(number - '0');
			else if (i == 1)
				second.push(number - '0');
			else if (i == 2)
				third.push(number - '0');
			else if (i == 3)
				fourth.push(number - '0');
		}	
	}
	cin >> N;
	int fi, se;
	for (int i = 0; i < N; ++i){
		cin >> fi >> se;
		moves.push_back(make_pair(fi, se));
	}
	solve();
	return 0;
}

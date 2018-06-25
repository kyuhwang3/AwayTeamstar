#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define RNUM 12
#define CNUM 6
char myMap[RNUM + 1][CNUM + 1];
int visited[RNUM + 1][CNUM + 1];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void printer(){
	for (int i = 0; i < RNUM; ++i){
		for (int j = 0; j < CNUM; ++j){
			cout << myMap[i][j];
		}
		cout << '\n';
	}	
}

pair<int, int> findOne(){
	for (int i = 0; i < RNUM; ++i){
		for (int j = 0; j < CNUM; ++j){
			if (myMap[i][j] != '.'){
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

void doProcess(int x, int y){

}

int main(){
	for (int i = 0; i < RNUM; ++i){
		for (int j = 0; j < CNUM; ++j){
			cin >> myMap[i][j];
		}
	}
	//printer();
	return 0;
}

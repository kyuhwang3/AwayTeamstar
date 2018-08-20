#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
int alpha[27];
void printer(vector<string> storage){
	for (int i = 0; i < N; ++i){
		cout << storage[i] << '\n';
	}
}

void solve(vector<string> storage){
	int totalCount = 0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < 27; ++j){
			alpha[j] = 0;
		}
		char prev = storage[i][0];
		alpha[storage[i][0] - 'a'] = 1;
		int checker = 0;
		for (int j = 1; j < storage[i].length(); ++j){
			if (prev != storage[i][j] && alpha[storage[i][j] - 'a'] > 0){
				checker = 1;
				break;
			}
			prev = storage[i][j];
			alpha[storage[i][j] - 'a'] = 1;
		}
		if (checker == 0){
			totalCount ++;
		}
	}
	cout << totalCount << '\n';
}

int main(){
	cin >> N;
	vector<string> storage(101);
	string tmp;
	for (int i = 0; i < N; ++i){
		cin >> tmp;
		storage[i] = tmp;
	}
	solve(storage);
	//printer(storage);
	return 0;
}

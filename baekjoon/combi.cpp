#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, r;
	cin >> n;
	cin >> r;
	vector<bool> storage(n, false);
	fill(storage.begin(), storage.begin() + r, true);
	do{
		for (int i = 0; i < storage.size(); ++i){
			if (storage[i]){
				cout << i;
			}
		}
		cout << '\n';
	} while(prev_permutation(storage.begin(), storage.end()));
}

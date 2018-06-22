#include <iostream>

using namespace std;
int N;

bool isDecreasingNum(int num){
	if (num < 10)
		return true;
	else
		return isDecreasingNum(num / 10) > num % 10;
}

int main(){
	N = 18;
	int num;
	cin >> num;
	cout << isDecreasingNum(num) << endl;
}

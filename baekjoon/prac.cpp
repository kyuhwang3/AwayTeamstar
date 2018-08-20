#include <iostream>
#include <vector>
using namespace std;
/*
template <class T>
void func(T a){
	cout << "generic" << endl;
}

template <>
void func(int a){
	cout << "int" << endl;
}
*/
int main(){
	vector<int> test;
	for (int i = 0; i < 5; ++i){
		test.push_back(i + 1);
	}
	for (auto i = test.begin(); i != test.end(); ++i){
		cout << *i << endl;
	}
	return 0;
}

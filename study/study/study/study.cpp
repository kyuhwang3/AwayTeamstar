#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>
using namespace std;

void printer(int sudoku[][9])
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << sudoku[i][j];
		}
		cout << endl;
	}
}

bool checker(int sudoku[][9]) {
	vector<int> test(9);
	bool result = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			test[j] = sudoku[i][j];
		}
		result = true;
		sort(test.begin(), test.end());
		for (int q = 1; q < 10; q++) {
			if (test[q - 1] != q) {
				result = false;
				return result;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			test[j] = sudoku[j][i];
		}
		result = true;
		sort(test.begin(), test.end());
		for (int q = 1; q < 10; q++) {
			if (test[q - 1] != q) {
				result = false;
				return result;
			}
		}
	}
	
	return result;
}

void solve(int sudoku[][9])
{

}

int main()
{
	ifstream cin("in.txt");
	int sudoku[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
		}
	}
	bool test =  checker(sudoku);
	cout << test << endl;
    return 0;
}


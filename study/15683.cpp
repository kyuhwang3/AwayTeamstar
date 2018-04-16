#include <iostream>
#include <vector>
using namespace std;

int R, C;
int myMap[10][10];
int ultMin = 2e9;
/*
0 up
1 right
2 down
3 left
*/

void checkUp(int x, int y, int myMap[][10]){
	y--;
	while (y >= 0 && y < R && (myMap[y][x] == 0 || myMap[y][x] == 7))
		myMap[y--][x] = 7;
}

void checkLeft(int x, int y, int myMap[][10]){
	x--;
	while (x >= 0 && x < C && (myMap[y][x] == 0 || myMap[y][x] == 7))
		myMap[y][x--] = 7;
}

void checkRight(int x, int y, int myMap[][10]){
	x++;
	while (x >= 0 && x < C && (myMap[y][x] == 0 || myMap[y][x] == 7))
		myMap[y][x++] = 7;
}
void checkDown(int x, int y, int myMap[][10]){
	y++;
	while (y >= 0 && y < R && (myMap[y][x] == 0 || myMap[y][x] == 7))
		myMap[y++][x] = 7;
}
/*
0 up
1 right
2 down
3 left
*/

void solve(vector<int> camDir, int camCount){
	int tmpMap[10][10];
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			tmpMap[i][j] = myMap[i][j];
		}
	}
	int count = 0;
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			if (myMap[i][j] > 0 && myMap[i][j] < 6){
				if (camDir[count] == 0){
					checkUp(j, i, tmpMap);
					if (myMap[i][j] == 2){
						checkDown(j, i, tmpMap);
					}
					else if (myMap[i][j] == 3){
						checkRight(j, i, tmpMap);
					}
					else if (myMap[i][j] == 4){
						checkLeft(j, i, tmpMap);
						checkRight(j, i, tmpMap);
					}
					else if (myMap[i][j] == 5){
						checkLeft(j, i, tmpMap);
						checkRight(j, i, tmpMap);
						checkDown(j, i, tmpMap);
					}
				}
				else if (camDir[count] == 1){
					checkRight(j, i, tmpMap);
					if (myMap[i][j] == 2){
						checkLeft(j, i, tmpMap);
					}
					else if (myMap[i][j] == 3){
						checkDown(j, i, tmpMap);
					}
					else if (myMap[i][j] == 4){
						checkUp(j, i, tmpMap);
						checkDown(j, i, tmpMap);
					}
					else if (myMap[i][j] == 5){
						checkLeft(j, i, tmpMap);
						checkUp(j, i, tmpMap);
						checkDown(j, i, tmpMap);
					}
				}
				else if (camDir[count] == 2){
					checkDown(j, i, tmpMap);
					if (myMap[i][j] == 2){
						checkUp(j, i, tmpMap);
					}
					else if (myMap[i][j] == 3){
						checkLeft(j, i, tmpMap);
					}
					else if (myMap[i][j] == 4){
						checkRight(j, i, tmpMap);
						checkLeft(j, i, tmpMap);
					}
					else if (myMap[i][j] == 5){
						checkLeft(j, i, tmpMap);
						checkRight(j, i, tmpMap);
						checkUp(j, i, tmpMap);
					}
				}
				else if (camDir[count] == 3){
					checkLeft(j, i, tmpMap);
					if (myMap[i][j] == 2){
						checkRight(j, i, tmpMap);
					}
					else if (myMap[i][j] == 3){
						checkUp(j, i, tmpMap);
					}
					else if (myMap[i][j] == 4){
						checkDown(j, i, tmpMap);
						checkUp(j, i, tmpMap);
					}
					else if (myMap[i][j] == 5){
						checkUp(j, i, tmpMap);
						checkRight(j, i, tmpMap);
						checkDown(j, i, tmpMap);
					}
				}
				count ++;
			}
		}
	}
	int localMin = 0;
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			if (tmpMap[i][j] == 0){
				localMin ++;
			}
		}
	}
	if (localMin < ultMin){
		ultMin = localMin;
	}
}

void generate(int count, int camCount, vector<int> camDir){
	if (count == camCount){
		solve(camDir, camCount);
		return;
	}
	else{
		for (int i = 0; i < 4; ++i){
			camDir[count] = (camDir[count] + 1) % 4;
			generate(count + 1, camCount, camDir);
		}
	}
}

int main(){
	cin >> R >> C;
	int camCount = 0;
	vector<int> camDir(10);
	for (int i = 0; i < R; ++i){
		for (int j = 0; j < C; ++j){
			cin >> myMap[i][j];
			if (myMap[i][j] > 0 && myMap[i][j] <= 5){
				camCount ++;
			}
		}
	}
	//cout << "cam " << camCount << endl;
	generate(0, camCount, camDir);
	cout << ultMin << endl;
	return 0;
}

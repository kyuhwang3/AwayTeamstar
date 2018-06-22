#include <iostrem>

using namespace std;
int myMap[105][105];
int x, y, d, g;
/*
0 x+
1 y+
2 x-
3 y-
*/
void makeCurve(){
	int tmpMap[105][105];
	tmpMap[y][x] = 1;
	if (d == 0)
		tmpMap[y][x+1] = 1;
	else if (d == 1)
		tmpMap[y+1][x] = 1;
	else if (d == 2)
		tmpMap[y][x-1] = 1;
	else if (d == 3)
		tmpMap[y-1][x] = 1;
	return;
}
void countSquare(){
	return;
}
int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> x >> y >> d >> g;
		makeCurve();
	}
	countSquare();
	return 0;
}
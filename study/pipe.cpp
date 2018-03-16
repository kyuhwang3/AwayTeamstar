#include <iostream>
#include <queue>
using namespace std;

int N;
int X, Y;
int map[20][20];
int dfsMap[105][105];
int vis[200];
int visited[200];
int count;
void bfs(int src)
{
	queue<int> q;
	q.push(src);
	vis[src]=1;
    int atLeast;
	while(!q.empty()){
        atLeast = 0;
		int cur=q.front();
		//printf("%d ",cur);
		//cout << cur << " ";
        count ++;
		q.pop();
		for(int i=0; i < N * N; ++i){
			if(dfsMap[cur][i] && dfsMap[i][cur] && vis[i]!=1){
				vis[i] = 1;
                atLeast = 1;
				q.push(i);
			}
		}
        if (atLeast == 1)
            visited[cur] = 1;
	}
}

void Input_Data(void){
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			if(str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}
/*
void solve(int x, int y) {
    int i;
    visit[x][y] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (map[v][i] == 1 && !visit[i])
        {
            solve(i);
        }
    }
}
*/
int calcIndex(int i, int j)
{
    return i * N + j;
}


void buildMap(){
    int node, left, right, top, bottom;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            node = calcIndex(i, j);
            if (j - 1 >= 0)
                left = calcIndex(i, j - 1);
            else
                left = -1;
            if (j + 1 < N)
                right = calcIndex(i, j + 1);
            else
                right = -1;
            if (i - 1 >= 0)
                top = calcIndex(i - 1, j);
            else 
                top = -1;
            if (i + 1 < N)
                bottom = calcIndex(i + 1, j);
            else
                bottom = -1;
						if (map[i][j] == 0){
								count ++;
						}
            else if (map[i][j] == 1){
                //left right
                if (left > -1) dfsMap[node][left] = 1;
                if (right > -1) dfsMap[node][right] = 1;
            }
            else if (map[i][j]  == 2){
                //top bottom
                if (top > -1) dfsMap[node][top] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
            }
            else if (map[i][j]  == 3){
                //right bottom
                if (right > -1) dfsMap[node][right] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
            }
            else if (map[i][j]  == 4){
                //left bottom ㄱ
                if (left > -1) dfsMap[node][left] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
            }
            else if (map[i][j]  == 5){
                //top left 
                if (top > -1) dfsMap[node][top] = 1;
                if (left > -1) dfsMap[node][left] = 1;
            }
            else if (map[i][j]  == 6){
                //top right ㄴ
                if (top > -1) dfsMap[node][top] = 1;
                if (right > -1) dfsMap[node][right] = 1;
            }
            else if (map[i][j]  == 7){
                //top bottom right ㅏ
                if (top > -1) dfsMap[node][top] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
                if (right > -1) dfsMap[node][right] = 1;
            }
            else if (map[i][j]  == 8){
                //right left bottom ㅜ
                if (left > -1) dfsMap[node][left] = 1;
                if (right > -1) dfsMap[node][right] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
            }
            else if (map[i][j]  == 9){
                //left top bottom ㅓ
                if (left > -1) dfsMap[node][left] = 1;
                if (top > -1) dfsMap[node][top] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
            }
            else if (map[i][j]  == 10){
                //top right left ㅗ
                if (left > -1) dfsMap[node][left] = 1;
                if (right > -1) dfsMap[node][right] = 1;
                if (top > -1) dfsMap[node][top] = 1;
            }
            else if (map[i][j]  == 11){
                //all +
                if (left > -1) dfsMap[node][left] = 1;
                if (right > -1) dfsMap[node][right] = 1;
                if (top > -1) dfsMap[node][top] = 1;
                if (bottom > -1) dfsMap[node][bottom] = 1;
            }
        }
    }
}

int main(){
	int ans = -1;
    count = 0;
	Input_Data();
    buildMap();
    int start = calcIndex(Y, X);
	bfs(start);


    cout << (N * N) - count << endl;

    /*
    for (int i = 0; i < N*N; i ++){
        for (int j = 0; j < N*N; j++){
            cout << dfsMap[i][j];
        }
        cout << endl;
    }
    */	
	return 0;
}

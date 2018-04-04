#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A, B, N, M;
int mymap[105][105];
struct robot{
	int x;
	int y;
	char dir;
};

struct step{
	int which;
	char to;
	int rep;
};

vector<robot> robots;
vector<step> moves;

void printerRobot(int from, int to){
	cout << "Robot " << from << " crashes into robot " << to << endl;
}
void printerWall(int from){
	cout << "Robot " << from << " crashes into the wall" << endl;
}

int performStep(int target, int rep){
	int x = robots[target - 1].x;
	int y = robots[target - 1].y;
	int dir = robots[target - 1].dir;
	if (dir == 1){
		for (int i = y - 1; i > y - 1 - rep; --i){
			if (i <= 0){
				printerWall(target);
				return -1;
			}
			else if (mymap[x][i] != 0){
				printerRobot(target, mymap[x][i]);
				return -1;
			}
		}
		mymap[x][y] = 0;
		mymap[x][y - rep] = target;
	}
	else if (dir == 3){
		for (int i = y + 1; i < rep + y + 1; ++i){
			if (i > B){
				printerWall(target);
				return -1;
			}
			else if (mymap[x][i] != 0){
				printerRobot(target, mymap[x][i]);
				return -1;
			}
		}
		mymap[x][y] = 0;
		mymap[x][y + rep] = target;

	}
	else if (dir == 2){
		for (int i = x + 1; i < rep + x + 1; ++i){
			if (i > A){
				printerWall(target);
				return -1;
			}
			else if (mymap[i][y] != 0){
				printerRobot(target, mymap[i][y]);
				return -1;
			}
		}
		mymap[x][y] = 0;
		mymap[x + rep][y] = target;
	}
	else if (dir == 4){
		for (int i = x - 1; i > x - 1 - rep; --i){
			if (i <= 0){
				printerWall(target);
				return -1;
			}
			else if (mymap[i][y] != 0){
				printerRobot(target, mymap[i][y]);
				return -1;
			}
		}
		mymap[x][y] = 0;
		mymap[x - rep][y] = target;
	}
	else{
		cout << "something wrong" << endl;
	}
	return 1;
}

void solve(){
	for (int i = 0; i < M; ++i){
		int repe = moves[i].rep;
		int whichone = moves[i].which;
		if (moves[i].to == 'F'){
			int ret = performStep(whichone, repe);
			if (ret == -1){
				return;
			}
		}
		else if (moves[i].to == 'R'){
			for (int i = 0; i < repe; ++i){
				robots[whichone - 1].dir = (robots[whichone - 1].dir + 1) % 4;
			}	
		}
		else if (moves[i].to == 'L'){
			for (int i = 0; i < repe; ++i){
				robots[whichone - 1].dir = (robots[whichone - 1].dir + 3) % 4;
			}
		}
	}
    cout << "OK" << endl;
}

int main(){
	//ifstream cin("input.txt");
	cin >> A >> B;
	cin >> N >> M;
	robot tempRobot;
	char dir;
	for (int i = 1; i <= N; ++i){
		cin >> tempRobot.x >> tempRobot.y >> dir;
		if (dir == 'N')
			tempRobot.dir = 1;
		else if (dir == 'E')
			tempRobot.dir = 2;
		else if (dir == 'S')
			tempRobot.dir = 3;
		else if (dir == 'W')
			tempRobot.dir = 4;
		robots.push_back(tempRobot);
		mymap[tempRobot.y][tempRobot.x] = i;
	}
	step tempMove;
	char which;
	for (int i = 1; i <= M; ++i){
		cin >> tempMove.which >> tempMove.to >> tempMove.rep;
		moves.push_back(tempMove);
	}

	solve();
	return 0;
}
















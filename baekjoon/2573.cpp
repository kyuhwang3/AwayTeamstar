#include <iostream>
using namespace std;
int x, y;
int myMap[305][305];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void printer(){
    for (int i = 0; i < y; ++i){
        for (int j = 0; j < x; ++j){
            cout << myMap[i][j];
        }
        cout << '\n';
    }
    return ;
}

void doProcess(int startY, int startX){
    for (int i = 0; i < 4; ++i){
        if (startY + dy[i] >= 0 && startY + dy[i] < y){
            if (startX + dx[i] >= 0 && startX + dx[i] < x){
                if (myMap[startY + dy[i]][startX + dx[i]]){
                    myMap[startY + dy[i]][startX + dx[i]] --;
                    if (!myMap[startY + dy[i]][startX + dx[i]]){
                        
                    }
                }
            }
        }
    }
}

int main(){
    cin >> y >> x;
    int startX, startY;
    for (int i = 0; i < y; ++i){
        for (int j = 0; j < x; ++j){
            cin >> myMap[i][j];
            if (myMap[i][j] != 0){
                startY = i;
                startX = j;
            } 
        }
    }
    doProcess(startY, startX);
    return 0;
}
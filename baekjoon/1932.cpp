#include <iostream>
using namespace std;
int N;
int tri[505][505];
int memo[505][505];
void printer(){
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << memo[i][j] << " ";
        }
        cout << '\n';
    }
}
/*
int calcMe(int i, int j){
    if (i == N - 1){
        if (j <= i)
            return max(tri[i][j], tri[i][j + 1]);
        else
            return tri[i][j];
    }
    else{
        if (j <= i)
            return max(tri[i][j] + calcMe(i + 1, j), tri[i][j] + calcMe(i + 1, j + 1));
        else
            return tri[i][j] + calcMe(i + 1, j);
    }
}
*/
int calcMe(int i, int j){
    memo[0][0] = tri[0][0];
    for (int i = 1; i < N; ++i){
        for (int j = 0; j < i + 1; ++j){
            if (j - 1 >= 0){
                memo[i][j] = max(memo[i-1][j] + tri[i][j], memo[i-1][j-1] + tri[i][j]);
            }
            else{
                memo[i][j] = memo[i-1][j] + tri[i][j];
            }
        }
    }
}
int main(){
    cin >> N;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < i + 1; ++j){
            cin >> tri[i][j];
        }
    }
    //printer();
    calcMe(0, 0);
    printer();
    //cout << tri[0][0] << endl;
    int myMax = 0;
    
    for (int i = 0; i < N; ++i){
        if (memo[N-1][i] > myMax)
            myMax = memo[N-1][i];
    }
    cout << myMax << '\n';
    
    return 0;
}
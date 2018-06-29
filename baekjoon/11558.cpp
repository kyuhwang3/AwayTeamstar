#include <iostream>
#include <vector>
#include <map>
using namespace std;
int T;
int N;
vector<int> answer;
void doProcess(vector<int> info){
    int check = 0;
    for (int i = 0; i < N; ++i){
        if (info[i] == N - 1){
            check = 1;
            break;
        }
    }
    if (check != 1){
        answer.push_back(0);
    }
    else{
        int count = 1;
        int index = info[0];
        while (true){
            if (index == N - 1){
                break;
            }
            else {
                index = info[index];
            }
            count ++;
            if (count > N){
                count = 0;
                break;
            }
        }
        answer.push_back(count);
    }
}

int main(){
    int tmp;
    cin >> T;
    for (int i = 0; i < T; ++i){
        vector<int> peopleInfo;
        cin >> N;
        for (int j = 0; j < N; ++j){
            cin >> tmp;
            peopleInfo.push_back(tmp - 1);
        }
        //cout << "qwe" << '\n';
        doProcess(peopleInfo);
    }
    for (int i = 0; i < T; ++i){
        cout << answer[i] << '\n';
    }
}
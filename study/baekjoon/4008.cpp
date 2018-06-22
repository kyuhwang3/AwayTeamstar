#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int T;
int N;
int mySigns[4];
vector<int> numbers;
vector<int> signs;
int minNumber = 100000000;
int maxNumber = -100000000;
//int minNumber = -; int maxNumber;
int number;

void solve(int k, int num){
    if (k == N){
        if (num > maxNumber){
            maxNumber = num;
        }
        if (num < minNumber){
            minNumber = num;
        }
        return;
    }
    else{
        for (int i = 0; i < 4; ++i){
            //cout << numbers[k] << endl;
            if (mySigns[i] > 0){
                mySigns[i] --;
                if (i == 0){
                    solve(k + 1, num + numbers[k]);
                }
                else if (i == 1){
                    solve(k + 1, num - numbers[k]);
                }
                else if (i == 2){
                    solve(k + 1, num * numbers[k]);
                }
                else if (i == 3){
                    solve(k + 1, num / numbers[k]);
                }
                mySigns[i] ++;
            }
        }
    }
}

void numPrinter(){
    //cout << numbers.size() << endl;
    
    for (int i = 0; i < numbers.size(); ++i){
        cout << numbers[i];
    }
    cout << endl;

}

int main(){
    //int tmp;
	//ifstream cin("input.txt");
	cin >> T;
    for (int i = 0; i < T; ++i){
        maxNumber = -100000000; minNumber = 100000000;
        number = 0;
        cin >> N;
        numbers.clear();
        for (int j = 0; j < 4; ++j){
            cin >> mySigns[j];
        }
        for (int k = 0; k < N; ++k){
            int tmp;
            cin >> tmp; //cout << tmp;
            numbers.push_back(tmp);
            //cout << numbers[k] << endl;
        }
        //cout << numbers.size() << endl;
        //signPrinter();
        //numPrinter();
        solve(1, numbers[0]);
        cout << "#" << i + 1 << " " << maxNumber - minNumber << endl;
    }
}

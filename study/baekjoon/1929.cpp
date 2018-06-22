#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> numbers;
bool isPrime(int num){
    if (num == 1)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;
    else{
        for (int i = 3; i < num / 2; ++i){
            if (num % i == 0)
                return false;
        }
        return true;
    }
}
int main(){
    cin >> N >> M;
    for (int i = N; i <= M; ++i){
        numbers.push_back(i);
    }
    for (int i = 0; i < numbers.size(); ++i){
        if (numbers[i] == -1)
            continue;
        if (isPrime(numbers[i])){
            for (int j = i; j <= M; j = j + j){
                numbers[j] = -1;
            }
        }
    }
    for (int i = 0; i < numbers.size(); ++i){
        if (numbers[i] != -1)
            cout << numbers[i] << endl;
    }
}
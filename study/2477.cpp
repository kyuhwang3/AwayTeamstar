#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
//N = number of reception
//M = number of repair shop
//K = numbre of customers
//A = customer's reception number
//B = customer's repair shop number

int T, N, M, K, A, B, curTime;
vector<int> reception; int receptionDesk[12];
vector<int> repair; int repairDesk[12];
priority_queue<int, vector<int>, greater<int> > customer;
priority_queue<int, vector<int>, greater<int> > receptionPool;
priority_queue<int, vector<int>, greater<int> > repairPool;


void solve(){
    //customer arrvied
    
    
    //place customer in the reception Desk
    vector<int> curCustomers;
    while (!customer.empty() && customer.top() == curTime){
        curCustomers.push_back(customer.top());
        customer.pop();
    }
    
    
    for (int i = 0; i < curCustomers.size(); ++i){
        int checker = -1;
        for (int j = 0; j < N; ++j){
            if (receptionDesk[j] == -1){
                checker = 1;
                receptionDesk[j] = curCustomers[i];
                break;
            }
        }
        if (checker == -1){
            // i부터
            for (int k = i; k < curCustomers.size(); ++k){
                receptionPool.push(curCustomers[k]);
            }
            break;
        }
    }

    for (int i = 0; i < receptionDesk.size(); ++i){
        if (receptionDesk[i] == 0){
            repairPool.push(
        }
    }
}

int main(){
    ifstream cin("input.txt");
    cin >> T;
    int tmp;
    for (int i = 0; i < T; ++i){
        curTime = 0;
        reception.clear(); repair.clear();
        cin >> N >> M >> K >> A >> B;
        for (int j = 0; j < N; ++j){
            cin >> tmp;
            reception.push_back(tmp);
        }
        for (int j = 0; j < M; ++j){
            cin >> tmp;
            repair.push_back(tmp);
        }
        for (int j = 0; j < K; ++j){
            cin >> tmp;
            customer.push(tmp);
        }
        for (int i = 1; i <= N; ++i)
            receptionDesk[i] = -1;
        for (int i = 1; i <= M; ++i)
            repairDesk[i] = -1;
        solve();
    }
    return 0;
}
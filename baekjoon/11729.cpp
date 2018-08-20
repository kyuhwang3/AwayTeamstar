#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<pair<int, int> > moves;

void doProcess(int n, int from, int spare, int to){
    if (n == 1){
        //cout << from << " " << to << '\n';
        moves.push_back(make_pair(from , to));
        //cout << "done" << endl;
        return;
    }
    else{
        //cout << "1========== " << n << endl;
        doProcess(n - 1, from, to, spare);
        //cout << "2========== " << n << endl;
        //cout << from << " " << to << '\n';
        moves.push_back(make_pair(from , to));
        doProcess(n - 1, spare, from, to); 
        //cout << "3========== " << n << endl;
    }
}

int main(){
    int n;
    cin >> n;
    doProcess(n, 1, 2, 3);
    cout << moves.size() << '\n';
    for (int i = 0; i < moves.size(); ++i){
        cout << moves[i].first << " " << moves[i].second << '\n';
    }
}
#include<iostream>
#define MAX_SIZE 13
using namespace std;
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;
 
void permu(int start, int index){
        if (index == 6){
                for (int i = 0; i < 6; ++i){
                        cout << combi[i] << ' ';
                }
                cout << '\n';
                return;
        }
        for (int i = start; i < k; ++i){
                combi[index] = lotto[i];
                permu(i + 1, index + 1);
        }
}

void combo(int start, int index){
        if (index == 6){
                
        }
}

int main() {
        while(cin >> k && k) {           
                for(int i=0; i<k; i++) {
                        cin >> lotto[i];
                }
                permu(0, 0);
                cout << '\n';
        }
        return 0;
}
 
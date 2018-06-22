#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N;
struct st{
	int X, ID;
};
st A[50010];
set<int> uniqueID;
bool compare (st i, st j){
	return i.X < j.X;
}

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A[i].X >> A[i].ID;
		uniqueID.insert(A[i].ID);
	}
}

int solve()
{

}

int main(){
	int ans = -1;

	InputData();		
	for (int i = 0; i < uniqueID.size(); ++i)
	{
		cout << uniqueID[i] << endl;
	}
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int N, T;
int main(){
    cin >> N;
    string school;
    int alch;
    vector<string> answer;
    for (int i = 0; i < N; ++i){
        vector<pair<string, int> > schoolInfo;
        cin >> T;
        string maxName;
        int maxCount = -1;
        for (int j = 0; j < T; ++j){
            cin >> school >> alch;
            //cout << school << ":" << alch << '\n';
            schoolInfo.push_back(make_pair(school, alch));
        }
        for (int a = 0; a < schoolInfo.size(); ++a){
            if (schoolInfo[a].second > maxCount){
                maxCount = schoolInfo[a].second;
                maxName = schoolInfo[a].first;
            }
            //cout << schoolInfo[a].first << ": " << schoolInfo[a].second << '\n';
        }
        answer.push_back(maxName);
    }
    for (int i = 0; i < N; ++i){
        cout << answer[i] << '\n';
    }
    return 0;
}
#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(void) {
	map<string, int> mymap;

	mymap["123"] = 1;
	mymap["123"] = 2;
	cout << mymap["123"] << endl;
	string s;
	getline(cin, s);
	string temp;
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ' ') {
			temp[j++] = s[i];
		}
		else {
			j = 0;
			if (mymap[temp]) {
				mymap[temp] = mymap[temp] + 1;
			}
			else {
				mymap[temp] = 1;
			}
		}
	}
	return 0;
}
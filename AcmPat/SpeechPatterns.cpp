//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <map>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int ans = 0;
	map<string, int> res;
	string tmp;
	while (cin >> tmp) {
		string str;
		for (int i = 0; i < tmp.size(); i++) {
			if (isalnum(tmp[i]) != 0) {
				if (isalpha(tmp[i]) != 0)
					str += tolower(tmp[i]);
				else
					str += tmp[i];
			}
		}
		if (str.size() != 0) 
			res[str]++;
	}
	map<string, int>::iterator it = res.begin(), it2;
	for (it; it != res.end(); it++) {
		if (it->second > ans) {
			ans = it->second;
			it2 = it;
		}
		else if (it->second == ans && it->first < it2->first)
			it2 = it;
	}
	cout << it2->first << " " << it2->second;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include<string>
using namespace std;

string LookandSay(string num, int cnt, int globalCnt) {
	string tmp = "";
	if (cnt == globalCnt) { return num; }
	for (int i = 0; i < num.size();) {
		int j = i;
		for (j; j < num.size() && num[i] == num[j]; j++) {}
		tmp += num[i] + to_string(j - i);
		i = j;
	}
	return LookandSay(tmp, ++cnt, globalCnt);
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int globalCnt;
	string num;
	cin >> num >> globalCnt;
	cout << LookandSay(num, 1, globalCnt) << endl;
	return 0;
}
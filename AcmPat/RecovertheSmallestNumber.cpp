//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int num;
	cin >> num;
	string str[10001], res;
	for (int i = 0; i < num; i++) { cin >> str[i]; }
	sort(str, str + num, Cmp);
	for (int i = 0; i < num; i++)
		res += str[i];
	while(res.size()!=0 && res[0] == '0')
		res.erase(res.begin());
	if (res.size() == 0) { cout << 0; }
	cout << res;
	return 0;
}
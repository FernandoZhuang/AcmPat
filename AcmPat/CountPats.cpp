#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int pCnt = 0, tCnt = 0, res = 0;
	string str1;
	cin >> str1;
	for (int i = 0; i < str1.size(); i++) 
		if (str1[i] == 'T')
			tCnt++;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] == 'P')
			pCnt++;
		else if (str1[i] == 'T')
			tCnt--;
		else
			res = (res + pCnt * tCnt) % 1000000007;
	}
	cout << res;
	return 0;
}
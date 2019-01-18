//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string s1, s2, s3;
	map<char, int> record;
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++) { record[s1[i]] = 0; }
	for (int i = 0; i < s2.size(); i++) { record[s2[i]] = 1; }
	for (int i = 0; i < s1.size(); i++) 
		if (record[s1[i]] == 0)
			s3 += s1[i];
	cout << s3;
	return 0;
}
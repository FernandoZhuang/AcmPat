//Correct among some dataset
//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//
//int res;
//map<char, vector<int> > record;
//string str;
//
//void Cal(int start, int end) {
//	for (int i = start, j = end; i <= j && str[i] == str[j]; i++, j--)
//		res = (i == j ? (i - start + end - j + 1) : (i - start + end - j + 2)) > res ? (i == j ? (i - start + end - j + 1) : (i - start + end - j + 2)) : res;
//}
//
//int main() {
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
//	getline(cin, str);
//	for (int i = 0; i < str.size(); i++) 
//		record[str[i]].push_back(i); 
//	for (int i = 0; i < str.size(); i++) {
//		int flag;
//		if (record[str[i]].size() == 1) { continue; }
//		for (int j = 0; j < record[str[i]].size(); j++) 
//			if (record[str[i]][j] == i) { flag = j; }
//		for (int j = flag + 1; j < record[str[i]].size(); j++)
//			Cal(i, record[str[i]][j]);
//	}
//	cout << res;
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
using namespace std;

int dp[1005][1005], ans;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
		dp[i][i] = 1;
	for (int i = 0; i < s.size() - 1; i++) 
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = 1;
			ans = 2;
		}
	for (int i = 3; i <= s.size(); i++) {
		for (int j = 0; j + i - 1 < s.size(); j++) {
			if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2] == 1) {
				dp[j][j + i - 1] = 1;
				ans = i;
			}
		}
	}
	cout << ans;
	return 0;
}
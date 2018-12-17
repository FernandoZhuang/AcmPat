//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int verticleCnt, lineCnt, queryCnt, queryNum, tmp1;
	cin >> verticleCnt >> lineCnt;
	vector<vector <int> > graph(lineCnt, vector<int>(2));
	for (int i = 0; i < lineCnt; i++) { cin >> graph[i][0] >> graph[i][1]; }
	cin >> queryCnt;
	for (int i = 0; i < queryCnt; i++) {
		cin >> queryNum;
		set<int> query;//
		for (int j = 0; j < queryNum; j++) {
			cin >> tmp1;
			query.insert(tmp1);
		}
		int m = 0;
		for (m; m < lineCnt; m++) {
			if (query.find(graph[m][0]) == query.end() && query.find(graph[m][1]) == query.end()) {
				cout << "No" << endl;
				break;
			}
		}
		if (m == lineCnt) { cout << "Yes" << endl; }
	}
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void CalSimilarity(set<int>& A, set<int>& B) {
	vector<int> Nc,Nt;
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<vector<int>>(Nc, Nc.begin()));
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<vector<int>>(Nt, Nt.begin()));
	cout << fixed << setprecision(1) << (((double)Nc.size() / Nt.size())*100) << "%" << endl;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int cnt, tmp1, tmp2, testCnt;
	cin >> cnt;
	vector<set<int> > data(cnt);

	for (int i = 0; i < cnt; i++) {
		cin >> tmp1;
		for (int j = 0; j < tmp1; j++) {
			cin >> tmp2;
			data[i].insert(tmp2);
		}
	}
	cin >> testCnt;
	for (int i = 0; i < testCnt; i++) {
		cin >> tmp1 >> tmp2;
		CalSimilarity(data[tmp1 - 1], data[tmp2 - 1]);
	}
	return 0;
}
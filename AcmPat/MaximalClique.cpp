//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nv, ne, queryLineNum ,tmp1, tmp2, m, m1;
	cin >> nv >> ne;
	vector<vector <int> > node(nv + 1, vector<int> (201, 0));
	for (int i = 1; i <= ne; i++) {
		cin >> tmp1 >> tmp2;
		node[tmp2][tmp1] = node[tmp1][tmp2] = 1;
	}
	cin >> queryLineNum;
	for (int i = 0; i < queryLineNum; i++) {
		cin >> tmp1;
		vector<int> query(tmp1);
		vector<int> flag(201, 0);
		for (int j = 0; j < tmp1; j++) { 
			cin >> query[j]; 
			flag[query[j]] = 1;
		}
		for (int j = 0; j < tmp1; j++) {
			for (m = j + 1; m < tmp1 && node[query[j]][query[m]] == 1; m++) {}
			if (m < tmp1) { 
				cout << "Not a Clique" << endl; 
				break;
			}
		}
		if (m == tmp1) {
			for (int j = 1; j <= nv; j++) {
				if (flag[j] == 1) { continue; }
				for (m1 = 0; m1 < query.size() && node[j][query[m1]] == 1; m1++) {}
				if (m1 == query.size()) { 
					cout << "Not Maximal" << endl; 
					break;
				}
			}
			if (m1 < query.size()) { cout << "Yes" << endl; }
		}
	}
	return 0;
}
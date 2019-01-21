//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <set>
using namespace std;

int record[1001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	set<int> valid;
	int N, M, tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		record[tmp]++;
		valid.insert(tmp);
	}
	for (set<int>::iterator it = valid.begin(); it != valid.end(); it++) {
		if (record[*it] >= 2 && (*it + *it == M)) {
			cout << *it << " " << *it;
			return 0;
		}
		if (record[M - *it] >= 1 && *it != (M - *it)) {
			cout << *it << " " << M - *it;
			return 0;
		}
	}
	cout << "No Solution";
	return 0;
}
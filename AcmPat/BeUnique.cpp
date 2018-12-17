//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int tmp1, record[100000];
	memset(record, 0, 100000 * sizeof(int));
	cin >> tmp1;
	vector<int> store(tmp1);
	for (int i = 0; i < tmp1; i++) {
		cin >> store[i];
		record[store[i]]++;
	}
	for (int i = 0; i < tmp1; i++) {
		if (record[store[i]] == 1) {
			cout << store[i] << endl;
			return 0;
		}
	}
	cout << "None" << endl;
	return 0;
}
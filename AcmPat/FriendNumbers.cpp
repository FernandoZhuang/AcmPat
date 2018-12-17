//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;
//#define LOCAL

int DoSum(int num) {
	int res = 0;
	while (num) {
		res += num % 10;
		num = num / 10;
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m, tmp;
	set<int> num;

	int cnt;
	cin >> cnt;
	for (i = 0; i < cnt; i++) {
		cin >> tmp;
		num.insert(DoSum(tmp));
	}

	cout << num.size() << endl;
	set<int>::iterator it = num.begin();
	cout << *it++;
	for (it; it != num.end(); it++) { cout << " " << *it; }
	return 0;
}
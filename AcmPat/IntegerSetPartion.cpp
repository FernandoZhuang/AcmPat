#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m, tmp;
	long cnt, sum = 0;
	cin >> cnt;

	vector<long> num(cnt, 0);
	for (i = 0; i < cnt; i++) { cin >> num[i]; }
	sort(num.begin(), num.end());

	printf("%d", (cnt % 2) == 0 ? 0 : 1);
	for (i = cnt / 2; i < cnt; i++) { sum += num[i]; }
	for (i = 0; i < cnt / 2; i++) { sum -= num[i]; }
	printf(" %ld", sum);
	return 0;
}
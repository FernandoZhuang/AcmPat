//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <algorithm>
using namespace std;

int coupon[100001], value[100001];

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nc, np, n = 0, m = 0;
	long res = 0;
	cin >> nc;
	for (int i = 0; i < nc; i++) { cin >> coupon[i]; }
	cin >> np;
	for (int i = 0; i < np; i++) { cin >> value[i]; }
	sort(coupon, coupon + nc);
	sort(value, value + np);
	while (n < nc && m < np && coupon[nc - n - 1] >= 0 && value[np - m - 1] >= 0)
		res += coupon[nc - (n++) - 1] * value[np - (m++) - 1];
	n = nc, m = np;
	while (n >= 0 && m >= 0 && coupon[nc - n] <= 0 && value[np - m] <= 0)
		res += coupon[nc - (n--)] * value[np - (m--)];
	cout << res;
	return 0;
}
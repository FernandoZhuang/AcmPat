//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <algorithm>
using namespace std;
//HACK:negative num
int coupon[100001], value[100001];

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nc, np;
	long res = 0, tmp = 0;
	cin >> nc;
	for (int i = 0; i < nc; i++) { cin >> coupon[i]; }
	//HACK:nc np
	cin >> np;
	for (int i = 0; i < np; i++) { cin >> value[i]; }
	sort(coupon, coupon + nc);
	sort(value, value + np);
	for (int i = 0; i < nc; i++) { 
		tmp += coupon[i] * value[i]; 
		if (tmp > res) { res = tmp; }
		else { tmp = res; }
	}
	cout << res;
	return 0;
}
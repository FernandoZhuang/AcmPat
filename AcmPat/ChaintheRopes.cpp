//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int num;
	double res;
	cin >> num;
	vector<int> data(num);
	for (int i = 0; i < num; i++) { cin >> data[i]; }
	sort(data.begin(), data.end());
	res = data[0] * pow((1.0 / 2), num - 1);
	for (int i = 1; i < num; i++) { res += data[i] * pow((1.0/ 2), num - i); }
	cout << floor(res);
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string owner, eva;
	cin >> owner >> eva;
	int record[200] = { 0 };
	int res = 0;
	for (int i = 0; i < owner.size(); i++) { record[owner[i] - '0']++; }
	for(int i = 0; i < eva.size(); i++) {
		if (record[eva[i] - '0'] > 0) { record[eva[i] - '0']--; }
		else { res++; }
	}
	if (res) { cout << "No " << res; }
	else { cout << "Yes " << owner.size() - eva.size(); }
	return 0;
}
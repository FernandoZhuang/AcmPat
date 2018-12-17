//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//#define LOCAL
vector<int> res;
int N, B;
bool PalindromicJudge() {
	for (int i = 0; i < res.size() / 2; i++) {
		if (res[i] != res[res.size() - 1 - i]) { return false; }
	}
	return true;
}
void ToBase(int num) {
	if (!num) { return; }
	else {
		res.push_back(num%B);
		ToBase(num / B);
	}
}
int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m;
	cin >> N >> B;
	if (!N) { cout << "Yes" << endl << 0; }
	else {
		ToBase(N);
		if (PalindromicJudge())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cout << res[res.size() - 1];
		for (i = res.size() - 2; i >= 0; i--) { cout << " " << res[i]; }
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

#define LOCAL
vector<int> inNum, postNum, resNum;
void Do(int start, int end, int mid, int resOrder) {
	if (start > end) { return; }//
	int tmp = start;
	while (tmp < end && inNum[tmp] != postNum[mid]) { tmp++; }
	resNum[resOrder] = postNum[mid];
	Do(start, tmp - 1, mid - 1 - (end - tmp), resOrder * 2 + 1);
	Do(tmp + 1, end, mid - 1, resOrder * 2 + 2);
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m;
	int num, cnt = 0;

	cin >> num;
	inNum.resize(num);
	postNum.resize(num);
	resNum.resize(5000, -1);//error size
	for (i = 0; i < num; i++) { cin >> postNum[i]; }
	for (i = 0; i < num; i++) { cin >> inNum[i]; }
	Do(0, num - 1, num-1, 0);
	for (i = 0; i < resNum.size(); i++) {
		if (resNum[i] != -1) { 
			if (cnt != 0) { cout << " "; }
			cout << resNum[i]; 
			cnt++;
		}
		if (cnt == num) { break; }
	}
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

//#define LOCAL
int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif 
	int i, num, sum, tmpSum;
	int start, tmpStart, end;

	cin >> num;
	vector<int> number(num, 0);
	for (i = 0; i < num; i++) { cin >> number[i]; }
	sum = tmpSum = start = tmpStart = 0;
	for (i = 0; i < num; i++) {//
		tmpSum += number[i];
		if(tmpSum<0){
			tmpStart = i + 1;//
			tmpSum = 0;
		}
		else if (tmpSum > sum) {
			sum = tmpSum;
			start = tmpStart;//optimization
			end = i;
		}
	}
	if (sum == 0) { end = number.size() - 1; }
	cout << sum << " " << number[start] << " " << number[end] << endl;
	return 0;
}
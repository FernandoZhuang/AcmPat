//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> Shuffle(vector<string> tmp, int order[]) {
	vector<string> res(54, "");
	for (int i = 0; i < 54; i++) 
		res[order[i] - 1] = tmp[i];
	return res;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int times, order[54];
	vector<string> res(54, "");
	char flag[4] = { 'S','H','C','D'};
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			res[13 * i + j] += flag[i] + to_string(j + 1); 
	res[52] = "J1";
	res[53] = "J2";
	cin >> times;
	for (int i = 0; i < 54; i++)
		cin >> order[i]; 
	for (int i = 0; i < times; i++) 
		res = Shuffle(res, order);
	cout << res[0];
	for (int i = 1; i < 54; i++) 
		cout << " " << res[i]; 
	return 0;
}
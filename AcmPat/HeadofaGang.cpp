#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct node {
	string name, fa;
	int num, wt = 0;
};
map<string, node> person;
string maxName;
int maxTime, treeSize, gangCnt;

string Root(string tmp, int flag) {
	if (flag == 0) 
		maxTime = person[tmp].wt, treeSize = 1, maxName = tmp;
	while (person[tmp].fa != tmp) { 
		if (person[tmp].wt >= maxTime) {
			maxTime = person[tmp].wt;
			maxName = tmp;
		}
		treeSize++;
		tmp = person[tmp].fa;
	}
	return tmp;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int cnt, thresh, time, tmpTime, tmpSize;
	map<string, int> res;
	string tmp1, tmp2, tmp3, tmp4, tmpName;
	cin >> cnt >> thresh;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp1 >> tmp2 >> time;
		person[tmp1].wt += time;  
		person[tmp2].wt += time;
		if (person[tmp1].fa == "") { person[tmp1].fa = tmp1; }
		if (person[tmp2].fa == "") { person[tmp2].fa = tmp2; }

		tmp3 = Root(tmp1, 0);
		tmpTime = maxTime, tmpName = maxName, tmpSize = treeSize;
		tmp4 = Root(tmp2, 0);

		if (tmp3 != tmp4) {
			if (tmpTime > maxTime) {
				res[tmpName] += res[maxName];
				res[maxName] = 0;
				person[tmp4].fa = tmp3;
			}
			else
			{
				res[maxName] += tmpSize;
				res[tmpName] = 0;
				person[tmp3].fa = tmp4;
			}
		}
	}
	return 0;
}
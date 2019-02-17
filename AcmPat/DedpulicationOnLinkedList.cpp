//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

struct nodes {
	int addr, val, next;
};

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int addrStart, nodesCnt, cnt = 0;
	cin >> addrStart >> nodesCnt;
	vector<nodes> lists(nodesCnt), res, remv;
	map<int,int> seq;
	unordered_set<int> uniqueNum;
	for (int i = 0; i < nodesCnt; i++) {
		cin >> lists[i].addr >> lists[i].val >> lists[i].next;
		seq[lists[i].addr] = i;
	}
	int cur = seq[addrStart];
	while (cnt < nodesCnt) {
		if (!uniqueNum.size() || uniqueNum.find(abs(lists[cur].val)) == uniqueNum.end()) {
			uniqueNum.insert(abs(lists[cur].val));
			res.push_back(lists[cur]);
		}
		else
			remv.push_back(lists[cur]);
		if (lists[cur].next == -1)
			break;
		cur = seq[lists[cur].next], cnt++;
	}
	for (int i = 0; i < res.size() - 1; i++)
		printf("%05d %d %05d\n", res[i].addr, res[i].val, res[i + 1].addr);
	printf("%05d %d -1\n", res[res.size() - 1].addr, res[res.size() - 1].val);
	for (int i = 0; i < remv.size() - 1; i++)
		printf("%05d %d %05d\n", remv[i].addr, remv[i].val, remv[i + 1].addr);
	if (remv.size())
		printf("%05d %d -1\n", remv[remv.size() - 1].addr, remv[remv.size() - 1].val);
	return 0;
}
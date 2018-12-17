#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int maxLevel, maxCnt;
vector<vector<int> > tree;
void Dfs(int root, int level) {
	if (level > maxLevel) {
		maxLevel = level;
		maxCnt = 1;//
	}
	else if (level == maxLevel) { maxCnt++; }
	if (tree[root].empty()) { return; }
	for (int i = 0; i < tree[root].size(); i++) { Dfs(tree[root][i], level + 1); }
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodeCnt, tmp1, root;
	double price, inc;
	cin >> nodeCnt >> price >> inc;
	tree.resize(nodeCnt);
	for (int i = 0; i < nodeCnt; i++) {
		cin >> tmp1;
		if (tmp1 != -1) { tree[tmp1].push_back(i); }
		else { root = i; }
	}
	Dfs(root, 0);
	for (int i = 0; i < maxLevel; i++) { price = price * (1 + inc / 100); }
	cout << fixed << setprecision(2) << price << " " << maxCnt;
	return 0;
}
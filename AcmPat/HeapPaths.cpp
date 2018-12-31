//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int gFlag;
vector<int> tree, res;

int PrintPath(int root, int pre) {
	if (root >= tree.size()) { return 0; }
	if (root != pre && ((tree[root] < tree[pre] ? 1 : -1) != gFlag)) { gFlag = 0; }
	res.push_back(tree[root]);
	if (PrintPath(root * 2 + 2, root) + PrintPath(root * 2 + 1, root) == 0) {
		cout << res[0];
		for (int i = 1; i < res.size(); i++) { cout << " " << res[i]; }
		cout << endl;
	}
	res.pop_back();
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodeCnt;
	cin >> nodeCnt;
	tree.resize(nodeCnt);
	for (int i = 0; i < nodeCnt; i++) { cin >> tree[i]; }
	gFlag = tree[0] > tree[1] ? 1 : -1;
	PrintPath(0, 0);
	if (gFlag == 1) { cout << "Max Heap" << endl; }
	else if (gFlag == -1) { cout << "Min Heap" << endl; }
	else if (gFlag == 0) { cout << "Not Heap" << endl; }
	return 0;
}
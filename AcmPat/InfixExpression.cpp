#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct tree {
	string value;
	int rNo, lNo;
	tree* r, *l;
}node[21];

void In(tree* root, int flag) {
	if (root == NULL) { return; }
	if (flag == 1 && (root->lNo != -1 || root->rNo != -1)) {
		cout << "(";
		flag = 2;
	}
	In(root->l, 1);
	cout << root->value;
	In(root->r, 1);
	if (flag == 2) { cout << ")"; }
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodeCnt, root;
	cin >> nodeCnt;
	vector<int> flag(nodeCnt + 1, 0);
	for (int i = 1; i <= nodeCnt; i++)
		cin >> node[i].value >> node[i].lNo >> node[i].rNo;
	for (int i = 1; i <= nodeCnt; i++) {
		if (node[i].lNo == -1) { node[i].l = NULL; }
		else {
			node[i].l = &node[node[i].lNo];
			flag[node[i].lNo] = 1;
		}
		if (node[i].rNo == -1) { node[i].r = NULL; }
		else {
			node[i].r = &node[node[i].rNo];
			flag[node[i].rNo] = 1;
		}
	}
	for (int i = 1; i <= nodeCnt; i++)
		if (flag[i] == 0) { root = i; }
	In(&node[root], 0);
	return 0;
}
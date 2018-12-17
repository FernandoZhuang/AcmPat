//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
using namespace std;

struct node {
	int value, level;
	node *left, *right;
}tree[1001];
int cnt, maxLevel, recordLevel[1001];

node* create(int value, int level) {
	recordLevel[level]++;
	if (level > maxLevel) { maxLevel = level; }
	tree[cnt].value = value;
	tree[cnt].left = tree[cnt].right = NULL;
	return &tree[cnt++];
}

node* build(int value, int level, node* myNode) {
	if (myNode == NULL) { return create(value, level); }
	if (value <= myNode->value) { myNode->left = build(value, level+1, myNode->left); }
	else if (value > myNode->value) { myNode->right = build(value, level + 1, myNode->right); }
	return myNode;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodeCnt, tmp1;
	node* head = NULL;
	cin >> nodeCnt;
	for (int i = 0; i < nodeCnt; i++) {
		cin >> tmp1;
		head = build(tmp1, 0, head);
	}
	cout << recordLevel[maxLevel] << " + " << recordLevel[maxLevel - 1] << " = " << recordLevel[maxLevel] + recordLevel[maxLevel - 1];
	return 0;
}
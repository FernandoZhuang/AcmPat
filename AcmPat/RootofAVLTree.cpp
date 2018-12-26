#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <algorithm>
using namespace std;

struct tree {
	int value;
	tree *left, *right;
};

tree* RotateRight(tree* node) {
	tree *tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	return tmp;
}

tree* RotateLeft(tree* node) {
	tree *tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	return tmp;
}

tree* RotateLeftRight(tree* node) {
	node->left = RotateLeft(node->left);
	return RotateRight(node);
}

tree* RotateRightLeft(tree* node) {
	node->right = RotateRight(node->right);
	return RotateLeft(node);
}

int GetHeight(tree* node) {
	if (node == NULL) { return 0; }
	return max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

tree* InsertNode(tree* node, int value) {
	if (node == NULL) {
		node = new tree();
		node->value = value;
		node->left = node->right = NULL;
		return node;
	}
	if (value < node->value) {
		node->left = InsertNode(node->left, value);
		if (GetHeight(node->left) - GetHeight(node->right) >= 2) {
			node = value < node->left->value ? RotateRight(node) : RotateLeftRight(node);
		}
	}
	else {
		node->right = InsertNode(node->right, value);
		if (GetHeight(node->right) - GetHeight(node->left) >= 2) {
			node = value > node->right->value ? RotateLeft(node) : RotateRightLeft(node);
		}
	}
	return node;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	tree *root = NULL;
	int nodeCnt, value;
	cin >> nodeCnt;
	for (int i = 0; i < nodeCnt; i++) {
		cin >> value;
		root = InsertNode(root, value);
	}
	cout << root->value << endl;
	return 0;
}
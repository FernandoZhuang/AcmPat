#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int maxLevel;
vector<vector<int> > preRecord(31), levelNode(31);
vector<int> pre(31), in(31), post(31);

void Pre(int root, int start, int end, int level) {
	if (level > maxLevel) { maxLevel = level; }
	levelNode[level].push_back(post[root]);
	if (end < start) { return; }
	int i = end;
	while (i > start && in[i] != post[root]) { i--; }
	if (i != start) {
		Pre(root - 1 - (end - i), start, i - 1, level + 1); 
		preRecord[post[root]].push_back(post[root - 1 - (end - i)]);
	}
	if (i != end) { 
		Pre(root - 1, i + 1, end, level + 1); 
		preRecord[post[root]].push_back(post[root - 1]);
	}
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodeCnt;
	vector<int> res;
	cin >> nodeCnt;
	for (int i = 0; i < nodeCnt; i++) { cin >> in[i]; }
	for (int i = 0; i < nodeCnt; i++) { cin >> post[i]; }
	Pre(nodeCnt - 1, 0, nodeCnt - 1, 0);
	for (int i = 0; i <= maxLevel; i++) {
		if (i % 2 != 0) { for (int j = 0; j < levelNode[i].size(); j++) { res.push_back(levelNode[i][j]); } }
		else { for (int j = levelNode[i].size() - 1; j >= 0; j--) { res.push_back(levelNode[i][j]); } }
	}
	cout << res[0];
	for (int i = 1; i < res.size(); i++) { cout << " " << res[i]; }
	return 0;
}
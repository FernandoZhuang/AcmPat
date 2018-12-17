#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int weight;
	vector<int> child;
}tree[101];
int weight, S, cnt;
vector<int> res1(101), record;
vector<vector<int> > res2(101);

void Dfs(int root, int depth) {
	res1[depth] = tree[root].weight;
	if (weight + tree[root].weight > S) { return; }
	else if (weight + tree[root].weight == S && tree[root].child.empty()) {
		res2[cnt].insert(res2[cnt].begin(), res1.begin(), res1.begin() + depth + 1);
		record.push_back(cnt);
		cnt++;
	}
	else {
		if (tree[root].child.empty()) { return; }
		weight += tree[root].weight;
		for (int i = 0; i < tree[root].child.size(); i++) { Dfs(tree[root].child[i], depth + 1); }
		weight -= tree[root].weight;
	}
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int N, M, tmp1, tmp2, tmp3;
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) { cin >> tree[i].weight; }
	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		for (int j = 0; j < tmp2; j++) {
			cin >> tmp3;
			tree[tmp1].child.push_back(tmp3);
		}
	}
	Dfs(0, 0);
	for (int i = 0; i < cnt; i++) { for (int j = 0; j < cnt - 1; j++) { if (res2[j] < res2[j + 1]) { swap(res2[j], res2[j + 1]); } } }
	for (int i = 0; i < cnt; i++) { for (int j = 0; j < res2[i].size(); j++) { printf("%d%c", res2[i][j], j != res2[i].size() - 1 ? ' ' : '\n'); } }
	return 0;
}
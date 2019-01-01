//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector < vector <int> > tree(101);
vector<int> res(101);

int LevelTraversal(int level) {
	if (q.size() == 0) { return level; }
	int tmp1 = q.size();
	for (int i = 0; i < tmp1; i++) {
		int tmp2 = q.front();
		q.pop();
		if (tree[tmp2].size() == 0) 
			res[level]++; 
		else 
			for (int j = 0; j < tree[tmp2].size(); j++) { q.push(tree[tmp2][j]); }
	}
	 return LevelTraversal(++level);
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int n, m, tmp[3];
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp[0] >> tmp[1];
		for (int j = 0; j < tmp[1]; j++) { 
			cin >> tmp[2]; 
			tree[tmp[0]].push_back(tmp[2]);
		}
	}
	q.push(1);
	tmp[0]= LevelTraversal(0);
	for (int i = 0; i < tmp[0]; i++) { printf("%d%s", res[i], i == tmp[0] - 1 ? "\n" : " "); }
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <algorithm>
using namespace std;

int cnt, num[102];
struct node {
	int data, l, r, index, level;
}info[102];

void Dfs(int root,int index, int level) {
	if (info[root].l == -1 && info[root].r == -1) { info[root] = { num[cnt++],info[root].l,info[root].r,index,level }; }
	else {
		if (info[root].l != -1) { Dfs(info[root].l, index * 2 + 1, level+1); }
		info[root] = { num[cnt++],info[root].l,info[root].r,index,level };
		if (info[root].r != -1) { Dfs(info[root].r, index * 2 + 2, level+1); }
	}
}

bool Cmp(node a, node b) {
	if (a.level != b.level) { return a.level < b.level; }
	else { return a.index < b.index; }
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m, tmp1;
	cin >> tmp1;
	for (i = 0; i < tmp1; i++) { cin >> info[i].l >> info[i].r; }
	for (i = 0; i < tmp1; i++) { cin >> num[i]; }
	sort(num, num+tmp1);
	Dfs(0, 0, 0);
	sort(info, info + tmp1, Cmp);
	cout << info[0].data;
	for (i = 1; i < tmp1; i++) { cout << " " << info[i].data; }
	return 0;
}
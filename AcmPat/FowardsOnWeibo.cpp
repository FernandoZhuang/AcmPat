//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <vector>
#include <iostream>
using namespace std;

int L, res;
vector<bool> flag;
vector<vector<int> > follower(1001);

void Ans(int level, int node, int root) {
	if (level > L)
		return;
	if (flag[node] == false && level >= 1)
		res++;
	flag[node] = true;
	for (int i = 0; i < follower[node].size(); i++) 
		if(follower[node][i] != root)
			Ans(level + 1, follower[node][i], node);
	return;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N, tmp[3], query[1001];
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &tmp[1]);
		for (int j = 0; j < tmp[1]; j++) {
			scanf("%d", &tmp[2]);
			follower[tmp[2]].push_back(i);
		}
	}
	scanf("%d", &tmp[1]);
	for (int i = 0; i < tmp[1]; i++) {
		scanf("%d", &query[i]);
		res = 0;
		flag = vector<bool> (1001, false);
		Ans(0, query[i], query[i]);
		printf("%d\n", res);
	}
	return 0;
}
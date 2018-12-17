#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodes, edges, queryLine, tmp1, tmp2, m;
	vector<vector<int> > map(1001);
	vector<int> res;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++) {
		cin >> tmp1 >> tmp2;
		map[tmp1].push_back(tmp2);
	}
	cin >> queryLine;
	for (int i = 0; i < queryLine; i++) {
		vector<int> queryNode, queryHash(nodes + 1);
		for (int j = 1; j <= nodes; j++) {
			cin >> tmp1;
			queryNode.push_back(tmp1);
			queryHash[tmp1] = j;
		}
		for (int j = 0; j < nodes; j++) {
			for (m = 0; m < map[queryNode[j]].size() && queryHash[map[queryNode[j]][m]] > queryHash[queryNode[j]]; m++) {}
			if (m < map[queryNode[j]].size()) {
				res.push_back(i);
				break; 
			}
		}
	}
	cout << res[0];
	for (int i = 1; i < res.size(); i++) { cout << " " << res[i]; }
	return 0;
}
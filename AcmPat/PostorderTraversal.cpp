#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, in, res;

void Post(int root, int start, int end) {
	if (end < start) { return; }
	int tmp = start;
	while (tmp < end && pre[root] != in[tmp]) { tmp++; }
	Post(root + 1, start, tmp - 1);
	Post(root + 1 + tmp - start, tmp + 1, end);
	res.push_back(root);
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int nodes;
	cin >> nodes;
	pre.resize(nodes);
	in.resize(nodes);
	for (int i = 0; i < nodes; i++) { cin >> pre[i]; }
	for (int i = 0; i < nodes; i++) { cin >> in[i]; }
	Post(0, 0, nodes - 1);
	cout << pre[res[0]];
	return 0;
}
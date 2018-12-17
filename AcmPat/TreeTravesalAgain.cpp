//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> pre, in, post, value;

void PostRecursive(int root, int start, int end) {
	if (start > end) { return; }//==?
	int i = start;
	while (i < end&&in[i] != pre[root]) { i++; }//==?
	PostRecursive(root + 1, start, i - 1);
	PostRecursive(root + 1 + i - start, i + 1, end);
	post.push_back(pre[root]);
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int key = 0;
	string buf;
	stack<int> s;
	int nodeCnt, tmp1;
	cin >> nodeCnt;
	for (int i = 0; i < 2 * nodeCnt; i++) {
		cin >> buf;
		if (buf.size() == 4) {
			cin >> tmp1;
			value.push_back(tmp1);
			pre.push_back(key);
			s.push(key++);
		}
		else {
			in.push_back(s.top());
			s.pop();
		}
	}
	PostRecursive(0, 0, nodeCnt - 1);
	cout << value[post[0]];
	for (int i = 1; i < post.size(); i++) { cout << " " << value[post[i]]; }
	return 0;
}
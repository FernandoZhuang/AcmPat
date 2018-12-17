//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cctype>
using namespace std;

vector<int> inSequence;
int root, node[10][2], nodeLink[10];

void InOrder(int root) {
	if (node[root][0] == -1 && node[root][1] == -1) { 
		inSequence.push_back(root);
		return; 
	}
	else {
		if (node[root][0] != -1) { InOrder(node[root][0]); }
		inSequence.push_back(root);
		if (node[root][1] != -1) { InOrder(node[root][1]); }
	}
	return;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string str;
	int nodeNum;
	cin >> nodeNum;
	getchar();
	memset(nodeLink, -1, 10*sizeof(int));
	for (int i = 0; i < nodeNum; i++) {	
		getline(cin, str);
		node[i][1] = isdigit(str[0]) ? (str[0] - '0') : -1;//
		node[i][0] = isdigit(str[2]) ? (str[2] - '0') : -1;//
		if (node[i][0] != -1) { nodeLink[node[i][0]] = i; }
		if (node[i][1] != -1) { nodeLink[node[i][1]] = i; }
	}
	for (int i = 0; i < nodeNum; i++) { if (nodeLink[i] == -1) { root = i; } }

	queue<int> q;
	int rootPrint = 1;
	q.push(root);
	while (!q.empty()) {
		int index = q.front();
		if (rootPrint) { 
			cout << index; 
			rootPrint = 0;
		}
		else{ cout << " " << index; }
		q.pop();
		if (node[index][0] != -1) { q.push(node[index][0]); }
		if (node[index][1] != -1) { q.push(node[index][1]); }
	}
	cout << endl;
	InOrder(root);
	cout << inSequence[0];
	for (int i = 1; i < nodeNum; i++) { cout << " " << inSequence[i]; }
	return 0;
}
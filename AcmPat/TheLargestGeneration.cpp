//#define _CRT_SECURE_NO_WARNINGS	
//#define LOCAL
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//DFS
vector<vector<int> > node(101);
vector<int> level, book;

void DoDfs(int index, int levelNum) {
	int i, k, m;
	for (i = 0; i < node[index].size(); i++) {
		level[node[index][i]] = levelNum + 1;
		book[levelNum + 1]++;
		DoDfs(node[index][i], levelNum + 1);
	}
	return;
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m, tmp1, tmp2, tmp3;
	int cntFam, cntPar, levelNum, max = 0;

	cin >> cntFam >> cntPar;
	level.resize(cntFam + 1, 0);
	book.resize(cntFam + 1, 0);
	for (i = 0; i < cntPar; i++) {
		cin >> tmp1 >> tmp2;
		for (k = 0; k < tmp2; k++) {
			cin >> tmp3;
			node[tmp1].push_back(tmp3);
		}
	}
	book[1] = level[1] = 1;
	DoDfs(1, 1);
	for (i = 1; i < cntFam + 1; i++) {
		if (book[i] > max) {
			max = book[i];
			levelNum = i;
		}
	}
	cout << max << " " << levelNum;
	return 0;
}

// BFS
/*int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int i, k, m, tmp1, tmp2, tmp3;
	int cntFam, cntPar, index, levelNum, max = 0;
	queue<int> num;

	cin >> cntFam >> cntPar;
	vector<vector<int> > node(cntFam + 1);
	vector<int> level(cntFam+1);
	vector<int> book(cntFam + 1, 0);
	for (i = 0; i < cntPar; i++) {
		cin >> tmp1 >> tmp2;
		for(k=0;k<tmp2;k++){
			cin >> tmp3;
			node[tmp1].push_back(tmp3);
		}
	}
	level[1] = 1;
	num.push(1);

	while (!num.empty()) {
		index = num.front();
		num.pop();
		book[level[index]]++;
		for (i = 0; i < node[index].size(); i++) {
			level[node[index][i]] = level[index] + 1;
			num.push(node[index][i]);
		}
	}
	for (i = 0; i < cntFam + 1; i++) {
		if (book[i] > max) {
			max = book[i];
			levelNum = i;
		}
	}
	cout << max << " " << levelNum;
	return 0;
}*/
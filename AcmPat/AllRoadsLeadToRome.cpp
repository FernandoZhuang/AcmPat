#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#define MAX 999999999
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	string start, tmp[3];
	map<string, int> seq;
	int N, K, tmpCost;
	cin >> N >> K >> start;
	vector<string> reSeq(N), res;
	vector<bool> flag(N, false);
	vector<int> min(N, MAX), happy(N, 0), maxHappy(N, 0), cnt(N, 0), root(N);
	vector<vector<int> > cost(N, vector<int>(N, MAX));
		
	for (int i = 0; i < N; i++) {
		cost[i][i] = 0;
		root[i] = i;
	}
	seq[start] = 0, min[seq[start]] = 0, reSeq[0] = start;
	for (int i = 1; i <= N - 1; i++) {
		cin >> tmp[1] >> happy[i];
		seq[tmp[1]] = i;
		reSeq[i] = tmp[1];
	}
	for (int i = 0; i < K; i++) {
		cin >> tmp[1] >> tmp[2] >> tmpCost;
		cost[seq[tmp[1]]][seq[tmp[2]]] = tmpCost;
		cost[seq[tmp[2]]][seq[tmp[1]]] = tmpCost;
	}

	for (int i = 0; i < N; i++) {
		int minNum = MAX, next;
		for (int j = 0; j < N; j++)
			if (min[j] < minNum && !flag[j]) {
				minNum = min[j];
				next = j;
			}
		min[next] = minNum;
		flag[next] = true;

		for (int j = 0; j < N; j++) {
			if (flag[j] == true)
				continue;
			if (min[next] + cost[next][j] < min[j]) {
				cnt[j] = 1;
				min[j] = min[next] + cost[next][j];
				maxHappy[j] = maxHappy[next] + happy[j];
				root[j] = next;
			}
			else if (min[next] + cost[next][j] == min[j]) {
				cnt[j]++;
				if (maxHappy[next] + happy[j] > maxHappy[j]) {
					maxHappy[j] = maxHappy[next] + happy[j];
					root[j] = next;
				}
				else if (maxHappy[next] + happy[j] == maxHappy[j] && (maxHappy[next] + happy[j])*1.0 / i > (maxHappy[j] * 1.0 / i))
					root[j] = next;
			}
		}
	}

	int i = seq["ROM"];
	res.push_back("ROM");
	while (root[i] != i) {
		res.push_back(reSeq[root[i]]);
		i = root[i];
	}
	cout << cnt[seq["ROM"]] << " " << min[seq["ROM"]] << " " << maxHappy[seq["ROM"]] << " " << maxHappy[seq["ROM"]] / (res.size() - 1) << endl;
	for (int i = res.size() - 1; i > 0; i--)
		cout << res[i] << "->";
	cout << res[0];
	return 0;
}
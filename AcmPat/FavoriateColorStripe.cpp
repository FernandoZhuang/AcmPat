//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#define UNK 999
#include <iostream>
#include <cstring>
using namespace std;

int colorHash[201], stripe[10001], res[10001];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N, M, L, tmp, flag = 0;
	cin >> N >> M;
	memset(colorHash, UNK, 201 * sizeof(int));
	for (int i = 1; i <= M; i++) { 
		cin >> tmp;
		colorHash[tmp] = i;
	}
	cin >> L;
	for (int i = 0; i < L; i++) { 
		cin >> stripe[i]; 
		res[i] = colorHash[stripe[i]] == UNK ? 0 : 1;
		if (colorHash[stripe[i]] == UNK)
			continue; 
		/*if (colorHash[stripe[i]] >= colorHash[stripe[flag]] && i != 0) {
			res[i] = res[flag] + 1;
			flag = i;
		}
		else {
			int j = i - 1;
			while (j >= 0 && colorHash[stripe[j]] > colorHash[stripe[i]]) { j--; }
			if (j < 0) { continue; }
			res[i] = res[j] + 1;
			if (res[i] > res[flag])
				flag = i;
		}*/
		for (int j = 0; j < i; j++)
			if (colorHash[stripe[i]] >= colorHash[stripe[j]])
				res[i] = res[i] > (res[j] + 1) ? res[i] : (res[j] + 1);
		flag = res[i] > res[flag] ? i : flag;
	}
	cout << res[flag];
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ton;
vector<float> value;

bool Cmp(int A, int B) {
	return ((value[A] * 1.0) / ton[A]) > (value[B] * 1.0) / ton[B];
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	vector<int> seq;
	int N, M, tmp, tonExist = 0;
	float tmp2, valueExist = 0.0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		ton.push_back(tmp);
		seq.push_back(i);
	}
	for (int i = 0; i < N; i++) {
		scanf("%f", &tmp2);
		value.push_back(tmp2);
	}
	sort(seq.begin(), seq.end(), Cmp);
	for (int i = 0; i < seq.size(); i++) {
		if (tonExist + ton[seq[i]] >= M) {
			printf("%.2f", (valueExist + ((M - tonExist) * 1.0 / ton[seq[i]])*value[seq[i]]));
			return 0;
		}
		else {
			tonExist += ton[seq[i]];
			valueExist += value[seq[i]];
		}
	}
	printf("%.2f", valueExist);
	return 0;
}
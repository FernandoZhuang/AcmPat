//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct  info {
	char id[9];
	int v, t;
}person[100001];
vector<int> sage, noble, fool, rest;

bool Cmp1(int n, int m) {
	info A = person[n], B = person[m];
	if (A.v + A.t != B.v + B.t) 
		return A.v + A.t > B.v + B.t;
	else {
		if (A.v != B.v)
			return A.v > B.v;
		else {
			string tmp1 = A.id, tmp2 = B.id;
			return  tmp1 < tmp2;
		}
	}
}
		
void Ans(vector<int> A) {
	sort(A.begin(), A.end(), Cmp1);
	for (int i = 0; i < A.size(); i++) 
		printf("%s %d %d\n", person[A[i]].id, person[A[i]].v, person[A[i]].t); 
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int N, L, H, cnt = 0;
	scanf("%d %d %d", &N, &L, &H);
	for (int i = 0; i < N; i++) { 
		scanf("%s %d %d", person[i].id, &person[i].v, &person[i].t);
		if (person[i].v >= L && person[i].t >= L) {
			cnt++;
			if (person[i].v >= H && person[i].t >= H)
				sage.push_back(i);
			else if (person[i].v >= H && person[i].t < H)
				noble.push_back(i);
			else if (person[i].v < H && person[i].t < H && person[i].v >= person[i].t)
				fool.push_back(i);
			else
				rest.push_back(i);
		}
	}
	printf("%d\n", cnt);
	Ans(sage), Ans(noble), Ans(fool), Ans(rest);
	return 0;
}
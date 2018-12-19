//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int N, M, S;
	map<string, int> flag;
	cin >> N >> M >> S;
	vector<string> fans(N+1);
	if (S > N) {
		cout << "Keep going..." << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) { 
		cin >> fans[i]; 
		flag[fans[i]] = 0;
	}
	for (int i = S; i <= N;) {
		if (flag[fans[i]] == 0) { 
			cout << fans[i] << endl; 
			flag[fans[i]] = 1;
			i += M;
		}
		else {
			for (int j = i; j <= N; j++) { 
				if (flag[fans[j]] == 0) { 
					cout << fans[j] << endl; 
					flag[fans[j]] = 1;
					i = j + M;
					break;
				} 
			}
		}
		
	}
	return 0;
}
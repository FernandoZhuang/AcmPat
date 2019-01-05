//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string data;
	cin >> data;
	int flag = (data.size() + 2) / 3 + (data.size() + 2) % 3;
	for (int i = 0; i < (data.size() + 2 - flag) / 2; i++) {
		if (i < (data.size() + 2 - flag) / 2 - 1 ) {
			cout << data[i];
			for (int j = 0; j < flag - 2; j++) { cout << " "; }
			cout << data[data.size() - i - 1];
		}
		else 
			for (int j = 0; j < flag; j++) { cout << data[i + j]; }
		cout << endl;
	}
	return 0;
}
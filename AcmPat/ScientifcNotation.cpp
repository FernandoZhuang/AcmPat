#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <string>
#include <iostream>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int posDot, posE, exp;
	string str1, tmp;
	cin >> str1;
	posE = str1.find('E'), posDot = str1.find('.');
	exp = stoi(tmp.assign(str1.begin() + posE + 2, str1.end()));
	if (str1[0] == '-')
		cout << "-";
	if (str1[posE+1] == '-') {
		cout << "0.";
		for (int i = 0; i < exp - 1; i++)
			cout << "0";
		for (int i = 1; i < posE; i++)
			if (str1[i] != '.')
				cout << str1[i];
	}
	else {
		for (int i = 1; i < posE && i <= exp + 2; i++)
			if (str1[i] != '.')
				cout << str1[i];
		for (int i = 0; i < exp - (posE - posDot - 1); i++)
			cout << "0";
		if (exp < posE - posDot - 1) {
			cout << ".";
			for (int i = 0; i < posE - posDot - 1 - exp; i++)
				cout << "0";
		}
	}
	return 0;
}
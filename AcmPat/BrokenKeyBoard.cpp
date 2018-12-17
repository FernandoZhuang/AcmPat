#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int data1[256], data2[256];

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string str1, str2, str1Data;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++){
		if (isalpha(str1[i]) && islower(str1[i])) { str1[i] = toupper(str1[i]); }
		if (!data1[str1[i]]) {
			data1[str1[i]] = 1;
			str1Data.push_back(str1[i]);
		}
	}
	for (int i = 0; i < str2.size(); i++) { 
		if (isalpha(str2[i]) && islower(str2[i])) { str2[i] = toupper(str2[i]); }
		data2[str2[i]] = 1; 
	}
	for (int i = 0; i < str1Data.size(); i++) 
		if (!data2[str1Data[i]] && isalnum(str1Data[i])) {
			if (isdigit(str1Data[i])) { cout << str1Data[i]; }
			else { cout << str1Data[i]; }
		}
	return 0;
}
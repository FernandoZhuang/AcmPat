//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	string buf;
	int j = 0, flag = 0, res[10];
	char data[20];
	cin >> data;
	buf += data;
	memset(res, 0, 10 * sizeof(int));
	memset(data, '\0', 20 * sizeof(char));
	for (int i = buf.size()-1; i >= 0; i--) { 
		res[buf[i] - '0']++; 
		data[i] = ((buf[i] - '0') * 2 + flag >= 10 ? (buf[i] - '0') * 2 + flag - 10 : (buf[i] - '0') * 2 + flag) + '0';
		flag = (buf[i] - '0') * 2 + flag >= 10 ? 1 : 0;
		res[data[i] - '0']--;
	}
	if (flag == 0)
		for (j = 0; j < 10 && res[j] == 0; j++) {}
	printf("%s\n", j == 10 ? "Yes" : "No");
	if(flag == 1)
		printf("1%s", data);
	else
		printf("%s", data);
	return 0;
}
//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <vector>
using namespace std;

struct student {
	char name[11], id[11];
	int grade;
};

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	int stuNum, interval1, interval2, flag = 0;
	cin >> stuNum;
	vector<student> stu(stuNum);
	vector<int> record(101, -1);
	for (int i = 0; i < stuNum; i++) { 
		cin >> stu[i].name >> stu[i].id >> stu[i].grade; 
		record[stu[i].grade] = i;
	}
	cin >> interval1 >> interval2;
	for (int i = interval2; i >= interval1; i--) {
		if (record[i] != -1) { 
			cout << stu[record[i]].name << " " << stu[record[i]].id << endl; 
			flag = 1;
		}
	}
	if (!flag) { cout << "NONE"; }
	return 0;
}
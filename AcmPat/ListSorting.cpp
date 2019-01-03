//#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int N, C;
struct student {
	int id, grade;
	string name;
}stu[100001];

bool Cmp(student A, student B) {
	if (C == 3 && A.grade != B.grade) 
		return A.grade < B.grade; 
	else if (C == 2 && A.name != B.name) 
		return A.name < B.name; 
	else { return A.id < B.id; }
}

int main() {
#ifdef LOCAL
	freopen("data.txt", "r", stdin);
#endif
	cin >> N >> C;
	for (int i = 0; i < N; i++) { cin >> stu[i].id >> stu[i].name >> stu[i].grade; }
	sort(stu, stu + N, Cmp);
	for (int i = 0; i < N; i++) { cout << setw(6) << setfill('0') << stu[i].id << " " << stu[i].name << " " << stu[i].grade << endl; }
	return 0;
}
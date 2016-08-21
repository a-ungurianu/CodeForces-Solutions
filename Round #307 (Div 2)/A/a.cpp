#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct Stud {
	int idx;
	int rat;
	bool operator<(const Stud& oth) const {
		return rat > oth.rat;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	int n;
	cin >> n;

	vector<Stud> students(n);

	for(int i = 0; i < n; ++i) {
		cin >> students[i].rat;
		students[i].idx = i;
	}

	sort(students.begin(), students.end());

	vector<int> standings(n);

	int place = 1;
	int last_rating = students[0].rat;
	standings[students[0].idx] = place;
	for(int i = 1; i < n; ++i) {
		if(students[i].rat != last_rating) {
			place = i + 1;
			last_rating = students[i].rat;
		}
		standings[students[i].idx] = place;
	}
	for(int s:standings) {
		cout << s << ' ';
	}
}
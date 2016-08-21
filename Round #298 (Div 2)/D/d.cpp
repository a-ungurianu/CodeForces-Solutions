#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<unsigned> hand_count[200002];

int main() {
	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	int n;
	cin >> n;

	int max_h = 0;

	for(int i = 1; i <= n; ++i) {
		int h;
		cin >> h;
		max_h = max(max_h,h);
		hand_count[h].push_back(i);
	}

	vector<unsigned> order;
	order.reserve(n);

	int j = 0;
	for(int i = 0; i < n; ++i) {
		while(hand_count[j].empty() && j >= 3) {
			j -= 3;
		}

		if(hand_count[j].empty()) {
			cout << "Impossible\n";
			return 0;
		}

		order.push_back(hand_count[j].back());
		hand_count[j].pop_back();
		++j;
	}

	cout << "Possible\n";
	for(unsigned stud:order) {
		cout << stud << ' ';
	}
	cout << '\n';
}
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	int n;
	cin >> n;

	vector<int> digits;

	while(n) {
		digits.push_back(n%10);
		n/=10;
	}

	reverse(digits.begin(), digits.end());

	bool done = false;

	vector<int> decomp;

	while(!done) {
		int next = 0;
		for(int &d:digits) {
			next*=10;
			if(d != 0) {
				d--;
				next += 1;
			}
		}
		if(next == 0) {
			done = true;
		}
		else {
			decomp.push_back(next);
		}
	}

	cout << decomp.size() << '\n';
	for(int nr:decomp) {
		cout << nr << ' ';
	}

	return 0;
}
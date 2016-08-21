#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// #ifndef ONLINE_JUDGE
	// ifstream cin("input");
	// #endif

	int n;
	cin >> n;

	vector<int> times(n);

	for(int &tm:times) {
		cin >> tm;
	}

	int dis_count = 0;
	int total_wait = 0;

	sort(times.begin(), times.end());

	for(int tm:times) {
		if(total_wait > tm) {
			dis_count++;
		}
		else {
			total_wait += tm;
		}
	}

	cout << n - dis_count << '\n';
}
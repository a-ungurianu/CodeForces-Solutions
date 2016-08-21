#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	// #ifndef ONLINE_JUDGE
	// ifstream cin("input");
	// #endif

	int n;

	cin >> n;

	vector<vector<int> > a(n,vector<int>(n));

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}

	vector<int> good_cars;

	for(int i = 0; i < n; ++i) {
		bool is_good = true;
		for(int j = 0; j < n; ++j) {
			if(a[i][j] == 1 || a[i][j] == 3) {
				is_good = false;
			}
		}
		if(is_good) {
			good_cars.push_back(i+1);
		}
	}

	cout << good_cars.size() << '\n';
	for(int i = 0; i < good_cars.size(); ++i) {
		cout << good_cars[i] << ' ';
	}
}
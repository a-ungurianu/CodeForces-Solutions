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
	vector<int> values(n);
	for(int& val:values) {
		cin >> val;
	}

	sort(begin(values),end(values));

	if(values.front() == 1) {
		cout << -1 << '\n';
	}
	else {
		cout << 1 << '\n';
	}
}
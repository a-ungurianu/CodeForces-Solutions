#include <iostream>
#include <fstream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	int n;
	cin >> n;

	unsigned sum = 0;

	for(int r = 0; r < n; ++r) {
		int xs,xf,ys,yf;
		cin >> xs >> ys >> xf >> yf;
		sum += (xf - xs + 1)*(yf - ys + 1);
	}

	cout << sum << '\n';

	return 0;
}
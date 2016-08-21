#include <iostream>
#include <fstream>

using namespace std;

struct Rect {
	int w,h;
	bool fitsIn(Rect b) {
		return (b.w >= w && b.h >= h) || (b.w >= h && b.h >= w);
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	Rect big, small1, small2;

	cin >> big.w >> big.h;
	cin >> small1.w >> small1.h;
	cin >> small2.w >> small2.h;

	Rect tw = big,th = big;
	tw.w -= small1.w;
	th.h -= small1.h;

	if(small2.fitsIn(tw) || small2.fitsIn(th)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}
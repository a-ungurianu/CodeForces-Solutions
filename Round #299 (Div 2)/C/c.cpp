#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;


int A,B,n;

int cost(int r, int l, int m) {
	return ceil((A*(r-l+1) + B*((r*(r-1))/2 - (l*(l-1))/2))*1.0f/m);
}

int main() {
	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	cin >> A >> B >> n;

	for(int i = 0; i < n; ++i) {
		int l,t,m;
		cin >> l >> t >> m;

		int upper_limit = ceil(((t - A)*1.0f)/B) + 1;
		if(upper_limit < l) {
			cout << "-1\n";
			continue;
		}

		int st = l-1, fn = upper_limit+2;

		int last_mid = -4;
		while(st <= fn) {
			int mid = (st+fn)/2;
			if(cost(mid,l,m) > t) {
				fn = mid-1;
			}
			else {
				last_mid = mid;
				st = mid+1;
			}
		}

		cout << last_mid << '\n';
	}	
}
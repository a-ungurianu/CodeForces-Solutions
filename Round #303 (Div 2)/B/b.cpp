#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	// #ifndef ONLINE_JUDGE
	// ifstream cin("input");
	// #endif

	string a,b;

	cin >> a >> b;

	int dist = 0;

	for(int i = 0; i < a.size(); ++i) {
		if(a[i] != b[i]) {
			dist++;
		}
	}

	if(dist % 2 == 1) {
		cout << "impossible\n";
	}
	else {
		int diff = 0;
		string res(a.size(),'0');
		for(int i = 0; i < a.size(); ++i) {
			if(a[i] != b[i]) {
				if(diff <= 0) {
					res[i] = b[i];
					diff++;
				}
				else {
					res[i] = a[i];
					diff--;
				}

			}
		}
		cout << res << '\n';
	}

}
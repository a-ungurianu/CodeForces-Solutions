#include <iostream>
#include <fstream>

using namespace std;

int main() {
	//ifstream cin("input");

	int n;
	cin >> n;
	if(n > 4) {
		cout << n << '\n';	
		if(n%2 == 0) {
			for(int i = 0; i < n/2; ++i) {
				cout << 2*i + 1 << ' ';
			}
		}
		else {
			for(int i = 0; i <= n/2; ++i) {
				cout << 2*i + 1 << ' ';
			}
		}

		for(int i = 0; i < n/2; ++i) {
			cout << 2*(i+1) << ' ';
		}
	}
	else if(n == 4) {
		cout << "4\n3 1 4 2\n";
	}
	else if(n == 3) {
		cout << "2\n1 3\n";
	}
	else {
		cout << "1\n1\n";
	}

}
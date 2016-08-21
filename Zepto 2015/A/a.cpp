#include <iostream>
using namespace std;

bool check(const string &s, int i, int k) {
	if(i + 4*k < s.size()) {
		return s[i] == '*' &&
			   s[i] == s[i+k] &&
			   s[i] == s[i+2*k] &&
			   s[i] == s[i+3*k] &&
			   s[i] == s[i+4*k];
	}
	return false;
}

int main() {
	string s;
	int n;
	cin >> n;
	cin >> s;

	for(int k = 1; k < s.size(); ++k) {
		for(int i = 0; i < s.size(); ++i) {
			if(check(s,i,k)) {
				cout << "yes\n";
				return 0;
			}
		}
	}

	cout << "no\n";
	return 0;
}
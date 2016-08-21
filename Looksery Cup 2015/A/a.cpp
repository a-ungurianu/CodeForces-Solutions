#include <iostream>
#include <fstream>

using namespace std;

char mat[55][55];

int main() {
	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	int n,m;
	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}
	}

	int count = 0;
	for(int i = 0; i < n-1; ++i) {
		for(int j = 0; j < m-1; ++j) {
			bool match[4] = {0};
			for(int ii = 0; ii < 2; ++ii) {
				for(int jj = 0; jj < 2; ++jj) {
					for(int c = 0; c < 4; ++c) {
						if(mat[i+ii][j+jj] == "face"[c]) {
							match[c] = true;
						}
					}
				}
			}
			bool res = true;
			for(int c = 0; c < 4; ++c) {
				res = res && match[c];
			}
			if(res) {
				count ++;
			}
		}
	}
	cout << count;
}
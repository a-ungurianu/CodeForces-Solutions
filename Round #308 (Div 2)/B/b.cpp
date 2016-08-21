#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
	#endif

	int n;
	cin >> n;

	unsigned long long pow10 = 10;
	int num_len = 1;

	unsigned long long total_count = 0;

	while(pow10 <= n) {
		total_count += (pow10 - pow10 / 10)*num_len;

		num_len ++;
		pow10 *= 10;
	}

	total_count += (n - pow10/10 + 1)*num_len;

	cout << total_count;
}
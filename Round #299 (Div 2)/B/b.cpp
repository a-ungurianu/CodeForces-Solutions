#include <fstream>
#include <iostream>

using namespace std;


int main() {
	long long n;
	cin >> n;

	long long aux = n;

	int dig_count = 0;
	while(n) {
		n/= 10;
		dig_count++;
	}

	int pos = 0;
	for(int i = 0; i <= dig_count; ++i) {
		pos |= (1 << i);
	}

	int bit_pos = 1;
	while(aux) {
		if(aux % 10 == 4) {
			pos -= bit_pos;
		}
		bit_pos <<= 1;
		aux/= 10;
	}

	cout << pos - 1 << '\n';
	
}
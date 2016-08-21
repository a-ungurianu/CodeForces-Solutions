#include <iostream>

using namespace std;

struct Candy {
	long long w,h;
};

long long max_w;

Candy c1,c2;

 
int main() {
	cin >> max_w >> c1.h >> c2.h >> c1.w >> c2.w;
	
	long long max_h = 0;

	for(int i = 0; i <= max_w; i+=c1.w) {
		long long l_happ = (i/c1.w)*c1.h;
		long long r_happ = ((max_w-i)/c2.w)*c2.h;
		cerr << l_happ+r_happ << '\n';
		max_h = max(l_happ+r_happ,max_h);
	}

 
	//cout << max_h << '\n';
}
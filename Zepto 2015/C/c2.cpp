#include <iostream>
#include <utility>


using namespace std;

int main() {
	long long c;
	pair<long long,long long> c1,c2;
	cin >> c >> c1.first >> c2.first >> c1.second >> c2.second;

	if(c1.first*1.0f/c1.second < c2.first*1.0f/c2.second) {
		swap(c1,c2);
	}

	long long max_w = max(c1.second,c2.second);

	long long best = 0;
		
	if(max_w < 1000) {
		for(int i = 0; i < 10000000 && i*c2.second <= c; i++) {
			long long cur_best = i*c2.first + (c-i*c2.second)/c1.second*c1.first;
			best = max(cur_best,best);
		}
	}
	else {
		if(c1.second < c2.second) {
			swap(c1,c2);
		}
		for(int i = 0; i <= c; i+=c1.second) {
			long long l_happ = (i/c1.second)*c1.first;
			long long r_happ = ((c-i)/c2.second)*c2.first;

			best = max(l_happ+r_happ,best);
		}
	}
	cout << best << '\n';

	return 0;
}
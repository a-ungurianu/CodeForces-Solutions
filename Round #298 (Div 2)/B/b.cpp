#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;


int v1,v2,dv,t;

bool can_reach(int cur_v, int target_v, int dv, int rem_t) {
	int rem_v = target_v - cur_v;
	return abs(rem_v) < dv*rem_t;
}

int main() {
	// #ifndef ONLINE_JUDGE
	// ifstream cin("input");
	// #endif

	cin >> v1 >> v2 >> t >> dv;

	if(dv == 0) {
		cout << v1*t << '\n';
		return 0;
	}

	if(v1 + dv*(t-1) == v2) {
		int total_dist = 0;
		for(int v = v1; v <= v2;  v+=dv) {
			total_dist += v;
		}
		cout << total_dist << '\n';
		return 0;
	}

	int current_v = v1;
	int time_used = 1;
	vector<int> speeds;
	speeds.push_back(current_v);
	while(can_reach(current_v,v2,dv,t-time_used)) {
		current_v += dv;
		time_used++;
		speeds.push_back(current_v);
	}
	speeds.pop_back();

	current_v = v2 + dv * (t-time_used);	

	speeds.push_back(current_v);

	while(current_v != v2) {
		current_v -= dv;
		speeds.push_back(current_v);
	}

	int total_dist = 0;
	for(int sp:speeds) {
		total_dist += sp;
	}

	cout << total_dist << '\n';

	return 0;
}
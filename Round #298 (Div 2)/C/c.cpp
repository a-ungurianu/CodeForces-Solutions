#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	int nd;
	long long s;

	cin >> nd >> s;
	vector<unsigned> dices(nd);
	
	int dice_sum = 0;

	s -= nd;

	for(unsigned &dice:dices) {
		cin >> dice;
		dice --;
		dice_sum += dice;
	}

	for(unsigned dice:dices) {
		int max_val = dice - s;
		cout << dice+1 << ' ' << s - max_val << ' '<< '\n';
	}

	return 0;

}
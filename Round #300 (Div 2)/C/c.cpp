#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Note {
	int d;
	int h;
};

int main() {
	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	int n,m;
	cin >> n >> m;

	vector<Note> notes(m);
	for(int i = 0; i < m; ++i) {
		cin >> notes[i].d >> notes[i].h;
	}

	int max_h = 0;

	// for(int i = 0; i < m; ++i) {
	// 	max_h = max(max_h,notes[i].h);
	// }

	max_h = max(max_h,notes[0].h + notes[0].d - 1);
	max_h = max(max_h,notes.back().h + n-notes.back().d);

	bool fucked_up = false;

	for(int i = 1; i < m; ++i) {
		if(abs(notes[i].h - notes[i-1].h) > notes[i].d - notes[i-1].d) {
			fucked_up = true;
			break;
		}

		int c_max_h = notes[i-1].h + ((notes[i].d - notes[i-1].d) + notes[i].h - notes[i-1].h)/2;
		max_h = max(max_h,c_max_h);

		// d1 = 0 d2 = n(i).d-n(i-1).d
		// 2*d =  n(i).d - n(i-1).d + n(i).h - n(i-1).h

	}
	if(fucked_up) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << max_h << '\n';
	}
}
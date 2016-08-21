#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

unsigned n,m;

unsigned map[2000][2000];

struct Cell {
	int l,c;
	Cell operator+(const Cell & other) const {
		return {l+other.l, c+other.c};
	}

};

const unsigned nDir = 4;
Cell dir[] = {{0,1},{1,0},{0,-1},{-1,0}};

bool inbounds(Cell c) {
	return 0 <= c.l && c.l < n && 0 <= c.c && c.c < m;
}

void fill(Cell c) {
	queue<Cell> Q;
	int minL=2003,maxL=0,minC=2003,maxC=0;
	
	if(map[c.l][c.c] != '*') return;

	for(Q.push(c); !Q.empty(); Q.pop()) {
		Cell here = Q.front();
		minL = min(minL,here.l);
		maxL = max(maxL,here.l);
		minC = min(minC,here.c);
		maxC = max(maxC,here.c);

		for(unsigned k = 0; k < 4; ++k) {
			Cell next = here + dir[k];
			if(inbounds(next)) {
				if(map[next.l][next.c] == '.') {
					Q.push(next);
				}
			}
		}
	}
}

int main() {
	ifstream cin("arthur.in");
	cin >> n >> m;



	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	int l,c;
	Point operator+(const Point &oth) const {
		Point p = *this;
		p.l += oth.l;
		p.c += oth.c;
		return p;
	}
};

bool inbounds(Point p, int n) {
	return 0 <= p.l && p.l < n && 0 <= p.c && p.c < n;
}

const Point delta[] = {{0,1},{0,-1},{1,0},{-1,0}};

int main() {
	#ifndef ONLINE_JUDGE
		ifstream cin("input");
		ofstream cout("output");
	#endif

	int n,k;

	cin >> n >> k;

	vector<vector<int>> map(n,vector<int>(n,0));

	bool impossible = false;
	int cnt = 0;
	Point last;
	for(int i = 0; i < n; ++i) {
		for(int j = (i%2 == 0)?0:1; j < n; j +=2) {
			if(cnt >= k) {
				break;
			}
			Point cur = {i,j};
			
			map[cur.l][cur.c] = 1;

			if(cnt < k-1) {
				for(int kk = 0; kk < 4; ++kk) {
					Point nig = cur + delta[kk];
					if(inbounds(nig,n) && map[nig.l][nig.c] == 0) {
						map[nig.l][nig.c] = -1;
					}
				}
			}
			else {
				last = cur;
			}
			cnt++;
		}
	}	

	if(cnt < k) {
		impossible = true;
	}

	if(impossible) {
		cout << "NO";
	}
	else {

		queue<Point> bfs;

		for(bfs.push(last);!bfs.empty(); bfs.pop()) {
			Point cur = bfs.front();

			for(int kk = 0; kk < 4; ++kk) {
				Point nig = cur + delta[kk];
				if(inbounds(nig,n) && map[nig.l][nig.c] == 0) {
					map[nig.l][nig.c] = 1;
					bfs.push(nig);
				}
			}
		}
		cout << "YES\n";
		for(auto line: map) {
			for(auto p: line) {
				if(p == 1) {
					cout << "L";
				}
				else {
					cout << "S";
				}
			}
			cout << '\n';
		}

	}
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lights;

unsigned max_lvl;

unsigned total_cost = 0;

int dfs(int node, int lvl) {
	if(lvl == max_lvl) return lights[node];

	int val1 = dfs(2*node,lvl+1);
	int val2 = dfs(2*node+1,lvl+1);

	auto mm = minmax(val1,val2);
	total_cost += mm.second - mm.first;
	
	return mm.second + lights[node];
}

int main() {
	cin >> max_lvl;
	lights.resize(1<<(max_lvl+1),0);
	for(int i = 2; i < lights.size(); ++i) {
		cin >> lights[i];
	}

	dfs(1,0);

	cout << total_cost << '\n';


	return 0;
}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Edge {
	int to;
	int cost;
	int id;
};

int main() {

	#ifndef ONLINE_JUDGE
	ifstream cin("input");
	#endif

	int no_nodes, no_edges;

	cin >> no_nodes >> no_edges;

	vector<vector<Edge>> edges(no_nodes);

	for(int i = 0; i < no_edges; ++i) {
		int a,b,c;
		cin >> a >> b >> c;
		edges[a-1].push_back({b-1,c,i});
	}

	int source;

	cin >> source;
	source--;

	queue<int> bfs;

	vector<int> dist(no_nodes,0);

	for(bfs.push(source); !bfs.empty(); bfs.pop()) {
		int nd = bfs.front();
		
	}
}
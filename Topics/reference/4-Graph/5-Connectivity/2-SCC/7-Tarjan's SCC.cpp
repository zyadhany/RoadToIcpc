#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/** Takes in an adjacency list and calculates the SCCs of the graph. */
class TarjanSolver {
  private:
	vector<vector<int>> rev_adj;
	vector<int> post;
	vector<int> comp;

	vector<bool> visited;
	int timer = 0;
	int id = 0;

	void fill_post(int at) {
		visited[at] = true;
		for (int n : rev_adj[at]) {
			if (!visited[n]) { fill_post(n); }
		}
		post[at] = timer++;
	}

	void find_comp(int at) {
		visited[at] = true;
		comp[at] = id;
		for (int n : adj[at]) {
			if (!visited[n]) { find_comp(n); }
		}
	}

  public:
	const vector<vector<int>> &adj;

	TarjanSolver(const vector<vector<int>> &adj)
	    : adj(adj), rev_adj(adj.size()), post(adj.size()), comp(adj.size()),
	      visited(adj.size()) {
		vector<int> nodes(adj.size());
		for (int n = 0; n < adj.size(); n++) {
			nodes[n] = n;
			for (int next : adj[n]) { rev_adj[next].push_back(n); }
		}

		for (int n = 0; n < adj.size(); n++) {
			if (!visited[n]) { fill_post(n); }
		}
		std::sort(nodes.begin(), nodes.end(),
		          [&](int n1, int n2) { return post[n1] > post[n2]; });

		visited.assign(adj.size(), false);
		for (int n : nodes) {
			if (!visited[n]) {
				find_comp(n);
				id++;
			}
		}
	}

	int comp_num() const { return id; }

	int get_comp(int n) const { return comp[n]; }
};

int main() {
	int planet_num;
	int tele_num;
	std::cin >> planet_num >> tele_num;
	vector<vector<int>> adj(planet_num);
	for (int t = 0; t < tele_num; t++) {
		int from, to;
		std::cin >> from >> to;
		adj[--from].push_back(--to);
	}

	TarjanSolver scc(adj);
	cout << scc.comp_num() << '\n';
	for (int p = 0; p < planet_num - 1; p++) { cout << scc.get_comp(p) + 1 << ' '; }
	cout << scc.get_comp(planet_num - 1) + 1 << endl;
}
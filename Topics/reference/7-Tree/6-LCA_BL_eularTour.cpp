/*
Let $\texttt{start}$ and $\texttt{end}$ be the time-in and time-out table
for the nodes in the tree.
They'll be filled up in the exact same way the Euler tour module does it.

The cool thing is that while we're filling up $\texttt{start}$ and $\texttt{end}$,
we can also calculate our binary jumping table in the exact same way
we did in the previous solution!
We can do this because in a DFS, we're guaranteed to have processed all of
a node's parents before the node itself, so all the tables of any node's
ancestors will have been filled when we reach the node.

Now, to actually calculate the LCA without the depths of the nodes,
we can use the fact that node $a$ is an ancestor of node $b$
if $\texttt{start}[a] \le \texttt{start}[b]$ and $\texttt{end}[b] \le \texttt{end}[a]$.
*/

#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Tree {
  private:
	const int root = 0;

	const vector<vector<int>> &adj;
	const int log2dist;
	vector<vector<int>> pow2ends;
	vector<int> start, end;
	int timer = 0;

	void process(int at, int prev) {
		pow2ends[at][0] = prev;
		for (int p = 1; p <= log2dist; p++) {
			int halfway = pow2ends[at][p - 1];
			if (halfway == -1) {
				pow2ends[at][p] = -1;
			} else {
				pow2ends[at][p] = pow2ends[halfway][p - 1];
			}
		}

		start[at] = timer++;
		for (int n : adj[at]) {
			if (n != prev) { process(n, at); }
		}
		end[at] = timer;
	}

  public:
	Tree(const vector<vector<int>> &adj)
	    : adj(adj), log2dist(std::ceil(std::log2(adj.size()))),
	      pow2ends(adj.size(), vector<int>(log2dist + 1)), start(adj.size()),
	      end(adj.size()) {
		process(root, -1);
	}

	bool is_ancestor(int n1, int n2) {
		return start[n1] <= start[n2] && end[n2] <= end[n1];
	}

	int lca(int n1, int n2) {
		if (is_ancestor(n1, n2)) { return n1; }
		if (is_ancestor(n2, n1)) { return n2; }
		for (int i = log2dist; i >= 0; i--) {
			if (pow2ends[n1][i] != -1 && !is_ancestor(pow2ends[n1][i], n2)) {
				n1 = pow2ends[n1][i];
			}
		}
		return pow2ends[n1][0];
	}
};

int main() {
	int employee_num;
	int query_num;
	std::cin >> employee_num >> query_num;
	vector<vector<int>> adj(employee_num);
	for (int e = 1; e < employee_num; e++) {
		int boss;
		std::cin >> boss;
		adj[--boss].push_back(e);
		adj[e].push_back(boss);
	}

	Tree tree(adj);
	for (int q = 0; q < query_num; q++) {
		int e1, e2;
		std::cin >> e1 >> e2;
		cout << tree.lca(--e1, --e2) + 1 << '\n';
	}
}

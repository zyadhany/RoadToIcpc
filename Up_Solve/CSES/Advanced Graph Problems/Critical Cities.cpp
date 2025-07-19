#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

template <typename T> class Tree {
  private:
	const int root = 0;
	const vector<int> &parents;
	const vector<T> &vals;
	const int log2dist;
	vector<vector<int>> pow2ends;
	vector<vector<T>> pow2mins;
	vector<int> depth;

  public:
	Tree(const vector<int> &parents, const vector<T> &vals)
	    : parents(parents), vals(vals),
	      log2dist(ceil(log2(parents.size() + 1))),
	      pow2ends(parents.size(), vector<int>(log2dist + 1)),
	      pow2mins(parents.size(), vector<T>(log2dist + 1)) {
		assert(parents[root] == -1);

		vector<vector<int>> children(parents.size());
		for (int n = 0; n < parents.size(); n++) {
			if (parents[n] != -1) { children[parents[n]].push_back(n); }
		}
		depth = vector<int>(parents.size());
		vector<int> frontier{root};
		while (!frontier.empty()) {
			int curr = frontier.back();
			frontier.pop_back();
			for (int n : children[curr]) {
				depth[n] = depth[curr] + 1;
				frontier.push_back(n);
			}
		}

		for (int n = 0; n < parents.size(); n++) {
			pow2mins[n][0] = vals[n];
			pow2ends[n][0] = parents[n];
		}
		for (int p = 1; p <= log2dist; p++) {
			for (int n = 0; n < parents.size(); n++) {
				int halfway = pow2ends[n][p - 1];
				if (halfway == -1) {
					pow2ends[n][p] = -1;
					pow2mins[n][p] = pow2mins[n][p - 1];
				} else {
					pow2ends[n][p] = pow2ends[halfway][p - 1];
					pow2mins[n][p] =
					    min(pow2mins[n][p - 1], pow2mins[halfway][p - 1]);
				}
			}
		}
	}

	/**
	 * @return the min value on the path from the ancestor to its descendant,
	 *         not including the ancestor.
	 */
	T min_val(int ancestor, int desc) {
		int dist = depth[desc] - depth[ancestor];
		T ret = vals[desc];
		int at = desc;
		for (int pow = 0; pow <= log2dist; pow++) {
			if ((dist & (1 << pow)) != 0) {
				ret = min(ret, pow2mins[at][pow]);
				at = pow2ends[at][pow];
			}
		}
		assert(at == ancestor);
		return ret;
	}
};

vector<int> Dominators(ll n, vii &adj) {
	vii rev_adj(adj.size());
	for (int i = 0; i < adj.size(); i++) {
		for (auto j : adj[i]) {
			rev_adj[j].push_back(i);
		}
	}

	// Variables used for the Euler Tour
	vector<int> visit_order;
	// visit_time is initialized with INF so nodes that aren't reachable
	// during the DFS won't mess up our sdom calculation
	vector<int> visit_time(n, INT32_MAX);
	vector<int> visit_parent(n, -1);
	vector<bool> visited(n, false);
	function<void(int, int)> dfs;
	dfs = [&](int at, int prev) {
		if (visited[at]) { return; }
		visited[at] = true;

		visit_time[at] = visit_order.size();
		visit_order.push_back(at);
		visit_parent[at] = prev;
		for (int next : adj[at]) { dfs(next, at); }
	};
	dfs(0, -1);

	// We use a function-based interface instead of a class-based one due to
	// heavy reliance on previously calculated values
	vector<int> dsu_parent(n, -1);
	vector<int> dsu_min(n, INT32_MAX);
	function<int(int)> find;
	find = [&](int x) {
		if (dsu_parent[x] == -1) { return x; }
		if (dsu_parent[dsu_parent[x]] != -1) {
			int parent_res = find(dsu_parent[x]);
			if (visit_time[parent_res] < visit_time[dsu_min[x]]) {
				dsu_min[x] = parent_res;
			}
			dsu_parent[x] = dsu_parent[dsu_parent[x]];
		}
		assert(dsu_min[x] != INT32_MAX);
		return dsu_min[x];
	};

	vector<int> sdom(n, -1);
	for (int i = visit_order.size() - 1; i > 0; i--) {
		int c = visit_order[i];
		// Iterate over all nodes with a directed edge to c
		for (int from : rev_adj[c]) {
			int find_res = find(from);
			// Take the node with the earliest visit time in the traversal
			if (sdom[c] == -1 || visit_time[find_res] < visit_time[sdom[c]]) {
				sdom[c] = find_res;
			}
		}

		// Link c to its parent in the DFS tree
		dsu_parent[c] = visit_parent[c];
		dsu_min[c] = sdom[c];
	}

	// Initialize the values in the tree
	vector<pair<int, int>> sdom_times(n, {INT32_MAX, -1});
	for (int c : visit_order) {
		if (c != 0) {
			// The tree takes the minimum of these pairs, but what we
			// really want is the node itself- therefore, we store both
			sdom_times[c] = {visit_time[sdom[c]], c};
		}
	}
	Tree<pair<int, int>> tree(visit_parent, sdom_times);

	vector<int> rdom(n, -1);
	for (int c : visit_order) {
		if (c != 0) {
			// Use the definition of the rdom
			rdom[c] = tree.min_val(sdom[c], c).second;
		}
	}

	// Use the properties previously given to compute the idom
	vector<int> idom(n, -1);
	for (int c : visit_order) {
		if (c != 0) { idom[c] = rdom[c] == c ? sdom[c] : idom[rdom[c]]; }
	}

	return idom;
}


void solve(int tc) {
	ll n, m;

	cin >> n >> m;

	vii adj(n);
	for (int i = 0; i < m; i++) {
		ll u, v;
		cin >> u >> v;
		u--, v--;;
		adj[u].push_back(v);
	}

	auto idom = Dominators(n, adj);

	vi res;
	ll at = n-1;
	while (at != 0) {
		res.push_back(at);
		at = idom[at];
	}
	res.push_back(0);
	reverse(all(res));
	
	cout << res.size() << '\n';
	sortx(res);
	for (auto a : res) cout << a + 1 << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int size = 1;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	// cin >> size;
	for (int i = 1; i <= size; i++)
		solve(i);
}

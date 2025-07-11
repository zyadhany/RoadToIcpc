vii biconnected_components(vii &g, vi &is_cutpoint, vi &id) {
	int n = (int)g.size();

	vii comps;
	vi stk;
	vi num(n);
	vi low(n);

	is_cutpoint.resize(n);

	// Finds the biconnected components
	function<void(int, int, int &)> dfs = [&](int node, int parent, int &timer) {
		num[node] = low[node] = ++timer;
		stk.push_back(node);
		for (auto son : g[node]) {
			if (son == parent) { continue; }
			if (num[son]) {
				low[node] = min(low[node], num[son]);
			} else {
				dfs(son, node, timer);
				low[node] = min(low[node], low[son]);
				if (low[son] >= num[node]) {
					is_cutpoint[node] = (num[node] > 1 || num[son] > 2);
					comps.push_back({node});
					while (comps.back().back() != son) {
						comps.back().push_back(stk.back());
						stk.pop_back();
					}
				}
			}
		}
	};

	int timer = 0;
	dfs(0, -1, timer);
	id.resize(n);

	// Build the block-cut tree
	function<vii()> build_tree = [&]() {
		vii t(1);
		int node_id = 0;
		for (int node = 0; node < n; node++) {
			if (is_cutpoint[node]) {
				id[node] = node_id++;
				t.push_back({});
			}
		}

		for (auto &comp : comps) {
			int node = node_id++;
			t.push_back({});
			for (int u : comp)
				if (!is_cutpoint[u]) {
					id[u] = node;
				} else {
					t[node].push_back(id[u]);
					t[id[u]].push_back(node);
				}
		}
		return t;
	};

	return build_tree();
}

void solve(int tc) {
	ll n, m, q;
	cin >> n >> m >> q;

	// 0 index Connected Graph
	vii adj(n);
	for (int i = 0; i < m; i++)
	{
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vi cut(n), id(n);
	adj = biconnected_components(adj, cut, id);
	// new tree with 2*n noes
	Graph gr(n*2, adj);
}

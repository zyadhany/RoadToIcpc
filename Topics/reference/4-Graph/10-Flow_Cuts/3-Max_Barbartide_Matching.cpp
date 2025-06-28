/**
 * Matching is taking edges from graph such that no two edges share a vertex.
 * 
 * In bipartite graph we can find max matching using max_flow.
 * 
 * In a bipartite graph, we can find a maximum matching using the Hopcroft-Karp algorithm.
 */

 /*
 The whole theory: when graph is maximum matching, then the size of left set is equal to the size of right set and for every set in left graph of size A there is atleast A nodes in right graph that are reachable from it.
 */


// Hopcroft-Karp: O(sqrt(V) * E)
const int MXN = 1e5;
vi adj[MXN];
ll P[MXN]{}, vis[MXN]{};

bool dfs(ll u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (auto neg : adj[u]) {
		if (!P[neg]) {
			P[neg] = u, P[u] = neg;
			return 1;
		}
		if (dfs(P[neg])) {
			P[neg] = u, P[u] = neg;
			return 1;
		}
	}
	return 0;
}

void solve(int tc) {
    ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		ll u, v; cin >> u >> v;
		adj[u].push_back(v+n);
	}

	for (int i = 1; i <= n; i++)
	{
		if(!P[i]) {
			fill(vis, vis+n+1, 0);
			dfs(i);
		}
	}

	vp res;
	for (int i = 1; i <= n; i++)
	{
		if (P[i]) res.push_back({i, P[i]-n});
	}
	
	cout << res.size() << '\n';
	for (auto p : res) cout << p.first << ' ' << p.second << '\n';
}
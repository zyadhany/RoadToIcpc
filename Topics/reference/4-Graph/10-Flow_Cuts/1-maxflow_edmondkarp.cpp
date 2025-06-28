// Time: O(V*E^2)

long long max_flow(vector<vector<ll>> adj, vector<vector<long long>> capacity,
                   int source, int sink) {
	int n = adj.size();
	vector<int> parent(n, -1);
	// Find a way from the source to sink on a path with non-negative capacities
	auto reachable = [&]() -> bool {
		queue<int> q;
		q.push(source);
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int son : adj[node]) {
				long long w = capacity[node][son];
				if (w <= 0 || parent[son] != -1) continue;
				parent[son] = node;
				q.push(son);
			}
		}
		return parent[sink] != -1;
	};

	long long flow = 0;
	// While there is a way from source to sink with non-negative capacities
	while (reachable()) {
		int node = sink;
		// The minimum capacity on the path from source to sink
		long long curr_flow = LLONG_MAX;
		while (node != source) {
			curr_flow = min(curr_flow, capacity[parent[node]][node]);
			node = parent[node];
		}
		node = sink;
		while (node != source) {
			// Subtract the capacity from capacity edges
			capacity[parent[node]][node] -= curr_flow;
			// Add the current flow to flow backedges
			capacity[node][parent[node]] += curr_flow;
			node = parent[node];
		}
		flow += curr_flow;
		fill(parent.begin(), parent.end(), -1);
	}

	return flow;
}

void solve(int tc) {
    ll n, m;
    cin >> n >> m;
    vii adj(n+1);
    vii cap(n+1, vi(n+1, 0));
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v]+=w;
    }

    cout << max_flow(adj, cap, 1, n) << '\n';
}
    
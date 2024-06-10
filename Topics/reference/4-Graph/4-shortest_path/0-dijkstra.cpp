class Graph {
public:
    int size;
    vi vis;
    vector<vector<pl>> adj;

    void addEdge(int u, pl v) {
        adj[u].push_back(v);
    }

	vi dijkstra(ll v) {
		vi Z(size + 1, INT32_MAX);

		priority_queue<pl, vp, greater<pl>> L;
		L.push({0, v});
		Z[v] = 0;

		while (!L.empty())
		{
			auto k = L.top();
			L.pop();
			if (k.first > Z[k.second]) continue;

			for (auto neg : adj[k.second]) {
				ll cost = neg.second + k.first;
				if (Z[neg.first] <= cost) continue;
				Z[neg.first] = cost;
				L.push({cost, neg.first});
			}
		}

		return (Z);
	}

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

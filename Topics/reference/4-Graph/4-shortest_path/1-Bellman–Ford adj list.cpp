#define INF 1e16

class Graph {
public:    
    int size;
    vector<vp> adj;
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    vi BellmanFord(int src) {
        vi Z(size + 1, INF);
        Z[src] = 0;

        // itrate n - 1 to get shortest path.
        for (int i = 0; i < size - 1; i++) {
            for (int u = 0; u < size; u++) {
                if (Z[u] == INF) { continue; }
                for (auto &[v, w] : adj[u]) { Z[v] = min(Z[v], Z[u] + w); }
            }
        }

        queue<ll> que;
        for (int u = 0; u < size; u++) {
			if (Z[u] == INF) { continue; }
			for (auto &[v, w] : adj[u]) { 
				if (Z[u] + w < Z[v]) que.push(v);
				}
		}
		
        while (!que.empty())
        {
            ll u = que.front();
            que.pop();
            Z[u] = -INF;
            for (auto [v, w] : adj[u]) {
                if (Z[v] != -INF) {
                    que.push(v);
                    Z[v]=-INF;
                }
            }
        }
        
        return (Z);
    }

    Graph(ll n) : adj(n+1) {
        size = n;
    }
};
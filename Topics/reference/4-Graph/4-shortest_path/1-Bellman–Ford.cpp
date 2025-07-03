#define INF 1e16

/**
 * Time O(n * m) 
*/
class Graph {
public:
	struct edge {
		int u, v, w;
	};
    
	int size;
	vector<edge> E;
	
    void addEdge(int u, int v, int w) {
        edge ed = {u, v, w};
		E.push_back(ed);
    }

	vi BellmanFord(int src) {
		vi Z(size + 1, INF);
		Z[src] = 0;

		// itrate n - 1 to get shortest path.
		for (int i = 1; i <= size - 1; i++)
		{
			for (int j = 0; j < E.size(); j++)
			{
				ll u = E[j].u, v = E[j].v, w = E[j].w;
				if (Z[u] != INF && Z[u] + w < Z[v]) Z[v] = Z[u] + w;
			}
		}
		
		// itrate last time to ensure negrive syclic
		for (int i = 1; i <= size - 1; i++) {
			for (int j = 0; j < E.size(); j++)
			{
				ll u = E[j].u, v = E[j].v, w = E[j].w;
				if (Z[u] != INF && Z[u] + w < Z[v]) Z[v] = -INF;
				if (Z[u] == -INF) Z[v] = -INF;
			}
		}

		return (Z);
	}

    Graph(ll n) {
        size = n;
    }
};


// find the negative cycle
vi BelmenNegativeCycle() {
	vi Z(size + 1, INF);
	vi P(size + 1, -1);
	
	ll ls = -1;
	for (int i = 1; i <= size; i++)
	{
		ls = -1;
		for (int j = 0; j < E.size(); j++)
		{
			ll u = E[j].u, v = E[j].v, w = E[j].w;
			if (Z[u] + w < Z[v]) {
				Z[v] = Z[u] + w;
				P[v] = u;
				ls = v;
			}
		}
	}

	vi res;
	if (ls == -1) return {};
	for (int i = 0; i < size-1; i++) ls = P[ls];        
	for (int x = ls;; x = P[x]) {
		res.push_back(x);
		if (x == ls && res.size() > 1) break;
	}
	reverse(all(res));
	return res;
}

/**
 * get start of node
 * INF: Can't reach.
 * -INF: Negative Cyclic.
 */
ll BellmanFord(int src) {
	vi Z(size + 1, INF);
	Z[src] = 0;

	// itrate n - 1 to get shortest path.
	for (int i = 1; i <= size - 1; i++)
	{
		for (int j = 0; j < E.size(); j++)
		{
			ll u = E[j].u, v = E[j].v, w = E[j].w;
			if (Z[u] + w < Z[v] && Z[u] != INF) Z[v] = Z[u] + w;
		}
	}
	
	// itrate last time to ensure negrive syclic
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < E.size(); j++)
		{
			ll u = E[j].u, v = E[j].v, w = E[j].w;
			if (Z[u] + w < Z[v] && Z[u] != INF) Z[v] = -INF;
		}
	}

	if (Z[size] == -INF) return (-1); 
	return -Z[size];
}



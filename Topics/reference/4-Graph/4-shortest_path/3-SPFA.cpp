/**
The SPFA algorithm (”Shortest Path Faster Algorithm”) [20] is a variant of the
Bellman–Ford algorithm, that is often more efficient than the original algorithm.
The SPFA algorithm does not go through all the edges on each round, but instead,
it chooses the edges to be examined in a more intelligent way.
The algorithm maintains a queue of nodes that might be used for reducing
the distances. First, the algorithm adds the starting node x to the queue. Then,
the algorithm always processes the first node in the queue, and when an edge
a → b reduces a distance, node b is added to the queue.
The efficiency of the SPFA algorithm depends on the structure of the graph:
the algorithm is often efficient, but its worst case time complexity is still O(nm)
and it is possible to create inputs that make the algorithm as slow as the original
Bellman–Ford algorithm.
*/

// Negtive Cyclyc Can lead to TimeLimit.

#define INF 1e16

class Graph {
public:
    int size;
    vi vis;
    vector<vector<pl>> adj;

    void addEdge(int u, pl v) {
        adj[u].push_back(v);
    }

	vi SPFA(int src) {
		vi Z(size + 1, INF);
        vector<bool> InQueue(size + 1, 0);
		queue<int> que;
        
        que.push(src);
        Z[src] = 0;
        InQueue[src] = 1;

        while (!que.empty())
        {
            int u = que.front();
            que.pop();
            InQueue[u] = 0;

            for (auto neg : adj[u]) {
                int v = neg.first;
                int w = neg.second;
                if (Z[v] > Z[u] + w) {
                    Z[v] = Z[u] + w;
                    if (!InQueue[v]) {
                        InQueue[v] = 1;
                        que.push(v);
                    }
                }
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

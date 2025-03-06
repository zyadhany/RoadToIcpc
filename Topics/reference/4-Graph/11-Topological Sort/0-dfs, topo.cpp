class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // if there is a cycle, return empty vector and no topological sort
    bool DFS(vi &X, int u) {
        if (vis[u] == 1) return 1;
        if (vis[u] == -1) return 0;
        vis[u] = -1;

        for (auto v : adj[u])
            if (!DFS(X, v)) return 0;

        X.push_back(u);
        vis[u] = 1;
        return 1;
    }

    vi TopologicalSort() {
        vi X;
        for (int i = 1; i <= size; i++) 
            if (!DFS(X, i)) return vi();
        reverse(all(X));
        return (X);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

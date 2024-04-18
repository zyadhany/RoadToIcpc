class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(vi &X, ll n) {
        if (vis[n]) return;
        vis[n] = 1;
        for (auto neg : adj[n]) DFS(X, neg);
        X.push_back(n);
    }

    vi TopologicalSort() {
        vi X;
        for (int i = 1; i <= size; i++) DFS(X, i);
        reverse(all(X));
        return (X);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

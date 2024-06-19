class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void DFS(vi &visited, ll n, ll at) {
        if (visited[n]) return;
        visited[n] = at;
        for (auto neg : adj[n]) DFS(visited, neg, at);
    }

    bool IsConnected() {
        vi visited(size + 1);
        ll at = 0;
        for (int i = 1; i <= size; i++)
        {
            if (!visited[i]) {
                at++;
                DFS(visited, i, at);
            }
        }
        
        return (at <= 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

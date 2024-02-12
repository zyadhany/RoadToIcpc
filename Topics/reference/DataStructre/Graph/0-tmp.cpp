class Graph {
public:
    vi vis;
    vii adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }



    Graph(ll n) {
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

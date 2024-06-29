class Graph {
public:
    int size, SPSIZE;
    vi vis, Indeg;
    vii adj;
    vp Trav;
    vector<vp> table;

    void dfs(int n, int p, ll deep) {
        Indeg[n] = Trav.size();
        Trav.push_back({n, deep});
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n, deep + 1);
            Trav.push_back({deep, n});
        }
    }

    void BuildLCA() {
        dfs(1, 0, 1);

        ll n, m;
        n = size + 1; m = SPSIZE = ceil(log2(n));
        table.resize(n, vp(m + 1));
        for (int i = 0; i < n; i++)
            table[i][0] = Trav[Indeg[i]];
    
        for (int j = 1; j <= m; j++)
            for (int i = 0; i <= n - (1 << j); i++)
                table[i][j] = min(table[i][j - 1],
                table[i + (1 << (j - 1))][j - 1]);
    }

    ll LCA(ll a, ll b) {
        ll l = Indeg[a], r = Indeg[b];
        if (l > r) swap(l, r);
        int j = (int)log2(r - l + 1); 
        return min(table[l][j], table[r - (1 << j) + 1][j]).second;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

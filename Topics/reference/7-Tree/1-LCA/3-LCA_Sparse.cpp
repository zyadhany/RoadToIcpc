class Graph {
public:
    int size;
    vi vis, lvl;
    vii adj, SPT;


    void BuildSparse(ll node=1, ll parent=0){
        lvl[node] = lvl[parent] + 1;
        SPT[node][0] = parent;
        for (int i = 1; i < SPT[node].size(); i++)
            SPT[node][i] = SPT[SPT[node][i - 1]][i - 1];        
        for (auto neg : adj[node])
            if (neg != parent) BuildSparse(neg, node);
    }

    ll getKth(ll u, ll k){
        for (int i = 0; i < SPT[u].size(); i++)
            if ((1 << i) & k) u = SPT[u][i];
        return (u);
    }

    ll LCA(ll u, ll v) {
        if (lvl[u] > lvl[v]) swap(u, v);
        v = getKth(v, lvl[v] - lvl[u]);
        if (u == v) return (u);
        for (int i = SPT[u].size() - 1; i >= 0; i--)
        {
            if (SPT[u][i] != SPT[v][i]){
                u = SPT[u][i], v = SPT[v][i];
            }
        }
        return (SPT[u][0]);
    }

    ll dist(ll u, ll v) {
        ll p = LCA(u , v);
        return (lvl[u] + lvl[v] - 2 * lvl[p]);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
        SPT.resize(n + 1, vi(ceil(log2(n + 1)) + 1));
    }
};


// check if z on path  of x to y
auto on_path = [&](int x, int y, int z) {
    int lca = find_lca(x, y);
    int lca1 = find_lca(x, z);
    int lca2 = find_lca(y, z);

    if (lca == z || (lca1 == lca && lca2 == z) || (lca2 == lca && lca1 == z)) {
        return true;
    }
    return false;
};
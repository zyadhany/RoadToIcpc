// Heavy Light Decomposition
struct HLD {
    int size, timer;
    vi lvl, par, heavy, head, in, sz;
    vii adj;
 
    void dfs(int u, int p) {
        par[u] = p;
        sz[u] = 1;
        for (int v : adj[u]) if (v != p) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
            if (!heavy[u] || sz[v] > sz[heavy[u]]) heavy[u] = v;
        }
    }
    
    void decompose(int u, int p){
        in[u] = timer++;
        if (heavy[u]) {
            head[heavy[u]] = head[u];
            decompose(heavy[u], u);
        }
        for (int v : adj[u]) if (v != p && v != heavy[u]) {
            head[v] = v;
            decompose(v, u);
        }
    }
 
    HLD(int n, vii &adj) : size(n), lvl(n+1), par(n+1), heavy(n+1), head(n+1), in(n+1), adj(adj), sz(n+1) {
        dfs(1, 0);
        timer = 1;
        head[1] = 1;
        decompose(1, 0);
    }
 
    vp get_path(int u, int v) {
        vp path;
        while (head[u] != head[v]) {
            if (lvl[head[u]] < lvl[head[v]]) swap(u, v);
            // if cost in edges not node let in[head[u]] + 1. and edge cost get down to child node.
            path.push_back({in[head[u]], in[u]});
            u = par[head[u]];
        }
        if (lvl[u] > lvl[v]) swap(u, v);
        // u is lca between u and v
        path.push_back({in[u], in[v]});
        return path;
    }
};

// Qyery fast without getting path
ll get_path(int u, int v) {
    ll mx = 0;
    while (head[u] != head[v]) {
        if (lvl[head[u]] < lvl[head[v]]) swap(u, v);
        mx = max(mx, query(in[head[u]], in[u]));
        u = par[head[u]];
    }
    if (lvl[u] > lvl[v]) swap(u, v);
    mx = max(mx, query(in[u], in[v]));
    return mx;
}
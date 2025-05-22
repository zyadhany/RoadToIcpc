int par[MXN], sz[MXN], cdprc[MXN];
struct CentrtiodDecomp {
    vii adj;
    
    ll dfs(ll u, ll p) {
        sz[u] = 1;
        for (auto neg : adj[u]) if (neg != p && !cdprc[neg]) sz[u] += dfs(neg, u);
        return sz[u];
    }
    
    ll centriod(ll u, ll p, ll n) {
        for (auto neg : adj[u]) if (neg != p && !cdprc[neg] && sz[neg] > n/2) 
        return centriod(neg, u, n);
        return u;
    }
    
    void build(ll u, ll p) {
        ll sz = dfs(u, p);
        ll cen = centriod(u, p, dfs(u, p));
        if (!p) p = cen;
        par[cen] = p, cdprc[cen] = 1;
        for (auto neg : adj[cen]) if (!cdprc[neg]) build(neg, cen);
   }
    
    CentrtiodDecomp(ll n, const vii &edg): adj(edg) {
        build(1, 0);
    }
 
    int operator[](ll u) {
        return par[u];
    }
};

// gr -> to get lca and distance between 2 nodes.
void update(CentrtiodDecomp &cd, Graph &gr, vi &dp, ll k) {
    ll at = k;
    while (true)
    {
        dp[at] = min(dp[at], gr.dist(at, k));
        if (cd[at] == at) break;
        at = cd[at];
    }
}
 
ll query(CentrtiodDecomp &cd, Graph &gr, vi &dp, ll k) {
    ll ans = INT32_MAX;
    ll at = k;
    while (true)
    {
        ans = min(ans, dp[at] + gr.dist(at, k));
        if (cd[at] == at) break;
        at = cd[at];
    }
    return ans;
}

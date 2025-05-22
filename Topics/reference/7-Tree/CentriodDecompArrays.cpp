const int MXN = 2e5+10;
int par[MXN], sz[MXN], cdprc[MXN];
 
vector<int> adj[MXN];
    
int dfs(int u, int p) {
    sz[u] = 1;
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg]) sz[u] += dfs(neg, u);
    return sz[u];
}
 
int centriod(int u, int p, int n) {
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg] && sz[neg] > n/2) 
    return centriod(neg, u, n);
    return u;
}
 
void build(int u, int p) {
    int cen = centriod(u, p, dfs(u, p));
    if (!p) p = cen;
    par[cen] = p, cdprc[cen] = 1;
 
    for (auto neg : adj[cen]) if (!cdprc[neg]) build(neg, cen);
}

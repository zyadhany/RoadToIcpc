/*
get eulerian circuit of a undirected graph
you can convert it to path by checking the number of odd degree is 0 or 2, if it's 2 we start from one of the odd degree vertices
*/
void dfs(vector<vp> &adj, vi &eular, vi &vis, ll n) {
    while (!adj[n].empty())
    {
        auto [neg, ind] = adj[n].back();
        adj[n].pop_back();
        if (vis[ind]) continue;
        vis[ind] = 1;
        dfs(adj, eular, vis, neg);
    }
    eular.push_back(n);
}

void solve(int tc) {
    ll n, m;
    cin >> n >> m;

    vector<vp> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    ll cntod = 0;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() % 2) cntod++;
    if (cntod) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vi eurlcirc, vis(m);
    vector<vp> tmadj(adj);
    dfs(tmadj, eurlcirc, vis, 1);
    if (eurlcirc.size() != m+1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto a : eurlcirc) cout << a << ' ';
    cout << '\n';
}
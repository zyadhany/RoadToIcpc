ll dist(pl a, pl b){
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

ll req(vii &vis, vp &X, ll lst, bitset<11>bt){
    if (bt.count() == X.size()) {
        return (dist(X[0], X[lst]));
    }
    
    ll &ans = vis[lst][bt.to_ulong()];
    if (~ans) return (ans);
    ans = INT32_MAX;

    bitset<11> re;
    for (int i = 1; i < X.size(); i++)
    {
        if (!bt[i]) {
            re = bt;
            re[i] = 1;
            ans = min(ans, req(vis, X, i, re) + dist(X[lst], X[i]));
        }
    }
    
    return (ans);
}

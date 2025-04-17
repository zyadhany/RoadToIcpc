void makebinerytree(vii &adj, vi &ND, ll n, ll h) {
    if (h == 0) return;
    ll b = ND.back();
    ND.pop_back();
    adj[n].push_back(b);
    makebinerytree(adj, ND, b, h-1);
    
    b = ND.back();
    ND.pop_back();
    adj[n].push_back(b);
    makebinerytree(adj, ND, b, h-1);
}

vii makebinerytree(ll h) {
    ll n = (1<<h)-1;
    vi ND(n-1);
    for (int i = 0; i < n-1; i++)
    {
        ND[i] = i+1;
    }
    shuffle(ND.begin(), ND.end());
    

    vii adj(n);
    makebinerytree(adj, ND, 0, h-1);
    return adj;
}

/*
Convert scc to dag graph
C: component number for each node
*/
vii DAG(vii &adj, vii &cc, ll n) {
    ll m = cc.size();
    vi C(n+1);
    for (int i = 0; i < cc.size(); i++)
        for (auto a : cc[i]) C[a] = i+1;
    
    vii nadj(m+1);
    for (int i = 0; i <= n; i++)
        for (auto neg : adj[i]) if (C[i] != C[neg]) 
            nadj[C[i]].push_back(C[neg]);    
    
    for (int i = 0; i < nadj.size(); i++)
        nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
    return nadj;    
}
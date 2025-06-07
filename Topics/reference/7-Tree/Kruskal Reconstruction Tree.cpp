/*
we can answer query min or max edge between 2 node of tree in O(1) with preprocssing O(nlogn).

the construction be tree with 2*n - 1 nodes, the orginal n nodes is leafs and n-1 node represent edges of the tree.

after construction of KRT we the answer of (u, v) is val of LCA(u, v).
*/

const int MXN = 4e5+10, lg = 20;
int root;
int P[MXN], V[MXN], Indeg[MXN], lvl[MXN];
pl table[MXN][lg];
vi adj[MXN];
vp Trav;

ll get(ll n) {
    if(P[n] == n) return n;
    return P[n] = get(P[n]);
}

void add(ll u, ll v, ll w) {
    u = get(u), v = get(v);
    if (u == v) return;
    root++;
    V[root] = w;
    adj[root].push_back(u);    
    adj[root].push_back(v); 
    P[u] = P[v] = root;
}

void dfs(int n, int p, ll deep) {
    lvl[n] = deep;
    Indeg[n] = Trav.size();
    Trav.push_back({deep, n});
    for (auto neg : adj[n]) {
        if (neg == p) continue;
        dfs(neg, n, deep + 1);
        Trav.push_back({deep, n});
    }
}

ll LCA(ll a, ll b) {
    ll l = Indeg[a], r = Indeg[b];
    if (l > r) swap(l, r);
    int j = (int)log2(r - l + 1); 
    return min(table[l][j], table[r - (1 << j) + 1][j]).second;
}

void KRT() {
    dfs(root, 0, 0);
    ll n = Trav.size();
    int SPSIZE = ceil(log2(n));
    for (int i = 0; i < n; i++)
        table[i][0] = Trav[i];
    
    for (int j = 1; j <= SPSIZE; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}

void INIT(ll n) {
    Trav.clear();
    root = n;
    for (int i = 0; i <= n*2; i++)
    {
        P[i] = i;
        V[i] = 0;
        adj[i].clear();
    }
}

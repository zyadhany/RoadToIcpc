 
class Graph {
public:
    int timer;
    int size, SPSIZE;
    vi Outdeg, X;
    vi vis, Indeg, ST;
    vii adj;
    vp Trav;
    vector<vp> table;
 
    void dfs(int n, int p, ll deep) {
        X[n] ^= X[p];
        ST[n] = timer++;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n, deep + 1);
            Trav.push_back({deep, n});
        }
        Outdeg[n] = timer-1;
    }
 
    void BuildLCA() {
        dfs(1, 0, 1);
        ll n = Trav.size();
        SPSIZE = ceil(log2(n));
        table.resize(n, vp(SPSIZE + 1));
        for (int i = 0; i < n; i++)
            table[i][0] = Trav[i];
        
        for (int j = 1; j <= SPSIZE; j++)
            for (int i = 0; i <= n - (1 << j); i++)
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }
 
    ll LCA(ll a, ll b) {
        ll l = Indeg[a], r = Indeg[b];
        if (l > r) swap(l, r);
        int j = (int)log2(r - l + 1); 
        return min(table[l][j], table[r - (1 << j) + 1][j]).second;
    }
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    Graph(ll n) {
        timer = 1;
        size = n;
        X.assign(n + 1, 0);
        Outdeg.assign(n + 1, 0);
        Indeg.assign(n + 1, 0);
        ST.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

typedef long long item;
class SegmentTree
{
public:
    void set(ll l, ll r, ll value) {
        set(0, 0, size - 1, l, r, value);
    }

    item getrange(ll l, ll r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(vector<item>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, 0);

        build(X, 0, 0, size - 1);
    }

private:
    ll size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item a, item b) {
        item res = (a ^ b);
        return (res);
    }

    void checkLazy(ll m, ll lx, ll rx) {
        if (!lazy[m]) return;
        tree[m] ^= lazy[m];
        
        if (lx != rx) {
            lazy[2 * m + 1] ^= lazy[m];
            lazy[2 * m + 2] ^= lazy[m];
        }

        lazy[m] = 0;
    }

    void set(ll m, ll lx, ll rx, ll l, ll r, ll val) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return;
        if (l <= lx && rx <= r)
        {
            lazy[m] = val;
            checkLazy(m, lx, rx);
            return;
        }

        ll mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, l, r, val);
        set(m * 2 + 2, mid + 1, rx, l, r, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(ll m, ll lx, ll rx, ll l, ll r) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        ll mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<item>& X, ll m, ll lx, ll rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = X[lx];
            return;
        }

        ll mid = (lx + rx) / 2;
        item s1, s2;

        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }
};


void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    Graph gr(n);
    vi VAL(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> VAL[i + 1];
        gr.X[i + 1] = VAL[i + 1];
    }

    for (int i = 0; i < n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        gr.addEdge(u, v);
    }
    
    gr.BuildLCA();
    vi X(n + 10);
    for (int i = 1; i <= n; i++)
    {
        X[gr.ST[i]] = gr.X[i];
    }
    
    SegmentTree sg;
    sg.build(X);
    
    while (q--)
    {
        ll ty; cin >> ty;
        
        if (ty == 1) {
            ll nd, v;
            cin >> nd >> v;
            ll diff = v ^ VAL[nd];
            VAL[nd] = v;
            sg.set(gr.ST[nd], gr.Outdeg[nd], diff);
        } else {
            ll u, v; cin >> u >> v;
            ll a = sg.getrange(gr.ST[u], gr.ST[u]);
            ll b = sg.getrange(gr.ST[v], gr.ST[v]);
            ll lc = gr.LCA(u, v);
            ll re = (a ^ b ^ VAL[lc]);
            cout << re << '\n';
        }
    }
}
    
/**
 * we make traverse array as we have
  indegree and size and value of edge
 * to get value of subtree we take 
  we make marge of lange of it's size
 * we can make query of update using segment tree.
 */

/**
 * we can make path query if we storepath from root to node
 * each node store summ of path from root to it
 * if increase value of node by 5 we increase all values
 * of it subtree by 5.
 */
class Graph {
public:
    int size;
    vi vis;
    vii adj;

    vi Travese, Indeg, SubSize;

    ll dfs(int n, int p) {
        ll summ = 1;
        Indeg[n] = Travese.size();
        Travese.push_back(n);
        for (auto neg : adj[n])
            if (neg != p) summ += dfs(neg, n);
        return (SubSize[n] = summ);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        SubSize.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

class Graph {
public:
    int size;
    vi vis;
    vii adj;

    vi Travese, Indeg, SubSize;

    ll dfs(int n, int p) {
        ll summ = 1;
        Indeg[n] = Travese.size();
        Travese.push_back(n);
        for (auto neg : adj[n])
            if (neg != p) summ += dfs(neg, n);
        return (SubSize[n] = summ);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        SubSize.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


typedef long long item;

class SegmentTree
{
public:
    void set(int l, int r, ll value) {
        set(0, 0, size - 1, l, r, value);
    }

    item getrange(int l, int r) {
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
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item a, item b) {
        item res = a + b;
        return (res);
    }

    void checkLazy(int m, ll lx, ll rx) {
        if (!lazy[m]) return;
        tree[m] = lazy[m] * (rx - lx + 1ll);
        
        if (lx != rx) {
            lazy[2 * m + 1] = lazy[m];
            lazy[2 * m + 2] = lazy[m];
        }

        lazy[m] = 0;
    }

    void set(int m, int lx, int rx, int l, int r, ll val) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return;
        if (l <= lx && rx <= r)
        {
            lazy[m] = val;
            checkLazy(m, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, l, r, val);
        set(m * 2 + 2, mid + 1, rx, l, r, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<item>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = X[lx];
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }
};

void solve(ll test) {
    ll n;

    cin >> n;

    Graph gr(n);
    vi X(n + 1), Z;

    for (int i = 1; i <= n; i++)
        cin >> X[i];

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
        gr.addEdge(v, u);
    }
    gr.dfs(1, 0);

    for (auto m : gr.Travese) Z.push_back(X[m]);
    SegmentTree sg;
    sg.build(Z);

    ll q; cin >> q;
    while (q--)
    {
        ll opp; cin >> opp;

        if (opp == 1) {
            ll l, r; cin >> l >> r;
            ll a = gr.Indeg[l];
            ll b = a + gr.SubSize[l] - 1;
            sg.set(a, b, r);
        } else
        {
            ll l; cin >> l;
            ll a = gr.Indeg[l];
            ll b = a + gr.SubSize[l] - 1;
            ll summ = sg.getrange(a, b);
        }   
    }
}

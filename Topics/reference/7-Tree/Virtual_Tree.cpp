/*
Given a tree and queries, each query consists of a set of nodes.
we can make virtual tree that have compressed version of the tree and constains all set of nodes and their LCA.
if size of set is k then we will have virtual tree with at most 2k-1 nodes.

after constructing the virtual tree with O(klog(k)), we can answer the query in O(k) time.
*/
class Graph {
public:
    int size, SPSIZE;
    vi Indeg, lvl;
    vp Trav;
    vector<vp> table;

    void dfs( const vii &adj, int n, int p, ll deep) {
        lvl[n] = deep;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(adj, neg, n, deep + 1);
            Trav.push_back({deep, n});
        }
    }

    void BuildLCA() {
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

    ll dist(ll a, ll b) {
        return lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
    }

    vector<vp> virtual_tree(vi &nodes) {
        // compare in dfs order
        auto cmp = [&](ll a, ll b) {
            return Indeg[a] < Indeg[b];
        };
        sort(all(nodes), cmp);
        ll n = nodes.size();
        for (int i = 0; i < n-1; i++)
        {
            nodes.push_back(LCA(nodes[i], nodes[i+1]));
        }

        sort(all(nodes), cmp);
        nodes.erase(unique(all(nodes)), nodes.end());        
        n = nodes.size();

        vector<vp> adj(n);
        stack<ll> st;
        st.push(0);
        for (int i = 1; i < n; i++)
        {
            while (LCA(nodes[st.top()], nodes[i]) != nodes[st.top()]) st.pop();
            adj[st.top()].push_back({i, dist(nodes[st.top()], nodes[i])});
            st.push(i);
        }
        
        return adj;
    }

    ll dfsquery(vector<vp> &adj, vi &V, vi &dp, ll n) {
        ll cnt = 0;
        bool obn = 1;

        for (auto [neg, w] : adj[n]) {
            auto re = dfsquery(adj, V, dp, neg);
            if (dp[neg] == -1) {dp[n] = -1; return 0;}
            dp[n] += dp[neg];

            if (!re) continue; 
            cnt++;
            if (w==1 && V[neg]) obn = 0;
        }

        if (V[n]) {
            if (!obn) {dp[n]=-1; return 0;};
            dp[n] += cnt;
            return 1;
        }
        if (cnt <= 1) return cnt;
        dp[n]++;
        return 0;
    }

    ll query(vi nodes) {
        set<ll> st(all(nodes));
        auto adj = virtual_tree(nodes);
        ll n = nodes.size();
        vi V(n);
        for (int i = 0; i < n; i++)
        {
            if (st.count(nodes[i])) V[i] = 1;
        }
        
        vi dp(n);
        dfsquery(adj, V, dp, 0);
        return dp[0];
    }

    Graph(ll n, const vii &adj) : size(n), lvl(n+1), Indeg(n+1) {
        dfs(adj, 1, 0, 1);
        BuildLCA();
    }
};

void solve(int tc) {
    ll n;

    cin >> n;

    vii adj(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Graph gr(n, adj);

    ll q; cin >> q;
    while (q--)
    {
        ll k; cin >> k;
        vi nd(k);
        for (int i = 0; i < k; i++)
        {
            cin >> nd[i];
        }
        cout << gr.query(nd) << '\n';
    }
    
}

/**
 * Subtree Queries
 * For each node in a tree, you are given a value. You have to perform two types of queries:
 * 1. Change the value of a node.
 * 2. Find the sum of values of all nodes in the subtree of a node.
 * 
 * Idea to make euler tour so we know Indegree and Outdegree of each node.
 * then we can use Segment tree or Fenwick tree to solve the problem as range query.
*/

class Graph {
public:
    int size;
    vii adj;
    vi Indeg, Outdeg;
    int Timer;

    // each element from [Indeg[n], Outdeg[n]] is a subtree of node n
    void dfs(int n, int p) {
        Indeg[n] = Timer++;
        for (auto neg : adj[n])
            if (neg != p) dfs(neg, n);
        Outdeg[n] = Timer - 1;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Graph(ll n) {
        Timer = 1;
        size = n;
        Indeg.assign(n + 1, 0);
        Outdeg.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


ll rangequery(const vi& Z, int l, int r) {
	ll summ = 0;
	for (int i = r; i > 0; i -= i & -i)
		summ = (summ + Z[i]);
    
    for (int i = l - 1; i > 0; i -= i & -i)
        summ = (summ - Z[i]);

    return summ;
}

void updatepoint(vi& Z, ll n, int at) {
	for (int i = at; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] + n);
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i + 1];
    }
    
    Graph gr(n);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
    }
    
    gr.dfs(1, 0);

    vi BIT(n + 1);
    for (int i = 1; i <= n; i++)
    {
        updatepoint(BIT, X[i], gr.Indeg[i]);
    }
    
    while (q--)
    {
        ll ty; cin >> ty;

        if (ty == 1) {
            ll l, r; cin >> l >> r;
            ll v = r - X[l];
            X[l] = r;
            updatepoint(BIT, v, gr.Indeg[l]);
        } else {
            ll l; cin >> l;
            cout << rangequery(BIT, gr.Indeg[l], gr.Outdeg[l]) << '\n';
        }
    }
}
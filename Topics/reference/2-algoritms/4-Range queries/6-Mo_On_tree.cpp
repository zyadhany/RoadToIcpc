/*
using eular_tour we can queries path of tree with Mo
for eular tour each node is visited 2 times, when we enter and when we exit.
in range to if you found node twice then it'snot in path.

to query path from node u to v, first let u is in tour before v, we have 2 cases:
1- u is ancestor of v, then result is [st[u], st[v]]
2- u is not ancestor of v, then result is [en[u], st[v]] + [lca(u, v)]
*/

class Graph {
public:
    int size, SPSIZE;
    // LCA
	vi Indeg, lvl;
    vp Trav;

	// eular tour
	vi ST, EN, Tour;
    vector<vp> table;

    void dfs( const vii &adj, int n, int p, ll deep) {
        lvl[n] = deep;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        
		ST[n] = Tour.size();
		Tour.push_back(n);
		
		for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(adj, neg, n, deep + 1);
            Trav.push_back({deep, n});
        }

		EN[n] = Tour.size();
		Tour.push_back(n);
    }

    void BuildLCA(const vii &adj) {
        dfs(adj, 1, 0, 1);
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

    Graph(ll n, const vii &adj) {
        size = n;
        lvl.resize(n + 1, 0);
        Indeg.assign(n + 1, 0);
        ST.assign(n + 1, 0);
        EN.assign(n + 1, 0);
        BuildLCA(adj);
    }
};

int block;
struct Query
{
    int L, R, ind, lc;
};
bool compare(Query &x, Query &y)
{
    if (x.L/block != y.L/block)
       return x.L/block < y.L/block;
    if ((x.L/block) & 1) return x.R > y.R;
    return x.R < y.R;
}

void Update(ll &summ, ll ind, vi &X, vi &frqnd, vi &frq) {
    frqnd[ind] ^= 1;
	if (frqnd[ind]) {
		summ += (frq[X[ind]]==0);
		frq[X[ind]]++;
	} else {
		frq[X[ind]]--;
		summ -= (frq[X[ind]]==0);
	}
}

vi MoQueryResult(vector<Query> Q, vi &X, vi &tour)
{
    ll n, m;
 
    n = X.size(), m = Q.size();
    block = (int)sqrt(n);
    vi res(m);
 
    sort(Q.begin(), Q.end(), compare);
 
	vi frqnd(n+1);
	vi frq(n+10);

    ll currL = 0, currR = 0;
    ll currSum = 0;
 
    for (int i = 0; i < m; i++)
    {
        ll L = Q[i].L, R = Q[i].R, ind = Q[i].ind;
 
        while (currL > L) Update(currSum, tour[--currL], X, frqnd, frq);
        while (currR <= R) Update(currSum, tour[currR++], X, frqnd, frq);
        while (currL < L) Update(currSum, tour[currL++], X, frqnd, frq);
        while (currR > R+1) Update(currSum, tour[--currR], X, frqnd, frq);
 
		res[ind] = currSum;
		if (Q[i].lc != -1) res[ind] += (frq[X[Q[i].lc]] == 0);
    }
 
    return (res);
}

void solve(int tc) {
	ll n, q;
	cin >> n >> q;
	
	vi X(n + 1);
	vii adj(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> X[i + 1];
	}

	// compress
	set<ll> st(all(X));
	mi M;
	for (auto a : st) M[a] = M.size();
	for (auto &a : X) a = M[a];

	
	for (int i = 0; i < n-1; i++)
	{
		ll u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	Graph gr(n, adj);

	auto &Z = gr.Tour;

	vector<Query> Q(q);

	for (int i = 0; i < q; i++)
	{
		ll l, r; cin >> l >> r;
		if (gr.ST[l] > gr.ST[r]) swap(l, r);
		ll lc = gr.LCA(l, r);
		if (lc == l) Q[i].L = gr.ST[l], Q[i].R = gr.ST[r], Q[i].lc = -1;
		else Q[i].L = gr.EN[l], Q[i].R = gr.ST[r], Q[i].lc = lc;
		Q[i].ind = i;
	}
	
	auto res = MoQueryResult(Q, X, gr.Tour);
	for (auto a : res) cout << a << '\n';
}

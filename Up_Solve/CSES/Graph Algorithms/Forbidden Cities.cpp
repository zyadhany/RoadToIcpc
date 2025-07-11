#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define vpp vector<vp>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; continue;}
#define NO {cout << "NO\n"; continue;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

vii biconnected_components(vii &g, vi &is_cutpoint, vi &id) {
	int n = (int)g.size();

	vii comps;
	vi stk;
	vi num(n);
	vi low(n);

	is_cutpoint.resize(n);

	// Finds the biconnected components
	function<void(int, int, int &)> dfs = [&](int node, int parent, int &timer) {
		num[node] = low[node] = ++timer;
		stk.push_back(node);
		for (auto son : g[node]) {
			if (son == parent) { continue; }
			if (num[son]) {
				low[node] = min(low[node], num[son]);
			} else {
				dfs(son, node, timer);
				low[node] = min(low[node], low[son]);
				if (low[son] >= num[node]) {
					is_cutpoint[node] = (num[node] > 1 || num[son] > 2);
					comps.push_back({node});
					while (comps.back().back() != son) {
						comps.back().push_back(stk.back());
						stk.pop_back();
					}
				}
			}
		}
	};

	int timer = 0;
	dfs(0, -1, timer);
	id.resize(n);

	// Build the block-cut tree
	function<vii()> build_tree = [&]() {
		vii t(1);
		int node_id = 0;
		for (int node = 0; node < n; node++) {
			if (is_cutpoint[node]) {
				id[node] = node_id++;
				t.push_back({});
			}
		}

		for (auto &comp : comps) {
			int node = node_id++;
			t.push_back({});
			for (int u : comp)
				if (!is_cutpoint[u]) {
					id[u] = node;
				} else {
					t[node].push_back(id[u]);
					t[id[u]].push_back(node);
				}
		}
		return t;
	};

	return build_tree();
}

class Graph {
public:
    int size;
    vi vis, lvl;
    vii adj, SPT;


    void BuildSparse(ll node=1, ll parent=0){
        lvl[node] = lvl[parent] + 1;
        SPT[node][0] = parent;
        for (int i = 1; i < SPT[node].size(); i++)
            SPT[node][i] = SPT[SPT[node][i - 1]][i - 1];        
        for (auto neg : adj[node])
            if (neg != parent) BuildSparse(neg, node);
    }

    ll getKth(ll u, ll k){
        for (int i = 0; i < SPT[u].size(); i++)
            if ((1 << i) & k) u = SPT[u][i];
        return (u);
    }

    ll LCA(ll u, ll v) {
        if (lvl[u] > lvl[v]) swap(u, v);
        v = getKth(v, lvl[v] - lvl[u]);
        if (u == v) return (u);
        for (int i = SPT[u].size() - 1; i >= 0; i--)
        {
            if (SPT[u][i] != SPT[v][i]){
                u = SPT[u][i], v = SPT[v][i];
            }
        }
        return (SPT[u][0]);
    }

    ll dist(ll u, ll v) {
        ll p = LCA(u , v);
        return (lvl[u] + lvl[v] - 2 * lvl[p]);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n, vii &adj) : adj(adj) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        SPT.resize(n + 1, vi(ceil(log2(n + 1)) + 1));
		BuildSparse(0, 0);
    }
};


void solve(int tc) {
	ll n, m, q;
	cin >> n >> m >> q;

	vii adj(n);
	for (int i = 0; i < m; i++)
	{
		ll u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vi cut(n), id(n);
	adj = biconnected_components(adj, cut, id);
	
	
	Graph gr(n*2, adj);
	while (q--)
	{
		ll u, v, c;
		cin >> u >> v >> c;

		u--, v--, c--;
		if (u == c || v == c) NO;
		if (!cut[c]) YES;
		u = id[u];
		v = id[v];
		c = id[c];

		ll lc = gr.LCA(u, v);
		int lca = gr.LCA(u, v);
		int lca1 = gr.LCA(u, c);
		int lca2 = gr.LCA(v, c);

		if (lca == c || (lca1 == lca && lca2 == c) || (lca2 == lca && lca1 == c)) {
			NO;
		}

		YES;
	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

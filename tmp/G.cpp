#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

using namespace std;

const int MODE = 1e9 + 7;
const int MAXX = (1 << 30) - 1;


typedef long long item;
/*
struct item
{
	int val;

	item(){
		val = 0;
	}
};
*/

class DSU
{
public:

	item val(int n) {
		return(op[get(n)]);
	}

	int get(int n) {
		if (P[n] == n) return (n);
		return (P[n] = get(P[n]));
	}

	void add(int l, int r) {
		int a, b;
		a = get(l), b = get(r);

		if (a == b) return;

		if (R[a] == R[b])
			R[a]++;
		else if (R[a] < R[b])
			swap(a, b);

		P[b] = a;
		marge(op[a], op[b]);
	}

	void build(int n) {
		P.assign(n + 1, 0);
		R.assign(n + 1, 0);
		op.assign(n + 1, item());

		for (int i = 0; i <= n; i++)
			P[i] = i;
	}
private:
	vector<int> P, R;
	vector<item> op;

	void marge(item &a, item &b) {
		/*any oppration you want*/
	}
};


vii spanningTree(vii X, ll n)
{
    ll a, b, summ = 0;
    sort(X.begin(), X.end());

    vii Z;
    DSU ds;
    ds.build(n);

    for (int i = 0; i < X.size(); i++)
    {
        a = ds.get(X[i][1]);
        b = ds.get(X[i][2]);

        if (a != b)
        {
            ds.add(a, b);
            Z.push_back(X[i]);
        }
    }

    return (Z);
}

class Graph {
public:
    typedef ll item;
    
    int size;
    vi vis, lvl;
    vector<vector<pair<ll, item>>> adj, SPT;

    item SPTMarge(item &a, item &b){
        return (a | b);
    }

    void BuildSparse(ll node, ll parent, ll w){
        vis[node] = 1;
        lvl[node] = lvl[parent] + 1;
        SPT[node][0] = {parent, w};
        for (int i = 1; i < SPT[node].size(); i++){
            int tmp = SPT[node][i - 1].first;
            SPT[node][i].first = SPT[tmp][i - 1].first;
            SPT[node][i].second = SPTMarge(SPT[node][i - 1].second, SPT[tmp][i - 1].second);
        }
        for (auto neg : adj[node])
            if (neg.first != parent) BuildSparse(neg.first, node, neg.second);
    }

    pair<ll, item> getKth(ll u, ll k){
        item res = 0;
        for (int i = 0; i < SPT[u].size(); i++)
            if ((1 << i) & k) {
                res = SPTMarge(res, SPT[u][i].second);
                u = SPT[u][i].first;
            }
        return {u, res};
    }

    ll LCA(ll u, ll v) {
        if (lvl[u] > lvl[v]) swap(u, v);
        v = getKth(v, lvl[v] - lvl[u]).first;
        if (u == v) return (u);
        for (int i = SPT[u].size() - 1; i >= 0; i--)
        {
            if (SPT[u][i].first != SPT[v][i].first){
                u = SPT[u][i].first, v = SPT[v][i].first;
            }
        }
        return (SPT[u][0].first);
    }

    ll dist(ll u, ll v) {
        ll p = LCA(u , v);
        ll a, b;
        a = getKth(u, lvl[u] - lvl[p]).second;
        b = getKth(v, lvl[v] - lvl[p]).second;
 
        return (SPTMarge(a, b));
    }

    void addEdge(int u, int v, item w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
        SPT.resize(n + 1, vector<pair<ll, item>>(ceil(log2(n + 1)) + 1));
    }
};


void solve(ll tc) {
    ll n, m, q;

    cin >> n >> m;

    vii Z(m, vi(3));

    for (int i = 0; i < m; i++)
        cin >> Z[i][1] >> Z[i][2] >> Z[i][0];

    Z = spanningTree(Z, n);
    Graph gr(n);
    for (int i = 0; i < Z.size(); i++)
    {
        gr.addEdge(Z[i][1], Z[i][2], Z[i][0]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (gr.vis[i]) continue;
        gr.BuildSparse(i, 0, 0);
    }
    
    cin >> q;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << gr.dist(l, r) << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

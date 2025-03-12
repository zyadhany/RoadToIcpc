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
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
 
const int MODE = 1e9 + 7;
 
 
using namespace std;
 
 
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

 
 
ll rangequery(const vi& Z, ll ind) {
	ll summ = 0;
	for (int i = ind; i > 0; i -= i & -i)
		summ = (summ ^ Z[i]);
    return summ;
}
 
void updaterange(vi& Z, ll val, int l, ll r) {
	for (int i = l; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] ^ val);
    
    for (int i = r+1; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] ^ val);
}
 
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
        gr.adj[u].push_back(v);
    }
    
    gr.BuildLCA();
    vi X(n + 10);
    for (int i = 1; i <= n; i++)
    {
        X[gr.ST[i]] = gr.X[i];
    }
    
    vi BIT(n + 10);
    for (int i = 1; i <= n; i++)
    {
        updaterange(BIT, X[i], i, i);
    }
    
    while (q--)
    {
        ll ty; cin >> ty;
        
        if (ty == 1) {
            ll nd, v;
            cin >> nd >> v;
            ll diff = v ^ VAL[nd];
            VAL[nd] = v;
            updaterange(BIT, diff, gr.ST[nd], gr.Outdeg[nd]);
        } else {
            ll u, v; cin >> u >> v;
            ll a = rangequery(BIT, gr.ST[u]);
            ll b = rangequery(BIT, gr.ST[v]);
            ll lc = gr.LCA(u, v);
            ll re = (a ^ b ^ VAL[lc]);
            cout << re << '\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
<<<<<<< HEAD

    // freopen("hopscotch.in", "r", stdin);
    // freopen("hopscotch.out", "w", stdout);

    cin >> size;
=======
 
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
 
    // cin >> size;
>>>>>>> 26b5ceed95a7c2fe39b3c1aa81e0abf76a3f110d
    for (int i = 1; i <= size; i++)
        solve(i);
}
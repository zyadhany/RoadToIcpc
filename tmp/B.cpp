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
<<<<<<< HEAD


using namespace std;

class Graph {
public:
    typedef ll item;
    
    int size;
    vi vis, lvl;
    vector<vector<pair<ll, item>>> adj, SPT;

    item SPTMarge(item &a, item &b){
        return min(a, b);
    }

    void BuildSparse(ll node, ll parent, ll w){
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
        item res = INT32_MAX;
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
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
        SPT.resize(n + 1, vector<pair<ll, item>>(ceil(log2(n + 1)) + 1));
    }
};

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void solve(int tc) {
    ll n, q;
    
    
    cin >> n >> q;

    vi X(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i + 1];
    }
    
    for (int i = 1; i <= n; i++)
    {
        ll a = X[i];
        if (a <= 2) {
            X[i] = 2 - a;
            continue;
        }

        ll r, l;
        for (r=a; !isPrime(r); r++);
        for (l=a; !isPrime(l); l--);
        X[i] = min(r-a, a-l);
    }
    

    Graph gr(n);

    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v, X[v]);
        gr.addEdge(v, u, X[u]);
    }
    
    gr.BuildSparse(1, 0, 0);

    while (q--)
    {
        ll u, v; cin >> u >> v;
        ll re = gr.dist(u, v);
        ll lc = gr.LCA(u, v);
        re += X[lc];
        cout << re << '\n';
    }

}
=======
 
 
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
        Outdeg[n] = timer;
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
    ll n, m;

    cin >> n >> m;

    ll sol = 0;
    for (int i = 0; i < 2; i++)
    {
        ll k; cin >> k;
        ll mn = INT32_MAX, mx = INT32_MIN;
        for (int j = 0; j < k; j++)
        {
            ll a; cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        sol = max(sol, (mx - mn) * m);
    }

>>>>>>> 26b5ceed95a7c2fe39b3c1aa81e0abf76a3f110d

    for (int i = 0; i < 2; i++)
    {
        ll k; cin >> k;
        ll mn = INT32_MAX, mx = INT32_MIN;
        for (int j = 0; j < k; j++)
        {
            ll a; cin >> a;
            mn = min(mn, a);
            mx = max(mx, a);
        }
        sol = max(sol, (mx - mn) * n);
    }
    
    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
<<<<<<< HEAD

    // freopen("hopscotch.in", "r", stdin);
    // freopen("hopscotch.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
=======
 
    // freopen("cowland.in", "r", stdin);
    // freopen("cowland.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
>>>>>>> 26b5ceed95a7c2fe39b3c1aa81e0abf76a3f110d

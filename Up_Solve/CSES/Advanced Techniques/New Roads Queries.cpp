#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 1e9+7;
const ll INF = 1e16;
const int MXN = 2e5+1;
 
int par[MXN], res[MXN];
int RAN[MXN];
 
ll get(ll k) {
    if (k == par[k]) return k;
    return par[k] = get(par[k]);
}
 
void add(ll u, ll v) {
    u = get(u), v = get(v);
    if (u == v) return;
    if (RAN[u] < RAN[v]) swap(u, v);
    if (RAN[u] == RAN[v]) RAN[u]++;
    par[v] = u;    
}
 
void INIT() {
    for (int i = 0; i < MXN; i++) {
        par[i] = i;
        RAN[i] = 0;
    } 
}
 
struct edge {
    ll u, v, w;
    edge(){}
    edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
    bool operator<(edge &e) {
        return w < e.w;
    }
};
 
// return edge list of MST, if MST doesn't exist return empty list
vector<edge> MST_Kruskal(vector<edge> E) {
    vector<edge> TOK;
    sortx(E);
 
    for (auto e : E) {
        if (get(e.u) != get(e.v)) {
            add(e.u, e.v);
            TOK.push_back(e);
        }
    }
 
    return TOK;
}
 
class Graph {
public:
    typedef ll item;
    
    int size;
    vi vis, lvl;
    vector<vector<pair<ll, item>>> adj, SPT;
 
    item SPTMarge(item &a, item &b){
        return max(a, b);
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
        item res = item();
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
 
    item dist(ll u, ll v) {
        ll p = LCA(u , v);
        item a, b;
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
 
    cin >> n >> m >> q;
 
    INIT();
    vector<edge> E(m);
    for (int i = 0; i < m; i++)
    {
        cin >> E[i].u >> E[i].v;
        E[i].w = i + 1;
    }
    
    E = MST_Kruskal(E);
 
    Graph gr(n);
    for (auto e : E) gr.addEdge(e.u, e.v, e.w);
 
    for (int i = 1; i <= n; i++)
    {
        if (i == get(i)) {
            gr.BuildSparse(i, 0, 0);
        }
    }
    
    
    while (q--)
    {
        ll l, r; cin >> l >> r;
        if (get(l) != get(r)) {cout << "-1\n"; continue;}
        cout << gr.dist(l, r) << '\n';
    }
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   
 
    // freopen("subrev.in", "r", stdin   );
    // freopen("subrev.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

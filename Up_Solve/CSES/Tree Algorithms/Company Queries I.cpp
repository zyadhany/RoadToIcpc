#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
using namespace std;
 
const int MODE = 998244353;
 
class Graph {
public:
    int size;
    vi vis, lvl;
    vii adj, SPT;


    void BuildSparse(ll node, ll parent){
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

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
        SPT.resize(n + 1, vi(ceil(log2(n + 1)) + 1));
    }
};


void solve(ll tc) {
    ll n, q;

    cin >> n >> q;
    Graph gr(n);

    for (int i = 2; i <= n; i++)
    {
        ll a; cin >> a;
        gr.addEdge(a, i);
    }
    gr.BuildSparse(1, 0);

    while (q--)
    {
        ll u, k; cin >> u >> k;
        ll p = gr.getKth(u, k);
        if (p) cout << p << '\n';
        else cout << "-1\n";
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

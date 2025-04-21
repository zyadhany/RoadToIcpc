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
const int MXN = 5e4+1;
 
void req(vii &adj, vector<bitset<MXN>> &bt, vi &vis, ll n) {
    if (vis[n]) return;
    vis[n] = 1;
    bt[n][n] = 1;
    for (auto neg: adj[n]) {
        req(adj, bt, vis, neg);
        bt[n] |= bt[neg];
    }
}
 
void solve(ll tc) {
    ll n, m;
 
    cin >> n >> m;
 
    vii adj(n + 1);
 
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >>u >> v;
        adj[u].push_back(v);
    }
    
    vi vis(n + 1);
    vector<bitset<MXN>> bt(n + 1);
 
    for (int i = 1; i <= n; i++)
        req(adj, bt, vis, i);
    
    for (int i = 1; i <= n; i++) cout << bt[i].count() << ' ';
    cout << '\n'; 
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   
 
    // freopen("triangles.in", "r", stdin   );
    // freopen("triangles.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

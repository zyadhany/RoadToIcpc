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
 
ll sol = 0, k;
const int MXN = 2e5+10;
int par[MXN], sz[MXN], cdprc[MXN], frq[MXN];
int mxhight;
 
vector<int> adj[MXN];
    
int dfs(int u, int p) {
    sz[u] = 1;
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg]) sz[u] += dfs(neg, u);
    return sz[u];
}
 
int centriod(int u, int p, int n) {
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg] && sz[neg] > n/2) 
    return centriod(neg, u, n);
    return u;
}
 
void dfsfill(int u, int p, int high, int v) {
    frq[high]+=v;
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg]) dfsfill(neg, u, high+1, v);
}
void dfsres(int u, int p, int high) {
    mxhight = max(mxhight, high);
    if (high > k) return;
    sol += frq[k-high];
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg]) dfsres(neg, u, high + 1);
}
 
void build(int u, int p) {
    int cen = centriod(u, p, dfs(u, p));
    if (!p) p = cen;
    par[cen] = p, cdprc[cen] = 1;
 
    mxhight = 0;
    frq[0] = 1;
    for (auto neg : adj[cen]) if (!cdprc[neg]) {
        dfsres(neg, cen, 1);
        dfsfill(neg, cen, 1, 1);
    }
    fill(frq+1, frq+1+mxhight, 0);
    // for (auto neg : adj[cen]) if (!cdprc[neg]) {
    //     dfsfill(neg, cen, 1, -1);
    // }
 
    for (auto neg : adj[cen]) if (!cdprc[neg]) build(neg, cen);
}
 
 
void solve(ll tc) {
    ll n;
 
    cin >> n >> k;
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    frq[0] = 0;
    build(1, 0);
    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

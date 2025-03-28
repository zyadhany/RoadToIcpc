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
 
ll sol = 0;
int k1, k2;
const int MXN = 2e5+10;
int par[MXN], sz[MXN], cdprc[MXN], frq[MXN];
int subhight;
 
vector<int> adj[MXN];
 
 
long long BIT[MXN];
int rangequery(int l=k1, int r=k2) {
	int summ = 0;
	for (int i = r+1; i > 0; i -= i & -i)
		summ += BIT[i];
	for (int i = l; i > 0; i -= i & -i)
		summ -= BIT[i];
	return summ;
}
 
void updatepoint(int at, int v) {
	for (int i = at+1; i < MXN; i += i & -i)
		BIT[i]+=v;
}
void reset(int n) {
	for (int i = n+1; i < MXN; i += i & -i)
		BIT[i]=0;
}
 
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
 
void dfsfill(int u, int p, int high) {
    if (high > k2) return;
    subhight = max(subhight, high);
    frq[high]++;
    for (auto neg : adj[u]) if (neg != p && !cdprc[neg]) dfsfill(neg, u, high+1);
}
 
void build(int u, int p) {
    int cen = centriod(u, p, dfs(u, p));
    if (!p) p = cen;
    par[cen] = p, cdprc[cen] = 1;
    
    updatepoint(0, 1);
    int mxhight = 0;
    for (auto neg : adj[cen]) if (!cdprc[neg]) {
        subhight = 0;
        dfsfill(neg, cen, 1);
        for (int i = 1; i <= subhight; i++) {
            sol += 1ll * rangequery(max(0, k1 - i), k2-i) * frq[i];
        }
        for (int i = 1; i <= subhight; i++) {
            updatepoint(i, frq[i]);
            frq[i] = 0;
        }
        mxhight = max(mxhight, subhight);
    }
    for (int i = 0; i <= mxhight; i++)
        reset(i);
    for (auto neg : adj[cen]) if (!cdprc[neg]) build(neg, cen);
}
 
 
void solve(ll tc) {
    ll n;
 
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
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
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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
 
const int MODE = 1e9+7;

const int N = 1e5+100;
ll lvl[N]{}, vis[N]{};
ll spt[N][18];
vi adj[N];
ll timer = 1;
ll in[N], out[N];

void dfs(ll n, ll p) {
    in[n] = timer++;
    lvl[n] = lvl[p]+1;
    spt[n][0] = p;
    for (int j = 1; j < 18; j++)
        spt[n][j] = spt[spt[n][j-1]][j-1];     
    for (auto neg : adj[n]) if (neg != p) {
        dfs(neg, n);   
    }
    out[n] = timer;
}

ll kth(ll u, ll k) {
    for (int i = 0; i < 18; i++)
        if (k & (1<<i)) u = spt[u][i];    
    return u;
}

ll lca(ll u , ll v) {
    if (lvl[u] < lvl[v]) swap(u, v);
    u = kth(u, lvl[u]-lvl[v]);
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (spt[u][i] != spt[v][i]) u = spt[u][i], v = spt[v][i];        
    return spt[u][0];
}

bool cyc = 0;
void dfs2(vii &adj, vi &vis, ll n) {
    if (vis[n] == 1)return;
    if (vis[n] == 2) {
        cyc = 1;
        return;
    }
    vis[n] = 2;
    for (auto neg : adj[n]) dfs2(adj, vis, neg);
    vis[n] = 1;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    vii adj(n+1);

    vi prf(timer+10, 0);
    while (m--)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        ll lc = lca(u, v);
        if (lc != u) prf[in[u]]++, prf[out[u]]--;
        else {
            ll imd = kth(v, lvl[v]-lvl[u]-1);
            prf[0]++;
            prf[in[imd]]--;
            prf[out[imd]]++;
        }
    }

    vi vis(n+1);
    for (int i = 1; i <= n; i++)
        dfs2(adj, vis, i);    
    if (cyc) {
        for (int i = 0; i < n; i++)
        {
            cout << 0 << '\n';
        }
        return;
    }

    ll p = prf[0];
    for (int i = 1; i < prf.size(); i++)
    {
        p += prf[i];
        if (p) prf[i] = 0;
        else prf[i] = 1;
    }

    for (int i = 1; i <= n; i++)
        cout << prf[in[i]] << '\n';    
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	freopen("gathering.in", "r", stdin);
    freopen("gathering.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
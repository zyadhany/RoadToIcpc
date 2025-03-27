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

const int MXN = 2e5+10;


int sgsize;
ll sgtree[MXN * 4];

void update(int idx, int val) {
    sgtree[idx += sgsize] = val;
    for (idx /= 2; idx; idx /= 2) sgtree[idx] = max(sgtree[2 * idx], sgtree[2 * idx + 1]);
}

ll query(int lo, int hi) {
    ll ra = 0, rb = 0;
    for (lo += sgsize, hi += sgsize + 1; lo < hi; lo /= 2, hi /= 2) {
        if (lo & 1) ra = max(ra, sgtree[lo++]);
        if (hi & 1) rb = max(rb, sgtree[--hi]);
    }
    return max(ra, rb);
}

void build(vi &X) {
    sgsize = X.size();
    for (int i = 0; i < sgsize; i++) sgtree[i + sgsize] = X[i];
    for (int i = sgsize - 1; i > 0; i--) sgtree[i] = max(sgtree[2 * i], sgtree[2 * i + 1]);
}

struct HLD {
    int size, timer;
    vi lvl, par, heavy, head, indeg, sz;
    vii adj;
 
    void dfs(int u, int p) {
        par[u] = p;
        sz[u] = 1;
        for (int v : adj[u]) if (v != p) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
            if (!heavy[u] || sz[v] > sz[heavy[u]]) heavy[u] = v;
        }
    }
    
    void decompose(int u, int p){
        indeg[u] = timer++;
        if (heavy[u]) {
            head[heavy[u]] = head[u];
            decompose(heavy[u], u);
        }
        for (int v : adj[u]) if (v != p && v != heavy[u]) {
            head[v] = v;
            decompose(v, u);
        }
    }
 
    HLD(int n, vii &adj) : size(n), lvl(n+1), par(n+1), heavy(n+1), head(n+1), indeg(n+1), adj(adj), sz(n+1) {
        dfs(1, 0);
        timer = 1;
        head[1] = 1;
        decompose(1, 0);
    }
 
    vp get_path(int u, int v) {
        vp path;
        while (head[u] != head[v]) {
            if (lvl[head[u]] < lvl[head[v]]) swap(u, v);
            path.push_back({indeg[head[u]], indeg[u]});
            u = par[head[u]];
        }
        if (lvl[u] > lvl[v]) swap(u, v);
        // u is lca between u and v
        path.push_back({indeg[u], indeg[v]});
        return path;
    }
};


void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> X[i];
    }
    
    vii adj(n + 1);

    for (int i = 0; i < n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    HLD hld(n, adj);

    vi Z(n + 1);
    for (int i = 1; i <= n; i++)
    {
        Z[hld.indeg[i]] = X[i];
    }
    
    build(Z);

    while (q--)
    {
        ll ty; cin >> ty;
        if (ty == 1) {
            ll nd, k; cin >> nd >> k;
            update(hld.indeg[nd], k);
        } else {
            ll u, v; cin >> u >> v;
            cout << hld.get_path(u, v) << ' ';
        }
    }
    
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

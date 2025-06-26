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

// Heavy Light Decomposition
struct HLD {
    int size, timer;
    vi lvl, par, heavy, head, in, sz;
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
        in[u] = timer++;
        if (heavy[u]) {
            head[heavy[u]] = head[u];
            decompose(heavy[u], u);
        }
        for (int v : adj[u]) if (v != p && v != heavy[u]) {
            head[v] = v;
            decompose(v, u);
        }
    }
 
    HLD(int n, vii &adj) : size(n), lvl(n+1), par(n+1), heavy(n+1), head(n+1), in(n+1), adj(adj), sz(n+1) {
        dfs(1, 0);
        timer = 1;
        head[1] = 1;
        decompose(1, 0);
    }
 
    vp get_path(int u, int v) {
        vp path;
        while (head[u] != head[v]) {
            if (lvl[head[u]] < lvl[head[v]]) swap(u, v);
            // if cost in edges not node let in[head[u]] + 1. and edge cost get down to child node.
            path.push_back({in[head[u]], in[u]});
            u = par[head[u]];
        }
        if (lvl[u] > lvl[v]) swap(u, v);
        // u is lca between u and v
        if (u != v)
        path.push_back({in[u]+1, in[v]});
        return path;
    }
};


const int MXN = 1e5+10;
ll B1[MXN]{}, B2[MXN]{};

void add(ll *b, int idx, long long x) {
    for (; idx < MXN; idx += idx & -idx)
        b[idx] += x;
}

long long sum(const ll *b, int idx) {
    long long total = 0;
    for (; idx > 0; idx -= idx & -idx)
        total += b[idx];
    return total;
}

void range_add(int l, int r, long long x) {
    add(B1, l, x);
    add(B1, r + 1, -x);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, -x * r);
}

long long prefix_sum(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
}

long long range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}


void solve(int tc) {
    ll n, q;
    
    cin >> n >> q;

    vii adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    HLD hl(n, adj);

    while (q--)
    {
        char c;
        ll u, v;
        cin >> c >> u >> v;
        
        auto Z = hl.get_path(u, v);
        ll summ = 0;
        for (auto [l, r] : Z) {
            if (c == 'P') range_add(l, r, 1);
            else summ += range_sum(l, r);
        }
        if (c == 'Q') cout << summ << '\n'; 
    }    
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	freopen("grassplant.in", "r", stdin);
    freopen("grassplant.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

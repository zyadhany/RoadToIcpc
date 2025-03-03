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


struct graph {
    ll n;
    vector<vp>adj;
    vi vis;

    void addedge(ll u, ll v, ll w) {
        adj[u].push_back({v, w});
    }
    
    bool DFS(vi &X, int u) {
        if (vis[u] == 1) return 1;
        if (vis[u] == -1) return 0;
        vis[u] = -1;
    
        for (auto v : adj[u])
            if (!DFS(X, v.first)) return 0;
    
        X.push_back(u);
        vis[u] = 1;
        return 1;
    }
    
    vi TopologicalSort() {
        vi X, vis(n + 1);
        for (int i = 1; i <= n; i++) 
            if (!DFS(X, i)) return vi();
        reverse(all(X));
        return (X);
    }

    vi getsol(vi &X) {
        auto tps = TopologicalSort();
        vector<ll> dp(n + 1);
        for (auto u : tps) {
            dp[u] = max(dp[u], X[u]);
            for (auto [v, w] : adj[u]) {
                dp[v] = max(dp[v], dp[u]+w);
            }
        }

        return dp;
    }

    graph(ll n) {
        this->n = n;
        adj.assign(n + 1, vp());
        vis.assign(n + 1, 0);
    }
};


void solve(int tc) {
    ll n, k, m;

    cin >> n >> k >> m;

    vi X(n + 1);
    graph g1(n);

    for (int i = 1; i <= n; i++)
    {
        cin  >> X[i];
    }
    

    for (int i = 0; i < m; i++)
    {
        ll u, v , w;
        cin >> u >> v>> w;
        g1.addedge(u, v, w);
    }
    
    auto sol = g1.getsol(X);
    for (int i = 1; i <= n; i++) cout << sol[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

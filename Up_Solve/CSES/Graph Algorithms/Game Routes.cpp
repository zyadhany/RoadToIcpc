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

bool DFS(vii &adj, vi &vis, vi &X, int u) {
    if (vis[u] == 1) return 1;
    if (vis[u] == -1) return 0;
    vis[u] = -1;

    for (auto v : adj[u])
        if (!DFS(adj, vis, X, v)) return 0;

    X.push_back(u);
    vis[u] = 1;
    return 1;
}

vi TopologicalSort(vii &adj) {
    vi X, vis(adj.size());
    for (int i = 1; i < adj.size(); i++) 
        if (!DFS(adj, vis, X, i)) return vi();
    reverse(all(X));
    return (X);
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vi tpso = TopologicalSort(adj);
    reverse(all(tpso));
    vi dp(n + 1);
    dp[n] = 1;

    for (auto u : tpso) {
        for (auto v : adj[u]) dp[u] += dp[v];
        dp[u] %= MODE;
    }

    cout << dp[1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("tractor.in", "r", stdin);
    // freopen("tractor.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

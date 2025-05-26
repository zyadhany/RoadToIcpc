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
using namespace std;

void dfs(vector<vp> &adj, vi &eular, vi &vis, ll n) {
    while (!adj[n].empty())
    {
        auto [neg, ind] = adj[n].back();
        adj[n].pop_back();
        if (vis[ind]) continue;
        vis[ind] = 1;
        dfs(adj, eular, vis, neg);
    }
    eular.push_back(n);
}

void solve(int tc) {
    ll n, m;
    cin >> n >> m;

    vector<vp> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    
    ll cntod = 0;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() % 2) cntod++;

    if (cntod) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vi eurlcirc, vis(m);
    vector<vp> tmadj(adj);
    dfs(tmadj, eurlcirc, vis, 1);

    if (eurlcirc.size() != m+1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (auto a : eurlcirc) cout << a << ' ';
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("snowcow.in", "r", stdin);
    // freopen("snowcow.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

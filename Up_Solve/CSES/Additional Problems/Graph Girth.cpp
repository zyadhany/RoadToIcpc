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

const int MODE = 998244353;

using namespace std;

ll req(vii &adj, ll src) {
    ll res = INT32_MAX;
    vi vis(adj.size(), -1);
    vi par(adj.size(), -1);
    queue<ll> que;
    que.push(src);
    vis[src] = 0;
    while (!que.empty())
    {
        ll tp = que.front();
        que.pop();

        for (auto neg : adj[tp]) {
            if (neg == par[tp]) continue;
            if (vis[neg] == -1) {
                vis[neg] = vis[tp]+1;
                par[neg] = tp;
                que.push(neg);
            } else {
                res = min(res, vis[neg] + vis[tp] + 1);
            }
        }
    }

    return res;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    ll res = INT32_MAX;
    for (int i = 0; i < n; i++)
        res = min(res, req(adj, i + 1));
    
    if (res == INT32_MAX) cout << "-1\n";
    else cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("piggyback.in", "r", stdin);
    // freopen("piggyback.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

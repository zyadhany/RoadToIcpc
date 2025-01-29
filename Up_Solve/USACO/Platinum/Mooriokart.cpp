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

const int MODE = 1e9 + 7;

void dfs(vector<vp> &adj, vi &vis, vi &X, ll n) {
    if (vis[n]) return;
    X.push_back(n);
    vis[n] = 1;
    for (auto [neg, w] : adj[n]) dfs(adj, vis, X, neg);
}

void req(vector<vp> &adj, vi &X, ll n, ll p, ll k, ll st) {
    if (n > st) X.push_back(k);
    for (auto [neg, w] : adj[n]) if (neg != p)
        req(adj, X, neg, n, k + w, st);
}

void solve(int tc) {
    ll n, m, x, y;

    cin >> n >> m >> x >> y;

    vector<vp> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vi vis(n + 1);
    vii comp;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vi X;
        dfs(adj, vis, X, i);
        sortx(X);
        comp.push_back(X);
    }
    
    ll k = comp.size();
    y = max(0ll, y - k*x);

    vii Y(k);
    for (int i = 0; i < k; i++)
    {
        for (auto a : comp[i]) req(adj, Y[i], a, 0, 0, a);
        sortx(Y[i]);
    }
    
    ll sol = 0;
    ll cnt = 0;
    vi dp(y);
    if (y) dp[0] = 1;
    else cnt = 1, sol = x * k;

    for (auto &X: Y) {
        ll summ = 0;
        for (auto a : X) summ += a;
        sol = (sol * X.size()) % MODE;
        sol = (sol + cnt * summ) % MODE;
        cnt = (cnt * X.size()) % MODE;
        vi Z(y);
        for (int i = y - 1; i >= 0; i--)
        {
            for (auto a : X) {
                if (a + i >= y) {
                    cnt = (cnt + dp[i]) % MODE;
                    sol = (sol + (a + i + x * k) * dp[i]) % MODE;
                } else Z[i + a] = (Z[i + a] + dp[i]) % MODE;
            }
        }
        swap(Z, dp);
    }

    for (ll i = 1; i <= k - 1; i++) sol = (sol * i * 2) % MODE;
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("mooriokart.in", "r", stdin);
    freopen("mooriokart.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

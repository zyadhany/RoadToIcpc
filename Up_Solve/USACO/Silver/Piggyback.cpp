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

vi req(vii &adj, ll src) {
    vi Z(adj.size(), INT32_MAX);
    queue<ll> que;
    que.push(src);
    Z[src] = 0;

    while (!que.empty())
    {
        ll tp = que.front();
        que.pop();
        for (auto neg : adj[tp]) {
            if (Z[neg] > Z[tp] + 1) {
                Z[neg] = Z[tp] + 1;
                que.push(neg);
            }
        }
    }

    return Z;
}

void solve(int tc) {
    ll n, m, a, b, c;
    cin >> a >> b >> c >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    auto X = req(adj, 1);
    auto Y = req(adj, 2);
    auto Z = req(adj, n);

    ll res = INT64_MAX;
    for (int i = 1; i <= n; i++)
        res = min(res, X[i]*a+Y[i]*b+Z[i]*c);
    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

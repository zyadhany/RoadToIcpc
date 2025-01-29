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

const int MODE = 998244353;

ll req(vii &adj, vii &dp, vi &X, ll n, ll d) {
    if (d == dp[0].size() - 1) return (INT32_MIN * (n != 1));
    ll &res = dp[n][d];
    if (res != -1) return res;
    res = INT32_MIN;
    for (auto neg : adj[n]) res = max(res, req(adj, dp, X, neg, d + 1));
    res += X[n];
    return res;
}

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vi X(n + 1);
    vii dp(n + 1, vi(1001, -1));
    vii adj(n + 1);
    
    for (int i = 0; i < n; i++)
        cin >> X[i + 1];
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    ll mx = 0;
    for (int i = 0; i <= 1000; i++)
        mx = max(mx, req(adj, dp, X, 1, i) - k * (1000 - i) * (1000 - i));    
    cout << mx  << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

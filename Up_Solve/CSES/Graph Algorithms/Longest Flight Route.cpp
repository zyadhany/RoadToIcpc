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

ll dfs(vii &adj, vi &dp, vi &P, ll n) {
    ll &res = dp[n];
    if (res != -1) return res;
    res = INT32_MIN;

    for (auto neg:adj[n]) {
        ll re = dfs(adj, dp, P, neg);
        if (re > res) res = re, P[n] = neg;
    }

    if (res != INT32_MIN) res++;
    return res;
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
    
    vi P(n + 1, -1);
    vi dp(n + 1, -1);
    dp[n] = 1;
    dfs(adj, dp, P, 1);
    if (P[1] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vi sol;
    ll at = 1;
    while (at != -1)
    {
        sol.push_back(at);
        at = P[at];
    }
    cout << sol.size() << '\n';
    for (auto a : sol) cout << a << ' ';
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

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


ll req(vii &adj, vii &dp, ll n, ll p, ll ty) {
    ll &res = dp[n][ty];
    if (res != -1) return res;
    res = 0;
    
    if (ty == 0) {
        ll summ = req(adj, dp, n, p, 1);
        res = summ;
        for (auto neg : adj[n]) if (neg != p) {
            ll re = summ - req(adj, dp, neg, n, 0) + 1 + req(adj, dp, neg, n, 1);
            res = max(re, res);
        }
    } else {
        for (auto neg : adj[n]) if (neg != p)
            res += req(adj, dp, neg, n, 0);
    }

    return res;
}

void solve(int tc) {
    ll n; cin >> n;

    vii adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vii dp(n + 1, vi(2, -1));

    cout << req(adj, dp, n, 0, 0) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("cowland.in", "r", stdin);
    // freopen("cowland.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

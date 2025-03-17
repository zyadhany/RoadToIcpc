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
    res = 1;

    for (auto neg : adj[n]) if (neg != p) {
        ll re = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != ty) {
                re += req(adj, dp, neg, n, i);
            }
        }
        res *= re;
        res %= MODE;
    }
    
    return res;
}

void solve(int tc) {
    ll n, k; cin >> n >> k;
    
    vii adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vii dp(n + 1, vi(3, -1));
    for (int i = 0; i < k; i++)
    {
        ll ind, col; cin >> ind >> col;
        col--;
        for (int j = 0; j < 3; j++)
        {
            if (j != col) dp[ind][j] = 0;
        }
    }
    
    ll res = 0;
    for (int i = 0; i < 3; i++)
    {
        res = (res + req(adj, dp, 1, 0, i)) % MODE;
    }
    
    cout << res << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

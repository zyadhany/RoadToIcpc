// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

const int MODE = 1e9+7;
const int MOD2 = (MODE + 1) / 2;
using namespace std;


void solve(int tc) {
    ll n;

    cin >> n;

    vii adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vi dp(n+1), C(n+1), dp2(n+1);
    ll sol = 0;

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        ll mx = 0;
        for (auto neg : adj[u]) if(neg != p) {
            dfs(neg, u);
            C[u] += C[neg];
            mx = max(mx, dp[neg]);
        }
        dp[u] = mx+C[u];
    };
    dfs(1, 0);

    function<void(ll, ll, ll)> dfs2 = [&](ll u, ll p, ll tp) {
        pl mx = {tp, 0};
        
        for (auto neg : adj[u]) if(neg != p) {
            if (dp[neg] > mx.first) {
                swap(mx.first, mx.second);
                mx.first = dp[neg];
            } else if (dp[neg] > mx.second) {
                mx.second = dp[neg];
            }
        }
        sol = max(sol, n+mx.first);

        for (auto neg : adj[u]) if(neg != p) {
            ll re;
            if (dp[neg] == mx.first) {
                re = n - C[neg] + mx.second;
            } else re = mx.first + n - C[neg];
            
            dfs2(neg, u, re);
        }
    };
    dfs2(1, 0, 0);


    cout << sol << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
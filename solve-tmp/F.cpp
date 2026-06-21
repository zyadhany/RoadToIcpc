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
#define int long long

const int MODE = 1e9+7;

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
    
    vi dp(n+1), dp2(n+1), C(n+1);

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        C[u] = 1;

        ll cnt = 0;
        for (auto neg : adj[u]) if (neg != p) {
            dfs(neg, u);
            C[u] += C[neg];
            dp[u] += dp[neg];    
            cnt += C[neg]%2;
        }
        if (cnt%2) {
            dp[u]++;
        }
        dp[u] += (cnt/2)*2;
    };
    
    
    function<void(ll, ll, ll)> dfs2 = [&](ll u, ll p, ll tp) {
        
        ll all = tp;
        ll cnt = (n - C[u]) % 2;
        for (auto neg : adj[u]) if (neg != p) {
            all += dp[neg];
            cnt += C[neg] % 2;
        }
        
        all += (cnt/2)*2;
        dp2[u] = all;


        for (auto neg : adj[u]) if (neg != p) {
            ll nal = all - dp[neg];
            if (C[neg]%2) {
                nal--;
            }
            dfs2(neg, u, nal);
        }
    };
    dfs(1, 0);
    if (n%2 == 0) {
        cout << dp[1] << '\n';
        return;
    }
    dfs2(1, 0, 0);
    ll mn = dp2[1];
    for (int i = 1; i <= n; i++)
    {
        mn = min(mn, dp2[i]);
    }
    
    cout << mn << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

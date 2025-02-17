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

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
    }
    
    vii dp(1 << n, vi(n, 0));
    dp[1][0] = 1;
    for (int i = 3; i < (1<<n); i+=2)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i&(1<<j))) continue;
            ll p = i - (1 << j);
            for (auto neg : adj[j])
                if (i & (1<<neg))
                    dp[i][j] += dp[p][neg];
            dp[i][j] %= MODE;
        }
    }

    cout << dp[(1<<n)-1][n-1] << '\n'; 
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

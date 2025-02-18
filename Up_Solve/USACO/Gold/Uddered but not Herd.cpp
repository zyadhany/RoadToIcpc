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
#define mi map<ll,ll

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
    string s;
    
    cin >> s;
    
    ll n = 0;
    mc Y;
    for (auto c : s) if (!Y.count(c))
        Y[c] = n++;

    vii adj(n, vi(n));
    for (int i = 1; i < s.size(); i++)
        adj[Y[s[i-1]]][Y[s[i]]]++;
    
    vi dp(1<<n, INT32_MAX);
    dp[0] = 1;

    ll bt = n / 2;
    vii sl(n, vi(1<<bt)), sr(n, vi(1<<(n-bt)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1<<bt); j++)
            for (int h = 0; h < bt; h++)
                if (j & (1<<h)) {
                    sl[i][j] += adj[i][h];
                }
        for (int j = 0; j < (1<<(n-bt)); j++)
            for (int h = 0; h < (n-bt); h++)
                if (j & (1<<h)) {
                    sr[i][j] += adj[i][h+bt];
                }            
    }

    for (int i = 1; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i &(1<<j))) continue;
            int sub = (i ^ (1<<j));
            ll ans = dp[sub];
            ans += sl[j][i & ((1<<bt)-1)];
            ans += sr[j][i >> bt];
            dp[i] = min(dp[i], ans);
        }
    }

    cout << dp[(1<<n)-1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

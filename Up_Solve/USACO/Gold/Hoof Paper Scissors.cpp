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

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);
    vector<vii> dp(n, vii(k + 1, vi(3)));

    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        if (c == 'P') X[i] = 0;
        else if (c == 'H') X[i] = 1;
        else X[i] = 2;
    }

    dp[0][0][X[0]] = 1;


    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int h = 0; h < 3; h++)
            {
                ll mx = 0;
                mx = max(mx, dp[i-1][j][h]);
                if (j) mx = max({mx, dp[i-1][j-1][0], dp[i-1][j-1][1], dp[i-1][j-1][2]});
                mx += (X[i] == h);
                dp[i][j][h] = max(dp[i][j][h], mx);
            }
        }
    }

    ll res = 0;
    for (auto Z : dp[n-1]) res = max({res, Z[0], Z[1], Z[2]});    
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

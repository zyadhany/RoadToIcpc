#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll int
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


const int MODE = 1000000007;
using namespace std;

ll req(vector<vii> &dp, vector<string> &X, ll l, ll r, ll k) {
    ll n, a, b;
    n = X.size(), a = n - k - 1, b = n - (l+r-k) - 1;
    if (l + r == n - 1) return (a==l&&b==r);
    if (l >= dp.size() || r >= dp[l].size() || k >= dp[l][r].size())
        return 0;
    
    ll &res = dp[l][r][k];
    if (res != -1) return res;
    res = 0;

    if (a < l || b < r || X[l][r] != X[a][b]) return res;
    res += req(dp, X, l+1,r,k+1);
    res += req(dp, X, l+1,r,k);
    res %= MODE;
    res += req(dp, X, l,r+1,k+1);
    res %= MODE;
    res += req(dp, X, l,r+1,k);
    return (res %= MODE);
}

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vii X(n, vi(3));

    for (int i = 0; i < n; i++)
        cin >> X[i][2] >> X[i][1] >> X[i][0];
    sortx(X);
    
    vii dp(n + 1, vi(k + m + 1));
    dp[0][0] = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= k + m; j++)
        {
            ll rem = max(k - j, ll(0));
            ll cn = rem / X[i][0];
            ll tk = min(X[i][1], cn);
            ll tkc = tk * X[i][0];
            ll val = X[i][1] - tk;
            
            if (val != 0) tkc = rem;
            if (j + tkc + val <= k + m)
                dp[i+1][j+tkc+val] = max(dp[i+1][j+tkc+val], dp[i][j] + X[i][2]);

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    ll sol = 0;
    for (int i = 0; i <= m + k; i++)
            sol = max(sol, dp[n][i]);
    cout << sol << '\n';
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("palpath.in", "r", stdin);
    // freopen("palpath.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

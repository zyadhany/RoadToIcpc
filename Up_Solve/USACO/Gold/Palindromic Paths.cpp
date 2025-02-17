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
    ll n;

    cin >> n;
    vector<string> X(n);
    vector<vii> dp(n);
    for (int i = 0; i < n; i++) cin >> X[i];

    for (int i = 0; i < n; i++)
    {
        dp[i].resize(n-i-1);
        for (int j = 0; j < dp[i].size(); j++)
            dp[i][j].assign(i+j+1, -1);
    }

    cout << req(dp, X, 0, 0, 0) << '\n';
}   

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

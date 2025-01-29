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
    ll n, m;

    cin >> n >> m;

    vii dp(n+10, vi(m+10));

    dp[1][1] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i+1][j+2] += dp[i][j], dp[i+2][j+1] += dp[i][j];
    
    cout << dp[n][m] << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

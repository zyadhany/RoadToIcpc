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

const int MODE = 998244353;

using namespace std;

void solve(int tc) {
    ll n;
    cin >> n;
    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sortx(X);
    
    vector<vii> dp(n, vii(n, vi(2)));

    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][i][0] = dp[i][i][1] = n * abs(X[i]);
        for (int j = i + 1; j < n; j++)
        {
            ll rem = n - j + i;
            ll a, b;
            a = dp[i][j-1][1] + rem * (X[j]-X[j-1]);
            b = dp[i][j-1][0] + rem * (X[j]-X[i]);
            dp[i][j][1] = min(a, b);

            a = dp[i+1][j][0] + rem * (X[i+1]-X[i]);
            b = dp[i+1][j][1] + rem * (X[j]-X[i]);
            dp[i][j][0] = min(a, b);
        }    
    }
    
    cout << min(dp[0][n-1][0], dp[0][n-1][1]);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);   
}

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

void solve(int tc) {
    ll n, x, y;

    cin >> n >> x >> y;

    vi X(n + 10), dp(n + 10, INT64_MAX);

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (X[i] >= X[i - 1] || X[i] >= X[i + 1]) {
            dp[i] = dp[i - 1];
            continue;
        }

        dp[i] = dp[i - 1] + (min(X[i - 1], X[i + 1]) - X[i]) * min(x, y);
        if (i < 4) continue;
        if (X[i - 1] <= X[i - 2] || X[i - 3] <= X[i - 2]) continue;
 
        ll a, b, c;
        a = X[i];
        b = X[i - 2];
        c = X[i - 1];
        if (b < a) swap(a, b);
 
        ll re = dp[i - 3] + (c - b) * y + (b - a) * x;
        re = min(re, dp[i - 3] + (c - a) * y);
        dp[i] = min(dp[i], re);
    }
    
    cout << dp[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
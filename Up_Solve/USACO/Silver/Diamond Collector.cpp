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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;    

void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    vi X(n);

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sortx(X);

    ll at = 0;
    vi Z(n + 1), dp(n + 1);
    
    X.push_back(INT32_MAX);
    for (int i = 0; i <= n; i++)
        while (X[i] - X[at] > k)
        {
            Z[at] = i - at;
            at++;
        }
    for (int i = n - 1; i >= 0; i--)
        dp[i] = max(dp[i + 1], Z[i]);

    ll mx = 0;

    for (int i = 0; i < n; i++)
    {
        ll re = Z[i] + dp[i + Z[i]];
        mx = max(mx, re);
    }

    cout << mx << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

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

const int MODE = 1e9 + 7;

void solve(int tc) {
    ll n, a, b;

    cin >> n >> a >> b;

    vi dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!dp[i]) continue;
        if (i + a <= n) dp[i + a] = 1;
        if (i + b <= n) dp[i + b] = 1;
    }
    
    ll sol = 0;
    
    ll at = 0;
    ll mxl = 0;

    for (ll i = n; i >= 0; i--)
    {
        if (!dp[i]) continue;
        while ((at + 1) <= n - i/2)
        {
            at++;   
            if (dp[at]) mxl=at;
        }
        sol = max(sol, i);
        sol = max(sol, i / 2 + mxl);
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

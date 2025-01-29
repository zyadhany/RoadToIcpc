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

ll fpow(ll x, ll y) {
    ll res = 1;
    x %= MODE;
    while (y > 0) {
        if (y & 1) res = (res * x) % MODE;
        x = (x * x) % MODE;
        y >>= 1;
    }
    return res;
}


void solve(int tc) {
    ll n, m, k;
    cin >> n >> m >> k;

    ll sol = 0;
    vi dp(n + 1, 0);
    vi pref(n + 1, 0);
    dp[0] = 1;

    for (int ind = 1; ind <= n; ind++)
    { 
        dp[ind] = ((pref[ind - 1] - pref[max(0ll, ind - k)]) % MODE + MODE) % MODE;
        dp[ind] = (dp[ind] * (m - 1)) % MODE;
        if (ind <= k - 1) dp[ind] = (dp[ind] + m - 1) % MODE;
        pref[ind] = (pref[ind - 1] + dp[ind]) % MODE;
    }
    
    for (int i = 0; i <= n - k; i++)
    {
        ll re = (fpow(m, n - i - k) * dp[i]);
        sol = (sol + re) % MODE;
    }
    sol = (sol * m) % MODE;

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

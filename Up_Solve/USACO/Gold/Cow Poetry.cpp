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

const int MODE = 1e9 + 7;

using namespace std;

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

    vp X(n);
    for (int i = 0; i < n; i++)
        cin >> X[i].first >> X[i].second;

    vi dp(k + 1, 0);
    vi Z(n + 1);
    dp[0] = 1;
    for (int i = 0; i < k; i++) {
        for (auto [a, c] : X) {
            if (i + a == k) Z[c] = (Z[c] + dp[i]) % MODE;
            if (i + a <= k) dp[i + a] = (dp[i + a] + dp[i]) % MODE;
        }
    }

    vi freq(26);
    for (int i = 0; i < m; i++)
    {
        char c; cin >> c;
        freq[c - 'A']++;
    }
    
    ll sol = 1;
    for (auto f : freq) {
        if (!f) continue;
        ll re = 0;
        for (int i = 1; i <= n; i++)
            re = (re + fpow(Z[i], f)) % MODE;
        sol = (sol * re) % MODE;
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

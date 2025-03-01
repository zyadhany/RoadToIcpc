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

const int SIZE = 1e6 + 1;
vi fac(SIZE, 1), facinv(SIZE, 1);

ll nCr(ll n, ll r) {
    if (n < r || n < 0) return 0;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

void INIT() {
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = MODE - MODE / i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < SIZE; i++)
        facinv[i] = (facinv[i] * facinv[i-1])%MODE;
}

void solve(int tc) {
    string s;

    cin >> s;
    ll n = s.size();
    vii dp(n, vi(n));
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][i+1] = dp[i+1][i] = (s[i]==s[i+1]);
        for (int j = i+2; j < n; j++)
        {
            if (s[i]==s[j]) dp[i][j] = dp[i+1][j-1];

            for (int h = i+1; h < j; h++)
            {
                if (s[i] != s[h]) continue;
                ll re = (dp[i+1][h-1] * dp[h+1][j]) % MODE;
                ll a = (h-i+1)/2;
                ll b = (j-h) / 2;
                re = (re * nCr(a+b, b)) % MODE;
                dp[i][j] = (dp[i][j] + re) % MODE;
            }
        }        
    }

    cout << dp[0][n-1];
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    // freopen("threesum.in", "r", stdin);
    // freopen("threesum.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

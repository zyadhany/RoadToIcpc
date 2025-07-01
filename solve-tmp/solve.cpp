#include "bits/stdc++.h"

#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define int ll
#define pl pair<ll, ll>
#define vp vector<pl>
using namespace std;

const int SIZE = 1e6 + 1;
const int MODE = 1e9+7;
ll fac[SIZE], facinv[SIZE];

ll nCr(ll n, ll r) {
    if (n < r || n < 0) return 0;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

ll catalan(int n)
{
    ll res = fac[2 * n];
    res *= (facinv[n+1] * facinv[n]) % MODE;
    return (res) % MODE;
}

void INIT() {
    fill(fac, fac+SIZE, 1);
    fill(facinv, facinv+SIZE, 1);
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = MODE - MODE / i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < SIZE; i++)
        facinv[i] = (facinv[i] * facinv[i-1])%MODE;
}

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ll modeenv(ll n) {
    ll x, y;
    gcdExtended(n, MODE, &x, &y);
    return (x + MODE) % MODE;
}

ll catalanKparts(ll n, ll k)
{
    ll res = ((k + 1) * nCr(2 * n + k, n)) % MODE;
    res *= modeenv(n + 1 + k);
    return (res) % MODE;
}

void solve() {
    ll n;
    string s;
    cin >> n >> s;

    ll at = 0;
    for (auto a : s) {
        if (a == '(') at++;
        else at--;
        if (at < 0) {
            cout << "0\n";
            return;
        }
    }
    ll l = n - s.size() - at;
    if (l < 0 || l%2) {
        cout << "0\n";
        return;      
    }
    ll sol = catalanKparts(l/2, at);  
    cout << sol << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    INIT();
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
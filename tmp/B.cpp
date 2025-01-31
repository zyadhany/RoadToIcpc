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

// const int MODE = 1e9 + 7;

using namespace std;


const int SIZE = 1e6 + 1;
int MODE = 998244353;
vi fac(SIZE, 1), facinv(SIZE, 1);

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

// nCr = fac(n)/fac(r)*fac(n-r)
ll nCr(ll n, ll r) {
    if (n < r || n < 0) return 0;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

// nPr = fac(n) / fac(n - r)
ll nPr(ll n, ll r) {
    ll res = (fac[n] * facinv[n - r]) % MODE;
    return (res);
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
    ll n;

    cin >> n >> MODE;

    INIT();
    vi P;
    for (int i = 2; i <= n; i++)
    {
        bool isit = 1;
        for (auto a : P) {
            if (i % a == 0) {isit = 0; break;}
        }
        if (isit) P.push_back(i);
    }
    
    vi dp(n + 1, 1);
    vi C(n + 1);
    dp[0] = C[0] = 1;


    for (auto a : P)
        for (int i = n - a; i >= 0; i--) {
            if (!C[i]) continue;
            ll at = a;
            while (at + i <= n) {
                ll nc = nCr(n - i, at);
                dp[i + at] = ((dp[i + at] * nc)%MODE * (dp[i] * at)%MODE) % MODE; 
                dp[i + at] = (dp[i + at] * fpow(at, C[i])) % MODE; 
                C[i + at] = (C[i + at] + C[i] * nc) % MODE;
                at *= a;
            }
        }
    
    ll sol = 1;
    for (auto x : C) {
    sol = (sol * x) % MODE;
    cout << x << ' ';
    }
    cout << "|\n";
    cout << sol << '\n';

    ll re = 1;
    re *= fpow(2, 10);
    re %= MODE;
    re *= fpow(3, 10);
    re %= MODE;
    re *= fpow(4, 5);
    re %= MODE;
    re *= fpow(5, 10);
    re %= MODE;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("exercise.in", "r", stdin);
    // freopen("exercise.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

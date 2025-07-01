/**
 * It use factorial fourmal of nCr,
 * use mod inv to avoid overflow.
 * Time O(n) - Build.
 * Time O(log(n)) - query.
 * Space O(n).
*/

const int SIZE = 1e6 + 1;
const int MODE = 998244353;
ll fac[SIZE], facinv[SIZE];

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
    fill(fac, fac+SIZE, 1);
    fill(facinv, facinv+SIZE, 1);
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = MODE - MODE / i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < SIZE; i++)
        facinv[i] = (facinv[i] * facinv[i-1])%MODE;
}

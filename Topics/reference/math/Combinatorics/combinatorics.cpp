const int SIZE = 1e6 + 1;
const int MODE = 998244353;
vi fac(SIZE, 1);

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

// nCr = fac(n)/fec(r)*fac(n-r)
ll nCr(ll n, ll r) {
    ll res = fac[n];
    res *= modeenv((fac[r] * fac[n - r]) % MODE);
    return (res) % MODE;
}

//nPr = fac(n) / fac(n - r)
ll nPr(ll n, ll r) {
    ll res = fac[n];
    res *= modeenv(fac[n - r]);
    return (res) % MODE;
}

void INIT() {
    for (int i = 2; i < SIZE; i++)
        fac[i] = (i * fac[i - 1]) % MODE;
}
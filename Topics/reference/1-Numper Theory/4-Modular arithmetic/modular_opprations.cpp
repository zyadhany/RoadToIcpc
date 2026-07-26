const int mod = 1e9+7;
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

ll modinv(ll n) {
    ll x, y;
    gcdExtended(n, mod, &x, &y);
    return (x + mod) % mod;
}

ll add(ll &a, ll b) {
    a += b;
    a %= mod;
    return a = (a + mod) % mod;
}
ll sub(ll &a, ll b) {
    return add(a, -b);
}
ll mul(ll &a, ll b) {
    b = (b%mod + mod) % mod;
    return a = ((a%mod) * (b%mod))%mod;
}
ll divied(ll &a, ll b) {
    return a = (a * modinv(b))%mod;
}

const int MODE = 1e9 + 7;

/**
 * it return value of gcd(a,b)
 * x*a + y*b = gcd(a, b)
*/
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

/**
* if a,b are coprimes then:
* x be a mode inv for b and via verse.
*/
ll modeenv(ll n) {
    ll x, y;
    gcdExtended(n, MODE, &x, &y);
    return (x % MODE + MODE) % MODE;
}

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0) {
        *x = 0, * y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

/*
* solve: x*a + y*b = n.
* 
* let d = gcd(a, b).
* from: x*a + y*b = d.
* if n = d * k -->>.
* (x * k) * a + (y * k) * b = d * k = n.
* now i got the value of x, y just need to make them postive.
* i can keep adding and subbstract by same value of x, y
* 
* X = x + n * (b/d) ||| Y = y - n * (a/d).
* n can be any int from - to +.
* 
* I want X & Y to be postive so.
* n >= ceil(-x / (b/d)) || n <= floor(y / (a/d)).
* 
* Return: range l, r that n can be so x, y are postive.
*/
pair<ll, ll> getExtendedRange(ll a, ll b, ll n) {
    ll x, y, d, xl, yl, l, r;
    d = gcdExtended(a, b, &x, &y);

    // if n not divided by d then no sol.
    if (n % d) return { INT32_MAX, INT32_MAX };

    x *= n / d, y *= n / d;
    xl = b / d, yl = a / d;
    l = ceil(-(double)x / xl);
    r = floor((double)y / yl);

    // l > r: so no value make them postive
    if (l > r) return { INT32_MAX, INT32_MAX };
    return {l , r};
}

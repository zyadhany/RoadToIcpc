// it work only if values of x that satisfy the conditions are not too large (<= LIM).

const ll LIM = 4000000000000000000LL;

ll norm(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    ll x1, y1;
    ll g = gcdExtended(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return g;
}

struct CRTState {
    // type = 0 -> impossible
    // type = 1 -> x === r mod m
    // type = 2 -> x == r
    int type;
    ll r, m;

    CRTState(int _type = 1, ll _r = 0, ll _m = 1) {
        type = _type;
        r = _r;
        m = _m;
    }
};

bool checkCRT(CRTState cur, ll x) {
    if (cur.type == 0) return false;
    if (cur.type == 2) return x == cur.r;
    return norm(x, cur.m) == cur.r;
}

CRTState CRT(ll a1, ll m1, ll a2, ll m2) {
    a1 = norm(a1, m1);
    a2 = norm(a2, m2);

    ll x, y;
    ll g = gcdExtended(m1, m2, &x, &y);

    ll d = a2 - a1;

    if (d % g != 0) {
        return CRTState(0); // impossible
    }

    ll mod = m2 / g;

    __int128 k = (__int128)x * (d / g);
    k %= mod;
    if (k < 0) k += mod;

    __int128 ans = (__int128)a1 + (__int128)m1 * k;
    __int128 lcm = (__int128)m1 / g * m2;

    ans %= lcm;
    if (ans < 0) ans += lcm;

    if (lcm > LIM) {
        if (ans <= LIM) {
            return CRTState(2, (ll)ans, 1); // x == ans
        }
        return CRTState(0); // no useful value inside limit
    }

    return CRTState(1, (ll)ans, (ll)lcm);
}
CRTState addCondition(CRTState cur, ll a, ll m) {
    a = norm(a, m);
    if (cur.type == 0) return cur;
    if (m == 1) return cur;
    if (cur.type == 2) {
        if (norm(cur.r, m) == a) return cur;
        return CRTState(0);
    }
    return CRT(cur.r, cur.m, a, m);
}

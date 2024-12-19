/**
 * x^{m-1} = 1  mod(m)
 * m is prime and x,m are coprime
 * -> x^{k} mod(m) = x^{k mod(m-1)} mod(m)
 * 
 * x*x^{-1} = 1 mod(m)
 * -> x^{-1} = x^{m-2}
 */

const int MODE = 1e9 + 7;

ll fpow(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x) % MODE;
        x = (x * x) % MODE;
        y >>= 1;
    }
    return res;
}

ll modinv(ll x) {
    return fpow(x, MODE - 2);
}

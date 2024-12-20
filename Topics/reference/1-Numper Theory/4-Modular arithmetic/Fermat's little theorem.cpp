/**
 * fermat's little theorem
 * x^{m} = x mod(m)
 * x^{m-1} = 1  mod(m)
 * x^{m-2} = x^{-1} mod(m) -> modular inverse
 * m is prime and x,m are coprime
 * -> x^{k} mod(m) = x^{k mod(m-1)} mod(m)
 */

/**
 * Using Euler's theorem
 * x^{phi(m)} = 1 mod(m)
 * x^{phi(m)-1} = x^{-1} mod(m) -> modular inverse
 * m is prime and x,m are coprime
 * -> x^{k} mod(m) = x^{k mod(phi(m))} mod(m)
 * phi(m) = m - 1 if m is prime
 */

const int MODE = 1e9 + 7;

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

ll modinv(ll x) {
    return fpow(x, MODE - 2);
}

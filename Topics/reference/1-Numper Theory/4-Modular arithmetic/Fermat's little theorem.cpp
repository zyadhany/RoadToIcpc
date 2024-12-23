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


// get count and summtion and product for divsors of number
// p: prime factor, k it'scount p^k
ll cnt, summ, prod, pcnt;
cnt = summ = prod = pcnt = 1;
for (auto [p, k] : PF)
{        
    // prod = prod^{k+1} * p^{summ(1->k)*cnt}
    ll kp = (((k * (k + 1) / 2) % (MODE - 1)) * pcnt) % (MODE - 1);
    prod = (fpow(prod, k + 1) * fpow(p, kp)) % MODE; 
    pcnt = (pcnt * (k + 1)) % (MODE - 1);
    
    // cnt = cnt * k + 1
    cnt = (cnt * (k + 1)) % MODE;

    // summtion = summ * (x^{k + 1} - 1) / (x-1)
    ll tp = ((fpow(p, k + 1) - 1)%MODE+MODE)%MODE;
    tp = (tp * fpow(p - 1, MODE - 2)) % MODE;
    summ = (summ * tp) % MODE;
}
cout << cnt << ' ' << summ << ' ' << prod << '\n';

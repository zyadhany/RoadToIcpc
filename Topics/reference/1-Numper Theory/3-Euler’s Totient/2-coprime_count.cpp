/*
if want to count how many c shuch that gcd(c, a) = d, where 1<=c<=n. 
c much be multiple of d, c = d * k, so we can count how many k such that gcd(k, a/d) = 1, where 1<=k<=n/d.
*/

// count of numbers less than or equal to L that are coprime with m
ll count_coprime(ll m, ll L) {
    if (L <= 0) return 0;
    vi primes;
    ll temp = m;
    for (ll i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            primes.push_back(i);
            while (temp % i == 0) temp /= i;
        }
    }
    if (temp > 1) primes.push_back(temp);

    int sz = primes.size();
    ll cnt = 0;
    for (int mask = 0; mask < (1 << sz); mask++) {
        ll prod = 1;
        int bits = 0;
        for (int i = 0; i < sz; i++) {
            if ((mask >> i) & 1) {
                prod *= primes[i];
                bits++;
            }
        }
        if (bits % 2 == 1) {
            cnt -= L / prod;
        } else {
            cnt += L / prod;
        }
    }
    return cnt;
}
// phi(n) = n * (1 – 1 / p) for all prime factors of n.
// phi(n * m) = phi(n) * phi(m) * (gcd(n,m) / phi(gcd(n,m))).
// phi(p) = p - 1 (p is prime numper).
// phi(a*b) = (a - 1) * (p - 1): (a, b are prime numpers).
// phi(p^k) = p^k - p^{k-1}.
// summ(phi(d)) == phi(n): (summtion all divisors of n).
// a^{phi(n)} = 1 (mod n): (a, n are coprime numbers).


// Time O(sqrl(n)).
int phi(int n)
{
    int res = n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p) continue;
        while (n % p == 0) n /= p;
        //res *= (1.0 - (1.0 / (float)p));
        res -= res / p; 
    }
    if (n > 1) res -= res/ n;
    return (res);
}
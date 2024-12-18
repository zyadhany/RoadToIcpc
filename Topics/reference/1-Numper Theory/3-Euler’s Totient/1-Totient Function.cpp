// phi(n) = n * (1 – 1 / p) for all prime factors of n.
// phi(n * m) = phi(n) * phi(m) * (gcd(n,m) / phi(gcd(n,m))).
// phi(p) = p - 1 (p is prime numper).
// phi(a*b) = (a - 1) * (p - 1): (a, b are prime numpers).
// phi(p^k) = p^k - p^{k-1}.
// summ(phi(d)) == phi(n): (summtion all divisors of n).
// a^{phi(n)} = 1 (mod n): (a, n are coprime numbers).


/**
 * phi(n) -> conut of i < n as gcd(n, i) = 1.
 * phi(n / d) -> count of i < n as gcd(n, i) = d. (d in divsor of n).
 */

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



// another approche to get phi from 1 to n

const int MAXN = 1e6+1;
int phi[MAXN];

void INIT() {
    vector <int> prime;
    bool is_composite[MAXN];
	fill (is_composite, is_composite + MAXN, false);
	phi[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		if (!is_composite[i]) {
			prime.push_back (i);
			phi[i] = i - 1;					//i is prime
		}
		for (int j = 0; j < prime.size () && i * prime[j] < MAXN; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
				break;
			} else {
				phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
			}
		}
	}
}

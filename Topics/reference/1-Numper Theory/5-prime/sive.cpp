vi prime(1e7 + 10, 0);
vi primes;

void INIT() {
    for (int i = 0; i < prime.size(); i++) prime[i] = i;
    for (int i = 2; i * i <= 1e7; ++i) if (prime[i] == i)
        for (int j = i; j <= 1e7; j += i) prime[j] = i;
    for (int i = 2; i <= 1e7; i++) if(prime[i] == i) primes.push_back(i);
}

vi PF(ll n) {
    vi X;

    while (n > 1)
    {
        X.push_back(prime[n]);
        n /= prime[n];
    }
    
    return (X);
}


// another approh: linner sive

std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

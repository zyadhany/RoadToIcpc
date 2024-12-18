const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
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

void divsorFactors(vp &faccnt, vi &div, ll at, ll d) {
    if (at == faccnt.size()) {div.push_back(d); return;}
    divsorFactors(faccnt, div, at + 1, d);
    for (int i = 0; i < faccnt[at].second; i++)
    {
        d *= faccnt[at].first;
        divsorFactors(faccnt, div, at + 1, d);
    }
}

vi divsors(ll n) {
    if (n == 1) return {1};
    vi fac;
    while(n > 1) fac.push_back(prime[n]), n /= prime[n];
    sort(fac.begin(), fac.end());
    vp faccnt;
    pl re = {fac[0], 1};
    for (int i = 1; i < fac.size(); i++)
    {
        if (fac[i] == re.first) re.second++;
        else faccnt.push_back(re), re = {fac[i], 1};
    }
    faccnt.push_back(re);
    vi div;
    divsorFactors(faccnt, div, 0, 1);
    return div;
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

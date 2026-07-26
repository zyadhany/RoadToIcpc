const int MAXSZ = 1e7 + 1;
int prime[MAXSZ] = {0};
vi primes;
 
void INIT() {
    for (int i = 0; i < MAXSZ; i++) prime[i] = i;
    for (int i = 2; i * i < MAXSZ; ++i) if (prime[i] == i)
        for (int j = i; j < MAXSZ; j += i) prime[j] = i;
    for (int i = 2; i < MAXSZ; i++) if(prime[i] == i) primes.push_back(i);
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

// get vector pair p.first^p.second
vp factorizationCnt(int n) {
    if (n == 1) return {};
    vi fac;
    while(n > 1) fac.push_back(prime[n]), n /= prime[n];
    vp faccnt;
    pl re = {fac[0], 1};
    for (int i = 1; i < fac.size(); i++)
    {
        if (fac[i] == re.first) re.second++;
        else faccnt.push_back(re), re = {fac[i], 1};
    }
    faccnt.push_back(re);
    return faccnt;
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


// sieve 1e9
vector<int> sieve(const int N, const int Q = 17, const int L = 1 << 15) {
  static const int rs[] = {1, 7, 11, 13, 17, 19, 23, 29};
  struct P { 
    P(int p) : p(p) {}
    int p; int pos[8];
  };
  auto approx_prime_count = [] (const int N) -> int {
    return N > 60184 ? N / (log(N) - 1.1)
                     : max(1., N / (log(N) - 1.11)) + 1;
  };

  const int v = sqrt(N), vv = sqrt(v);
  vector<bool> isp(v + 1, true);
  for (int i = 2; i <= vv; ++i) if (isp[i]) {
    for (int j = i * i; j <= v; j += i) isp[j] = false;
  }

  const int rsize = approx_prime_count(N + 30);
  vector<int> primes = {2, 3, 5}; int psize = 3;
  primes.resize(rsize);

  vector<P> sprimes; size_t pbeg = 0;
  int prod = 1; 
  for (int p = 7; p <= v; ++p) {
    if (!isp[p]) continue;
    if (p <= Q) prod *= p, ++pbeg, primes[psize++] = p;
    auto pp = P(p); 
    for (int t = 0; t < 8; ++t) {
      int j = (p <= Q) ? p : p * p;
      while (j % 30 != rs[t]) j += p << 1;
      pp.pos[t] = j / 30;
    }
    sprimes.push_back(pp);
  }

  vector<unsigned char> pre(prod, 0xFF);
  for (size_t pi = 0; pi < pbeg; ++pi) {
    auto pp = sprimes[pi]; const int p = pp.p;
    for (int t = 0; t < 8; ++t) {
      const unsigned char m = ~(1 << t);
      for (int i = pp.pos[t]; i < prod; i += p) pre[i] &= m;
    }
  }

  const int block_size = (L + prod - 1) / prod * prod;
  vector<unsigned char> block(block_size); unsigned char* pblock = block.data();
  const int M = (N + 29) / 30;

  for (int beg = 0; beg < M; beg += block_size, pblock -= block_size) {
    int end = min(M, beg + block_size);
    for (int i = beg; i < end; i += prod) {
      copy(pre.begin(), pre.end(), pblock + i);
    }
    if (beg == 0) pblock[0] &= 0xFE;
    for (size_t pi = pbeg; pi < sprimes.size(); ++pi) {
      auto& pp = sprimes[pi];
      const int p = pp.p;
      for (int t = 0; t < 8; ++t) {
        int i = pp.pos[t]; const unsigned char m = ~(1 << t);
        for (; i < end; i += p) pblock[i] &= m;
        pp.pos[t] = i;
      }
    }
    for (int i = beg; i < end; ++i) {
      for (int m = pblock[i]; m > 0; m &= m - 1) {
        primes[psize++] = i * 30 + rs[__builtin_ctz(m)];
      }
    }
  }
  assert(psize <= rsize);
  while (psize > 0 && primes[psize - 1] > N) --psize;
  primes.resize(psize);
  return primes;
}
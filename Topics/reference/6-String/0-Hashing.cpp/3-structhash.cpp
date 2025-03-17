class HashedString {
  public:
	// change M and B if you want
	static const ll M = (1LL << 61) - 1;
	static const ll B;
	static __int128 mul(ll a, ll b) { return (__int128)a * b; }
	static ll mod_mul(ll a, ll b) { return mul(a, b) % M; }

  private:
	// pow[i] contains P^i % M
	static vector<ll> pow;
	// p_hash[i] is the hash of the first i characters of the given string
	vector<ll> p_hash;
  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	ll get_hash(int start, int end) {
		ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);
// EndCodeSnip

const auto M = HashedString::M;
const auto B = HashedString::B;
const auto mul = HashedString::mul;
const auto mod_mul = HashedString::mod_mul;
ll inv(ll base, ll MOD) {
	ll ans = 1, expo = MOD - 2;
	while (expo) {
		if (expo & 1) { ans = mod_mul(ans, base); }
		expo >>= 1;
		base = mod_mul(base, base);
	}
	return ans;
}

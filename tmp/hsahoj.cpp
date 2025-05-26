#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;


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

void solve(int tc) {
	ll n, m;

	cin >> n >> m;

	vector<string> X(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
		for (auto &c : X[i]) if (c=='.') c = (char)2;
		else c = (char)1;
	}

	vi res(m);
	for (int i = 0; i < m; i++) res[i] = i;


	for (auto s : X) {
		s += s;
		
		HashedString H(s);
		auto cmp = [&](ll i, ll j) {
			ll l = 0, r = m;
			while (l < r)
			{
				ll mid = (l + r + 1) / 2;
				ll hi = H.get_hash(i, i+mid-1);
				ll hj = H.get_hash(j, j+mid-1);
				if (hi == hj) l = mid;
				else r = mid - 1;
			}
			
			if (l == m) return false;
			return s[i+l] < s[j+l];
		};
		sort(res.begin(), res.end(), cmp);
		// for (auto a : res) cout << a << '\n';
		// cout << cmp(res.back(), res[0]) << "|\n";
		while (true)
		{
			if (!cmp(res[0], res.back()) && !cmp(res.back(), res[0])) break;
			res.pop_back();
		}
	}
	

	ll sh = res[0];
	for (int i = 0; i < n; i++)
	{
		X[i] += X[i].substr(0, sh);
		X[i] = X[i].substr(sh, m);
		for (auto &c : X[i]) if (c == 2) c = '.';
		else c = '*';
	}
	
	for (auto &s : X) cout << s << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("lightsout.in", "r", stdin);
    // freopen("lightsout.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

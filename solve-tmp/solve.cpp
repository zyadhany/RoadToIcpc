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
	HashedString(const vi &s) : p_hash(s.size() + 1) {
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

	vector<int> suff(m*n);
	for (int i = 0; i < n*m; i++) suff[i] = i;
	vector<HashedString> H;

	for (auto &s : X) {
		s += s;
		H.push_back(HashedString(s));	
	}

	vii HX(m, vi(n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			HX[i][j] = H[j].get_hash(i, i+m-1);
			vector<HashedString> HR;
	cout << "|" << endl;
	for (int i = 0; i < M; i++)
		HR.push_back(HashedString(HX[i]));	
	
	
	auto cmp = [&](ll st, ll en) {
		ll ir = st/m, in = st%m;
		ll jr = en/m, jn = en%m;

		ll l = 0, r = n*m;
		while (l < r)
		{
			ll mid = (l + r + 1) / 2;
	
			ll hi = (HR[in].get_hash(ir,ir+mid/m-1) * B) % M;
			hi += H[ir+mid/m].get_hash(in, in+mid%m-1);
			hi %= M;
			
			ll hj = (HR[jn].get_hash(jr,jr+mid/m-1) * B) % M;
			hj += H[jr+mid/m].get_hash(jn, jn+mid%m-1);
			hj %= M;
	
			if (hi == hj) l = mid;
			else r = mid - 1;
		}
		
		if (l == n*m) return false;
		return X[ir+l/m][in+l%m] < X[jr+l/m][jn+l%m];
	};
	sort(suff.begin(), suff.end(), cmp);	
	
	ll star = suff[0]/m, sh = suff[0]%m;
	for (int i = 0; i < n; i++)
	{
		X[i] += X[i].substr(0, sh);
		X[i] = X[i].substr(sh, m);
		for (auto &c : X[i]) if (c == 2) c = '.';
		else c = '*';
	}
	for (int i = 0; i < n; i++) cout << X[(i+star)%n] << '\n';
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

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
const int MODE = 1e9 + 7;
  
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
    HashedString(){}
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

    vector<HashedString> X(n), Y(n);
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        X[i] = HashedString(s);
    }
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        Y[i] = HashedString(s);
    }

    ll l = 1, r = m;
    while (l < r) {
        ll len = (l + r) / 2;
        bool istr = 0;

        for (int i = 0; i < m - len; i++)
        {
            bool isit = 1;
            set<ll> st;
            for (auto &H : X) st.insert(H.get_hash(i, i + len - 1));
            for (auto &H : Y) if (st.count(H.get_hash(i, i + len - 1))) {
                isit = 0;
                break;
            }
    
            if (isit) {
                istr = 1;
                break;
            } 
        }

        if (istr) r = len;
        else l = len + 1;
    }
    
    cout << l << '\n';    
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

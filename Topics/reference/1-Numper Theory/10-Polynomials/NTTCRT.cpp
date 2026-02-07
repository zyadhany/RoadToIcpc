// Convolution modulo 1e9+7 using CRT over 3 NTT primes.
// Works for vectors of ints/ll (values can already be mod 1e9+7).
// Complexity: O(n log n).

#include <bits/stdc++.h>
using namespace std;


using i128 = __int128_t;

static const ll MOD = 1000000007LL;

// ---------- modpow / modinv ----------
static ll modpow(ll a, ll e, ll mod){
    ll r = 1 % mod;
    a %= mod;
    while(e > 0){
        if(e & 1) r = (i128)r * a % mod;
        a = (i128)a * a % mod;
        e >>= 1;
    }
    return r;
}
static ll modinv(ll a, ll mod){
    // mod must be prime
    return modpow(a, mod - 2, mod);
}

// ---------- NTT (iterative) ----------
struct NTTMod {
    ll mod, root; // primitive root
    NTTMod(ll m, ll r): mod(m), root(r) {}

    void ntt(vector<ll>& a, bool invert) const {
        int n = (int)a.size();
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1) j ^= bit;
            j ^= bit;
            if (i < j) swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            ll wlen = modpow(root, (mod - 1) / len, mod);
            if (invert) wlen = modinv(wlen, mod);

            for (int i = 0; i < n; i += len) {
                ll w = 1;
                int half = len >> 1;
                for (int j = 0; j < half; j++) {
                    ll u = a[i + j];
                    ll v = (i128)a[i + j + half] * w % mod;
                    ll x = u + v; if (x >= mod) x -= mod;
                    ll y = u - v; if (y < 0)   y += mod;
                    a[i + j] = x;
                    a[i + j + half] = y;
                    w = (i128)w * wlen % mod;
                }
            }
        }

        if (invert) {
            ll n_inv = modinv(n, mod);
            for (ll &x : a) x = (i128)x * n_inv % mod;
        }
    }

    vector<ll> convolution(const vector<ll>& A, const vector<ll>& B) const {
        if (A.empty() || B.empty()) return {};
        int n1 = (int)A.size(), n2 = (int)B.size();
        int n = 1;
        while (n < n1 + n2 - 1) n <<= 1;

        vector<ll> fa(n), fb(n);
        for (int i = 0; i < n1; i++) fa[i] = (A[i] % mod + mod) % mod;
        for (int i = 0; i < n2; i++) fb[i] = (B[i] % mod + mod) % mod;

        ntt(fa, false);
        ntt(fb, false);
        for (int i = 0; i < n; i++) fa[i] = (i128)fa[i] * fb[i] % mod;
        ntt(fa, true);

        fa.resize(n1 + n2 - 1);
        return fa;
    }
};

// ---------- CRT combine to mod 1e9+7 ----------
static inline ll crt3_to_mod(ll r1, ll r2, ll r3,
                             ll m1, ll m2, ll m3,
                             ll inv_m1_mod_m2,
                             ll inv_m1m2_mod_m3)
{
    // Garner-ish in 2 steps (all residues are in [0, mi-1]).
    ll t1 = r1;

    ll t2 = (r2 - t1) % m2; if (t2 < 0) t2 += m2;
    t2 = (i128)t2 * inv_m1_mod_m2 % m2;

    ll x12_mod_m3 = (t1 + (i128)m1 * t2) % m3;

    ll t3 = (r3 - x12_mod_m3) % m3; if (t3 < 0) t3 += m3;
    t3 = (i128)t3 * inv_m1m2_mod_m3 % m3;

    // Return x mod MOD without building huge integers
    ll a = t1 % MOD;
    ll b = (i128)(m1 % MOD) * (t2 % MOD) % MOD;
    ll c = (i128)((i128)m1 * m2 % MOD) * (t3 % MOD) % MOD;
    ll ans = a + b; if (ans >= MOD) ans -= MOD;
    ans += c; ans %= MOD;
    return ans;
}

// ---------- Public API: convolution mod 1e9+7 ----------
vector<ll> convolution_mod_1e9p7(const vector<ll>& A, const vector<ll>& B) {
    if (A.empty() || B.empty()) return {};

    // 3 NTT primes + primitive roots
    const ll m1 = 998244353LL;   const ll g1 = 3;
    const ll m2 = 1004535809LL;  const ll g2 = 3;
    const ll m3 = 469762049LL;   const ll g3 = 3;

    NTTMod n1(m1, g1), n2(m2, g2), n3(m3, g3);

    auto c1 = n1.convolution(A, B);
    auto c2 = n2.convolution(A, B);
    auto c3 = n3.convolution(A, B);

    // Precompute inverses for CRT
    ll inv_m1_mod_m2 = modinv(m1 % m2, m2);
    ll inv_m1m2_mod_m3 = modinv((ll)((i128)m1 * m2 % m3), m3);

    int n = (int)c1.size();
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = crt3_to_mod(c1[i], c2[i], c3[i],
                             m1, m2, m3,
                             inv_m1_mod_m2,
                             inv_m1m2_mod_m3);
    }
    return res;
}
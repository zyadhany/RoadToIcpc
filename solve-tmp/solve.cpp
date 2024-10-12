#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define Bit(x) (1 << (x))
#define ll long long
using namespace std;


const int mod = 998244353, CN = 2e5 + 8;
vector<ll> inv(CN + 6), fac(CN + 6), ifac(CN + 6); 

ll C(int a, int b) {
    if (b > a || b < 0) return 0;
    return fac[a] * ifac[b] % mod * ifac[a - b] % mod; 
}

void prep(void) {
    inv[1] = fac[0] = ifac[0] = 1;
    for (int i = 2; i <= CN; i++) 
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i <= CN; i++)
        fac[i] = fac[i - 1] * i % mod, ifac[i] = ifac[i - 1] * inv[i] % mod;    
}

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

ll calc(int n, int m, int k) {
    if (k == 0) return C(n + m - 1, m - 1);
    ll ret = 0;
    int sgn = 1;
    for (int i = 1; i * k <= n && i <= m; i++) {
        add(ret, (sgn * C(m, i) * C(n - i * k + m - 1, m - 1) % mod + mod) % mod);
        sgn *= -1;
    }
    return ret;
}

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << (calc(m, n - m + 1, k) - calc(m, n - m + 1, k + 1) + mod) % mod << endl; 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    prep();
    for (int i = 1; i <= tc; i++) {
        solve();
    }
    return 0;
}

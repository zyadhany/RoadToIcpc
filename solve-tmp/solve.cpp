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

const int MODE = 1e9 + 7;

using namespace std;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
int modpow(int b, int e, int m) {
    int ans = 1;
    for (; e; b = (ll)b * b % m, e /= 2)
        if (e & 1) ans = (ll)ans * b % m;
    return ans;
}

void ntt(vector<int> &a) {
    int n = (int)a.size(), L = 31 - __builtin_clz(n);
    vector<int> rt(2, 1); // erase the static if you want to use two moduli;
    for (int k = 2, s = 2; k < n; k *= 2, s++) { // erase the static if you want to use two moduli;
        rt.resize(n);
        int z[] = {1, modpow(root, mod >> s, mod)};
        for (int i = k; i < 2*k; ++i) rt[i] = (ll)rt[i / 2] * z[i & 1] % mod;
    }
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; ++j) {
                int z = (ll)rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
                a[i + j + k] = ai - z + (z > ai ? mod : 0);
                ai += (ai + z >= mod ? z - mod : z);
            }
        }
    }
}
vector<int> conv(const vector<int> &a, ll p) {
    if (a.empty()) return {};
    int s = (int)a.size() + (a.size() - 1)* (p-1), B = 32 - __builtin_clz(s), n = 1 << B;
    int inv = modpow(n, mod - 2, mod);
    vector<int> L(a), out(n);
    L.resize(n);
    ntt(L);
    for (int i = 0; i < n; ++i) out[-i & (n - 1)] = modpow(L[i], p, mod) % mod * inv % mod;
    ntt(out);
    return {out.begin(), out.begin() + s};
}

void solve(int tc) {
    ll n, m;
    cin >> n >> m;

    vector<int> X(m + 1);
    vi fac(m*n + 1, 1);
    vi inv(m*n + 1, 1);
    for (int i = 1; i < fac.size(); i++)
    {
        fac[i] = (fac[i-1] * i) % mod;
    }

    inv[n*m] = modpow(fac[n*m], mod-2, mod);
    for (int i = n*m - 1; i >= 0; i--)
    {
        inv[i] = (i + 1) * inv[i+1] % mod;
    }
    
    
    for (int i = 0; i <= m; i++)
    {
        X[i] = inv[i];
    }
    
    auto Z = conv(X, n);   

    ll q; cin >> q;
    while (q--)
    {
        ll k; cin >> k;
        ll res = (fac[k] * Z[k]) % mod;
        cout << res << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("differences.in", "r", stdin);
    // freopen("island.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
} 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

const int MOD = 998244353;
const int LOG = 62;

ll fpow(ll base, ll exp) {
    base %= MOD;
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

ll mod_inverse(ll n) {
    return fpow(n, MOD - 2);
}

ll C[LOG][LOG];
// Precomputes Pascal's Triangle for Krawtchouk transformation
void precompute_combinations() {
    for (int i = 0; i < LOG; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

struct Basis {
    ll basis[LOG];
    ll cnt;

    Basis() {
        cnt = 0;
        clear();
    }

    void clear() {
        memset(basis, 0, sizeof basis);
        cnt = 0;
    }

    // Inserts a mask into the XOR Basis (RREF form handled during dual extraction)
    bool insert(ll mask) {
        for (int i = LOG - 1; ~i; --i) {
            if ((mask >> i) & 1) {
                if (!basis[i]) {
                    basis[i] = mask;
                    cnt++;
                    return true;
                }
                mask ^= basis[i];
            }
        }
        return false;
    }

    // Converts basis V to its Orthogonal Complement / Dual Basis V^perp of dimension (m - cnt)
    Basis get_dual_basis(int m) const {
        Basis dual_res;
        ll temp[LOG];
        for (int i = 0; i < LOG; i++) temp[i] = basis[i];

        // Step 1: Reduce matrix to Gauss-Jordan RREF
        for (int i = m - 1; i >= 0; i--) {
            if (!temp[i]) continue;
            for (int j = m - 1; j > i; j--) {
                if (temp[j] && ((temp[j] >> i) & 1)) {
                    temp[j] ^= temp[i];
                }
            }
        }

        // Step 2: Transpose free variables to construct V^perp
        for (int i = 0; i < m; i++) {
            if (!temp[i]) {
                ll mask = (1LL << i);
                for (int j = 0; j < m; j++) {
                    if (temp[j] && ((temp[j] >> i) & 1)) {
                        mask |= (1LL << j);
                    }
                }
                dual_res.insert(mask);
            }
        }
        return dual_res;
    }

    void dfs_popcounts(int idx, const vector<ll>& active, ll cur, vi& popcount_freq) const {
        if (idx == (int)active.size()) {
            popcount_freq[__builtin_popcountll(cur)]++;
            return;
        }
        dfs_popcounts(idx + 1, active, cur, popcount_freq);
        dfs_popcounts(idx + 1, active, cur ^ active[idx], popcount_freq);
    }

    // Brute forces all 2^cnt combinations of the basis to count subset popcounts
    vi count_subspace_popcounts() const {
        vi popcount_freq(LOG, 0);
        vector<ll> active;
        for (int i = 0; i < LOG; i++) {
            if (basis[i]) active.push_back(basis[i]);
        }
        dfs_popcounts(0, active, 0, popcount_freq);
        return popcount_freq;
    }
};

// Maps popcounts from dual basis space (V^perp) back to original space (V) using FWHT Krawtchouk polynomial
vi convert_dual_counts_to_original(const vi& dual_freq, int m, int orig_k) {
    vi orig_freq(m + 1, 0);
    ll inv_2_mk = mod_inverse(fpow(2, m - orig_k));

    for (int c = 0; c <= m; c++) {
        ll total_sum = 0;
        for (int j = 0; j <= m; j++) {
            if (!dual_freq[j]) continue;

            ll W_cj = 0;
            for (int x = 0; x <= c; x++) {
                ll term = (C[j][x] * C[m - j][c - x]) % MOD;
                if (x & 1) W_cj = (W_cj - term + MOD) % MOD;
                else W_cj = (W_cj + term) % MOD;
            }

            ll current_term = (dual_freq[j] % MOD * W_cj) % MOD;
            total_sum = (total_sum + current_term) % MOD;
        }
        orig_freq[c] = (total_sum * inv_2_mk) % MOD;
    }

    return orig_freq;
}

void solve() {
    ll n, m;
    if (!(cin >> n >> m)) return;

    Basis b;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }

    int orig_k = b.cnt;
    ll redundant_elements = n - orig_k;
    vi popcount_ans;

    // Meet-in-the-middle choice: search whichever basis space is smaller (k vs m - k)
    if (orig_k <= 26) {
        popcount_ans = b.count_subspace_popcounts();
    } else {
        Basis dual_b = b.get_dual_basis(m);
        vi dual_freq = dual_b.count_subspace_popcounts();
        popcount_ans = convert_dual_counts_to_original(dual_freq, m, orig_k);
    }

    // Account for redundant elements outside the basis
    ll redundant_multiplier = fpow(2, redundant_elements);
    for (int i = 0; i <= m; i++) {
        cout << (popcount_ans[i] * redundant_multiplier) % MOD << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_combinations();

    int t = 1;
    while (t--) solve();

    return 0;
}
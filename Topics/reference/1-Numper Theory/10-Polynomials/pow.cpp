vector<int> poly_pow(vector<int> poly, int p, int limit = 1e9) {
    vector<int> ans{1};
    while (p) {
        if(p&1) ans = conv(ans, poly);
        poly = conv(poly, poly);
        ans.resize(limit + 1);
        poly.resize(limit + 1);
        p >>= 1;
    }
    return ans;
}

// use in nnt
// make sure size (n) is enough
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

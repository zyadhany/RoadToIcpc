// Check if range [l, r] is is permutation of size r-l+1
// after getting Hashval of [l, r] we can just compare with PERM[r-l+1]
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MXN = 3e5+10;
ll F[MXN], PERM[MXN];

ll HashVal(vi &pref, ll l, ll r) {
    ll ans = pref[r];
    if (l) ans ^= pref[l - 1];
    return ans;
}

vi HashPrefix(vi &X) {
    int n = X.size();
    vi pref(n);
    pref[0] = F[X[0]];
    for (int i = 1; i < n; i++)
        pref[i] = (pref[i - 1] ^ F[X[i]]);
    return (pref);    
}

void INIT() {
    for (int i = 1; i < MXN; i++)
    {
        F[i] = uniform_int_distribution<ll>(0, (1ull << 63) - 1)(rng);
        PERM[i] = (F[i] ^ PERM[i - 1]);
    }
}


/* For High Value Map */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MXN = 3e5+10;
mi F({{0,0}});

ll HashVal(vi &pref, ll l, ll r) {
    ll ans = pref[r];
    if (l) ans ^= pref[l - 1];
    return ans;
}

vi HashPrefix(vi X) {
    int n = X.size();
    vi pref(n);
    for (int i = 0; i < n; i++)
    {
        auto it = F.find(X[i]);
        if (it == F.end()) F[X[i]] = uniform_int_distribution<ll>(0, (1ull << 63) - 1)(rng);
        X[i] = F[X[i]];
    }
    
    pref[0] = X[0];
    for (int i = 1; i < n; i++)
        pref[i] = (pref[i - 1] ^ X[i]);
    return (pref);    
}

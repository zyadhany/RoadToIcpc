const int HASED = 2;
const int MODHS[2] = {1000000007, 1000000009};
const int P[2] = {31, 37};
const int N = 1e6;
ll pw[2][N]{}, pwinv[2][N]{};

ll fpowr(ll b, ll exp, ll mod)
{
    if (!exp) return (1);
    ll ret = fpowr(b, exp >> 1, mod);
    ret = (ret * ret) % mod;
    if (exp & 1) ret *= b;
    return (ret % mod);
}


struct BIT
{
    int size;
    vi V;
    vector<ll> tree;

    int opp;
    void set(int index, int value) {
        index++;
        value -= 'a' - 1;
        value = (value * pw[opp][index]) % MODHS[opp];
        ll old_value = V[index]; V[index] = value;
        value = (value - old_value + MODHS[opp]) % MODHS[opp];
        for (; index <= size; index += index & -index) {
            tree[index] = (tree[index] + value) % MODHS[opp];
        }
    }
    ll getrange(int l, int r) {
        l++, r++; if (l > r) return 0;
        int stl = l;
        ll summ = 0;
                for (; r > 0; r -= r & -r) summ = (summ + tree[r]) % MODHS[opp];
                for (; l > 0; l -= l & -l) summ = (summ - tree[l]) % MODHS[opp];
        if (summ < 0) summ += MODHS[opp];
        return (summ * pwinv[opp][stl]) % MODHS[opp];
    }
    void build(string& X) {
        size = X.size();
        V.assign(size + 10, 0);
        tree.assign(size + 10, 0);
        for (int i = 0; i < size; i++) {
            set(i, X[i]);
        }
    }
};

pl HashVal(vector<BIT> &pref, ll l, ll r) {
    if (r < l) return {-1, -1};
    vi ans(HASED);
    for (int hs = 0; hs < HASED; hs++)
        ans[hs] = pref[hs].getrange(l, r) % MODHS[hs];
    return {ans[0], ans[1]};
}

void HashUpdate(vector<BIT> &pref, ll ind, ll val) {
    for (int hs = 0; hs < HASED; hs++) pref[hs].set(ind, val);
}

vector<BIT> HashPrefix(string &s) {
    int n = s.size();
    vector<BIT> pref(HASED);
    for (int hs = 0; hs < HASED; hs++){
        pref[hs].opp = hs;
        pref[hs].build(s);
    }
    return (pref);    
}

void INIT(){
    for (int i = 0; i < HASED; i++) pw[i][0] = pwinv[i][0] = 1;
    vi minv(HASED); 
    for (int i = 0; i < HASED; i++) minv[i] = fpowr(P[i], MODHS[i] - 2, MODHS[i]);

    for (int hs = 0; hs < HASED; hs++)
        for (int i = 1; i < N; i++)
        {
            pw[hs][i] = (pw[hs][i - 1] * P[hs]) % MODHS[hs];
            pwinv[hs][i] = (pwinv[hs][i - 1] * minv[hs]) % MODHS[hs];
        }
}

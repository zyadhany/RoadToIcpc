
const int MODHS = 1e9 + 7;
const int P = 31;
const int N = 1e6;
int pw[N], pwinv[N];

ll fpowr(ll b, ll exp, ll mod)
{
    if (!exp) return (1);
    ll ret = fpowr(b, exp >> 1, mod);
    ret = (ret * ret) % mod;
    if (exp & 1) ret *= b;
    return (ret % mod);
}

int HashVal(vi &pref, ll l, ll r) {
    int ans;
    ans = pref[r];
    if (l) ans = (ans - pref[l - 1] + MODHS) % MODHS;
    ans = (1ll * ans * pwinv[l]) % MODHS;
    return ans;
}

vi HashPrefix(string &s) {
    int n = s.size();
    vi pref(n);
    pref[0] = (s[0] - 'a' + 1) % MODHS;
    for (int i = 1; i < n; i++)
        pref[i] = (pref[i - 1] + (s[i] - 'a' + 1ll) * pw[i]) % MODHS;
    return (pref);    
}

void INIT(){
    pw[0]  = pwinv[0] = 1;
    int minv = fpowr(P, MODHS - 2, MODHS);
    for (int i = 1; i < N; i++)
    {
        pw[i] = (1ll*pw[i - 1] * P) % MODHS;
        pwinv[i] = (1ll*pwinv[i - 1] * minv) % MODHS;
    }
}

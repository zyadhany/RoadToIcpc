#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

const int HASED = 2;
const vi MODHS = {1000000007, 1000000009};
const vi P = {31, 37};
const int N = 1e6;
vii pw(2, vi(N)), pwinv(2, vi(N));

ll fpowr(ll b, ll exp, ll mod)
{
    if (!exp) return (1);
    ll ret = fpowr(b, exp >> 1, mod);
    ret = (ret * ret) % mod;
    if (exp & 1) ret *= b;
    return (ret % mod);
}

vi HashVal(vii &pref, ll l, ll r) {
    vi ans(HASED);
    for (int hs = 0; hs < HASED; hs++)
    {
        ans[hs] = pref[hs][r];
        if (l) ans[hs] = (ans[hs] - pref[hs][l - 1] + MODHS[hs]) % MODHS[hs];
        ans[hs] = (1ll * ans[hs] * pwinv[hs][l]) % MODHS[hs];
    }
    
    return (ans);
}

vii HashPrefix(string &s) {
    int n = s.size();
    vii pref(HASED, vi(n));
    for (int hs = 0; hs < HASED; hs++){
        pref[hs][0] = (s[0] - 'a' + 1) % MODHS[hs];
        
        for (int i = 1; i < n; i++)
        {
            ll a = (s[i] - 'a' + 1ll);
            pref[hs][i] = (pref[hs][i - 1] + a * pw[hs][i]) % MODHS[hs];
        }
    }
    return (pref);    
}

void INIT(){
    for (int i = 0; i < HASED; i++)
        pw[i][0] = pwinv[i][0] = 1;
    vi minv(HASED); 
    for (int i = 0; i < HASED; i++)
        minv[i] = fpowr(P[i], MODHS[i] - 2, MODHS[i]);

    for (int hs = 0; hs < HASED; hs++)
        for (int i = 1; i < N; i++)
        {
            pw[hs][i] = (pw[hs][i - 1] * P[hs]) % MODHS[hs];
            pwinv[hs][i] = (pwinv[hs][i - 1] * minv[hs]) % MODHS[hs];
        }
}


void solve(int tc) {
    ll n, x;
    string s;

    cin >> n >> x;
    cin >> s;

    string t = s;
    
    reverse(all(t));

    auto L = HashPrefix(s);
    auto R = HashPrefix(t);
    
    for (int i = 0; i <= n - x; i++)
    {
        auto l = HashVal(L, i, i + x - 1);
        ll at = n - (i + x);
        auto r = HashVal(R, at, at + x - 1);
        if (l == r) {
            cout << "leacary\n";
            return;
        }
    }
    
    cout << "dracarys\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    INIT();
    //freopen("balancing.in", "r", stdin);
    //freopen("balancing.out", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

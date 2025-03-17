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


void solve(int tc) {
    ll n;
    string s;

    cin >> s;

    n = s.size();
    auto HT = HashPrefix(s);
    for (int len = 1; len <= s.size(); len++)
    {
        bool isit = 1;
        ll hs = HashVal(HT, 0, len-1);
        ll ro = n / len;
        for (int i = 0; i < ro; i++)
        {
            ll re = HashVal(HT,i*len,(i+1)*len-1);
            if (re != hs) {isit = 0; break;};
        }
        if (n % len) {
            ll a = HashVal(HT, 0, n % len - 1);
            ll b = HashVal(HT, n - (n%len), n - 1);
            if (a != b) isit = 0;
        }        

        if (isit) cout << len << ' ';
    }   
}   
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    INIT();
    // freopen("barnpainting.in", "r", stdin);
    // freopen("barnpainting.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

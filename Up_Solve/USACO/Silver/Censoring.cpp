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

const int MODE = 1e9 + 9;


using namespace std;


const int MODHS = 1e9 + 7;
const int P = 37;
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
    string s, t;

    cin >> s >> t;

    vi HP;
    string res;

    ll hp = 0;
    for (int i = 0; i < t.size(); i++)
        hp = (hp + pw[i] * (t[i]-'a'+1ll)) % MODHS;
    
    for (auto a : s) {
        ll ad = (pw[res.size()] * (a - 'a' + 1ll)) % MODHS;
        if (!res.empty()) ad = (ad + HP.back()) % MODHS;
        HP.push_back(ad);
        res += a;
        if (res.size() < t.size()) continue;
       
        ll hs = HashVal(HP, res.size() - t.size(), res.size()-1);

        if (hs == hp) {
            for (int i = 0; i < t.size(); i++)
            {
                res.pop_back();
                HP.pop_back();
            }            
        }
    }

    cout << res << '\n';
}   
 

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    INIT();

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

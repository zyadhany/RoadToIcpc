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



int timer;
void dfs(vii &adj,string &s, vi &indeg, vi &outdeg, vi &height, vi &sz, ll n) {
    indeg[n] = timer++;
    s += "(";
    sz[n] = 1;
    height[n] = 0;
    for (auto neg : adj[n]) {
        dfs(adj, s, indeg, outdeg, height, sz, neg);
        sz[n] += sz[neg];
        height[n] = max(height[n], height[neg] + 1);
    }

    outdeg[n] = timer++;
    s += ")";
}

const int HASED = 2;
const ll MODHS[] = {1000000007, 1000000009};
const ll P[] = {31, 37};
const ll N = 1e6;
ll pw[2][N], pwinv[2][N];

ll fpowr(ll b, ll exp, ll mod)
{
    if (!exp) return (1);
    ll ret = fpowr(b, exp >> 1, mod);
    ret = (ret * ret) % mod;
    if (exp & 1) ret *= b;
    return (ret % mod);
}

pl HashVal(vii &pref, ll l, ll r) {
    vi ans(HASED);
    for (int hs = 0; hs < HASED; hs++)
    {
        ans[hs] = pref[hs][r];
        if (l) ans[hs] = (ans[hs] - pref[hs][l - 1] + MODHS[hs]) % MODHS[hs];
        ans[hs] = (1ll * ans[hs] * pwinv[hs][l]) % MODHS[hs];
    }
   
    return (pl(ans[0], ans[1]));
}

vii HashPrefix(string &s) {
    int n = s.size();
    vii pref(HASED, vi(n));
    for (int hs = 0; hs < HASED; hs++){
        pref[hs][0] = (s[0] - '(' + 11) % MODHS[hs];
        for (int i = 1; i < n; i++)
        {
            ll a = (s[i] - '(' + 11ll);
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
    ll n, m;

    cin >> n;

    vii adj(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        adj[i].resize(x);
        for (int j = 0; j < x; j++)
        {
            cin >> adj[i][j];
            adj[i][j]--;
        }
    }

    cin >> m;
    vii adj2(m);

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        adj2[i].resize(x);
        for (int j = 0; j < x; j++)
        {
            cin >> adj2[i][j];
            adj2[i][j]--;
        }
    }

    string s1 = "", s2 = "";
    vi indeg1(n), outdeg1(n), height1(n), sz1(n);
    vi indeg2(m), outdeg2(m), height2(m), sz2(m);
    timer = 0;
    dfs(adj, s1, indeg1, outdeg1, height1, sz1, 0);
    timer = 0;
    dfs(adj2, s2, indeg2, outdeg2, height2, sz2, 0);

    auto hs1 = HashPrefix(s1);
    auto hs2 = HashPrefix(s2);

    vector<map<pl, int>> mp1(max(n,m)+1), mp2(max(n,m)+1);
    for (int i = 1; i < n; i++)
    {
        auto hs = HashVal(hs1, indeg1[i], outdeg1[i]);
        mp1[sz1[i]][hs]++;
    }
    for (int i = 0; i < m; i++)
    {
        auto hs = HashVal(hs2, indeg2[i], outdeg2[i]);
        mp2[sz2[i]][hs]++;
    }
    
    ll cnt = 0;
    ll res = 0;
    for (int i = 0; i <= max(n, m); i++)
    {
        cnt += mp2[i].size();
        for (auto [hs, cnt2] : mp2[i]) {
            if (mp1[i].count(hs)) {
                res -= mp1[i][hs];
            }
        }
    }
    res += cnt * (2 * n - 1) + 1;
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
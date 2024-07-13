#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
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


typedef long long item;
class SegmentTree
{
public:
    int opp;

    void set(int index, int value) {
        set(0, 0, size - 1, index, value - 'a' + 1);
    }

    item getrange(int l, int r) {
        return ((getrange(0, 0, size - 1, l, r)) * pwinv[opp][l]) % MODHS[opp];
    }

    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item());
    }

    void build(string& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());

        build(X, 0, 0, size - 1);
    }
private:
    int size;
    vector<item> tree;

    item merge(item a, item b) {
        item res = (a + b) % MODHS[opp];
        return (res);
    }

    void set(int m, int lx, int rx, int pos, int val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = (val * pw[opp][pos]) % MODHS[opp];
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, pos, val);
        set(m * 2 + 2, mid + 1, rx, pos, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(string& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = ((X[lx] - 'a' + 1) * pw[opp][lx]) % MODHS[opp];
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }
};

pl HashVal(vector<SegmentTree> &pref, ll l, ll r) {
    if (r < l) return {-1, -1};
    vi ans(HASED);
    for (int hs = 0; hs < HASED; hs++)
        ans[hs] = pref[hs].getrange(l, r) % MODHS[hs];
    
    return {ans[0], ans[1]};
}

void HashUpdate(vector<SegmentTree> &pref, ll ind, ll val) {
    for (int hs = 0; hs < HASED; hs++)
        pref[hs].set(ind, val);
}

vector<SegmentTree> HashPrefix(string &s) {
    int n = s.size();
    vector<SegmentTree> pref(HASED);
    for (int hs = 0; hs < HASED; hs++){
        pref[hs].opp = hs;
        pref[hs].build(s);
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
    ll n;
    string s, t;

    cin >> n >> s;

    t = s;
    reverse(all(t));

    auto L = HashPrefix(s);
    auto R = HashPrefix(t);

    ll q; cin >> q;
    while (q--)
    {
        ll opp; cin >> opp;
        if (opp == 1) {
            ll ind; char c;
            cin >> ind >> c;
            ind--;
            HashUpdate(L, ind, c);
            HashUpdate(R, n - ind - 1, c);
        } else
        {
            ll a, b, len; cin >> a >> b;
            a--; b--, len = (b - a + 1) / 2;
    
            if (len <= 1) {
                cout << "YES\n";
                continue;
            } 

            ll re = n - b - 1;

            ll l, r, at;
            l = 0, r = len;
            while (l < r)
            {
                at = (l + r + 1) / 2;

                auto hl = HashVal(L, a, a + at - 1);
                auto hr = HashVal(R, re, re + at - 1);

                if (hl == hr) l = at;
                else r = at - 1;
            }
            //cout << l << ' ' << re << "|\n";
            if (l >= len - 1) {
                cout << "YES\n";
                continue;
            }

            auto hl = HashVal(L, a + l + 1, a + len - 1);
            auto hr = HashVal(R, re + l + 1, re + len - 1);

            if (hl == hr) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    INIT();
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

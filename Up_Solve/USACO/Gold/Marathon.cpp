#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
const int MODE = 998244353;

using namespace std;

struct item
{
    pl fs1, fs2, ls1, ls2;
    ll sol0, sol1;

    item(){
        fs1 = ls1 = fs2 = ls2 = {INT32_MAX, INT32_MAX};
        sol0 = sol1 = INT32_MAX;
    }

    item(pl p) {
        sol0 = 0;
        sol1 = INT32_MAX;
        fs1 = ls1 = p;
        fs2 = ls2 = {INT32_MAX, INT32_MAX};
    }
};

ll dis(pl a, pl b) {
    ll re = abs(b.first - a.first) + abs(a.second - b.second);
    return re;
}

class SegmentTree
{
public:

    void set(int index, item value) {
        set(0, 0, size - 1, index, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, 0);
    }

    void build(vector<item>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, 0);

        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item a, item b) {
        if (a.fs1.first == INT32_MAX) return b;
        if (b.fs1.first == INT32_MAX) return a;
        item res;
        res.sol0 = a.sol0 + b.sol0 + dis(a.ls1, b.fs1);

        if (a.fs2.first == INT32_MAX) {
            a.fs2 = b.fs1;
        } else  {
            ll re = b.sol0 + a.sol0 - dis(a.ls1, a.ls2) + dis(a.ls2, b.fs1);
            res.sol1 = min(res.sol1, re);
        }

        if (b.fs2.first == INT32_MAX) {
            b.ls2 = a.ls1;
        } else  {
            ll re = b.sol0 + a.sol0 - dis(b.fs1, b.fs2) + dis(a.ls1, b.fs2);
            res.sol1 = min(res.sol1, re);
        }

        res.sol1 = min(res.sol1, a.sol1 + b.sol0 + dis(a.ls1, b.fs1));
        res.sol1 = min(res.sol1, a.sol0 + b.sol1 + dis(a.ls1, b.fs1));

        res.fs1 = a.fs1, res.fs2 = a.fs2;
        res.ls1 = b.ls1, res.ls2 = b.ls2;
        return (res);
    }

    void set(int m, int lx, int rx, int pos, item val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = val;
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
        if (rx < l || r < lx) return (item());
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<item>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = X[lx];
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


const int MXN = 1e6+10;
void solve(int tc) {
    ll n, q;
    
    cin >> n >> q;

    vector<item> X(n);

    for (int i = 0; i < n; i++)
    {
        pl p; cin >> p.first >> p.second;
        X[i] = item(p);
    }
    
    SegmentTree sg; sg.build(X);

    while (q--)
    {
        char ty; cin >> ty;

        if (ty == 'Q') {
            ll l, r; cin >> l >> r; l--, r--;
            auto re = sg.getrange(l, r);
            cout << min(re.sol0, re.sol1) << '\n';
        } else {
            ll ind, x, y; cin >> ind >> x >> y; ind--;
            sg.set(ind, item({x, y}));
        }
    }
    
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
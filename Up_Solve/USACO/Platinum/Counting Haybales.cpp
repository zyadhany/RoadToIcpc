#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
using namespace std;
 
const int MODE = 1e9+7;

struct item {
    ll sum, mn;
    item(){
        sum = 0, mn = INT32_MAX;
    }
    item(ll n){
        sum = mn = n;
    }
};

class SegmentTree
{
public:
    void set(int l, int r, int value) {
        set(0, 0, size - 1, l, r, value);
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

    void build(vi& X) {
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

    item merge(item &a, item &b) {
        item res;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        return (res);
    }

    void checkLazy(int m, int lx, int rx) {
        if (!lazy[m]) return;
        tree[m].sum += lazy[m] * (rx-lx+1);
        tree[m].mn += lazy[m];
        
        if (lx != rx) {
            lazy[2 * m + 1] += lazy[m];
            lazy[2 * m + 2] += lazy[m];
        }

        lazy[m] = 0;
    }

    void set(int m, int lx, int rx, int l, int r, int val) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return;
        if (l <= lx && rx <= r)
        {
            lazy[m] = val;
            checkLazy(m, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, l, r, val);
        set(m * 2 + 2, mid + 1, rx, l, r, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return item();
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = item(X[lx]);
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


void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    SegmentTree sg;
    sg.build(X);

    while (q--)
    {
        char ty; cin >> ty;
        ll l, r; cin >> l >> r; l--, r--;

        if (ty == 'M') cout << sg.getrange(l, r).mn << '\n';
        else if (ty == 'S') cout << sg.getrange(l, r).sum << '\n';
        else {
            ll k; cin >> k;
            sg.set(l, r, k);
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}

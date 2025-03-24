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
 
const int MODE = 1e9 + 7;

using namespace std;


struct item
{
    int l, r, mx, sz;

    item(){
        l = r = mx = sz = 0;
    }
    item(ll v){
        l = r = mx = sz = v;
    }
};

class SegmentTree
{
public:

    ll get(ll value) {
        if (tree[0].mx < value) return -1;
        return get(0, 0, size - 1, value);
    }
    void set(int l, int r, ll v) {
        set(0, 0, size - 1, l, r, v);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item(0));
        lazy.assign(size * 2, -1);
    }

// private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item a, item b) {
        item res;
        res.mx = max(a.mx, b.mx);
        res.mx = max(res.mx, a.r + b.l);
        res.l = a.l;
        res.r = b.r;
        res.sz = a.sz + b.sz;
        if (a.l == a.sz) res.l += b.l;
        if (b.r == b.sz) res.r += a.r;
        return (res);
    }

    void checkLazy(int m, int lx, int rx) {
        if (lazy[m] == -1) return;
        tree[m].mx = tree[m].l = tree[m].r = (rx-lx+1)* lazy[m];
        tree[m].sz = rx - lx + 1;
        if (lx != rx) {
            lazy[2 * m + 1] = lazy[m];
            lazy[2 * m + 2] = lazy[m];
        }

        lazy[m] = -1;
    }

    ll get(int m, int lx, int rx, int val) {
        checkLazy(m, lx, rx);
        if (rx == lx)
        {
            return rx;
        }
        
        int mid = (lx + rx) / 2;
        ll s1 = m * 2 + 1;
        ll s2 = m * 2 + 2;
        checkLazy(s1, lx, mid);
        checkLazy(s2, mid + 1, rx);

        if (tree[s1].mx >= val) {
            return get(s1, lx, mid, val);
        } else if (tree[s1].r + tree[s2].l >= val) {
            return mid + val - tree[s1].r;
        } else{
            return get(s2, mid+1, rx, val);
        }
    }

    void set(int m, int lx, int rx, int l, int r, ll v) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return;
        if (l <= lx && rx <= r)
        {
            lazy[m] = v;
            checkLazy(m, lx, rx);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, l, r, v);
        set(m * 2 + 2, mid + 1, rx, l, r, v);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return item(0);
        if (l <= lx && rx <= r) {
            return (tree[m]);
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }
};


void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    SegmentTree sg;
    sg.build(n);
    sg.set(0, n - 1, 1);

    ll cnt = 0;
    while (q--)
    {
        char t; cin >> t;
        if (t == 'A') {
            ll k; cin >> k;
            ll re = sg.get(k);
            if (re == -1) cnt++;
            else sg.set(re-k+1, re, 0);
        } else {
            ll l, r; cin >> l >> r; l--, r--;
            sg.set(l, r, 1);
        }
    }

    cout << cnt << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

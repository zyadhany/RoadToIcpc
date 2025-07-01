#include "bits/stdc++.h"

#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define int ll
#define pl pair<ll, ll>
#define vp vector<pl>
using namespace std;



typedef vi item;

class SegmentTree
{
public:

    void set(int index, ll value) {
        set(0, 0, size - 1, index, value);
    }

    ll getrange(int l, int r) {
        auto v = getrange(0, 0, size-1, l, r);
        ll mx = 0;
        for (auto a : v) mx = max(mx, mx^a);
        return mx;
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
        item res = a;
        for (auto x : b) {
            for (int i = 0; i < (int)res.size(); i++) {  
                x = min(x, x ^ res[i]);
            }
            if (x) res.push_back(x);
        } 
        return (res);
    }

    void set(int m, int lx, int rx, int pos, ll val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = {val};
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
        if (rx < l || r < lx) return {};
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = {X[lx]};
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


void solve() {
    ll n, q;

    cin >> n >> q;

    vi X(n);

    vector<set<ll>> bt(18);
    cout << (1<<17) << '\n';
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        for (int j = 0; j < 18; j++)
            if ((X[i]>>j)&1) bt[j].insert(i);        
    }
    
    SegmentTree sg;
    sg.build(X);
    
    while (q--)
    {
        ll ty; cin >> ty;
        if (ty == 1) {
            ll l, r, x; cin >> l >> r >> x; l--, r--;
            for (int i = 0; i < 18; i++)
            {
                if (!(x&(1<<i))) {
                    auto it = bt[i].lower_bound(l);
                    while (it != bt[i].end() && *it <= r)
                    {
                        X[*it] &= x;
                        sg.set(*it, X[*it]);
                        bt[i].erase(it);
                        it = bt[i].lower_bound(l);
                    }
                }
            }
        } else if (ty == 2) {
            ll ind, x; cin >> ind >> x;
            for (int i = 0; i < 18; i++)
                if (bt[i].count(ind)) bt[i].erase(ind);
            X[ind] = x;
            sg.set(ind, x);
            for (int j = 0; j < 18; j++)
                if ((x>>j)&1) bt[j].insert(ind);     
        } else {
            ll l, r; cin >> l >> r;
            l--, r--;
            cout << sg.getrange(l, r) << '\n';
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
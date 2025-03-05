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


/**
 * usage:-
 * creat tree element.
 * SegmentTree sg;
 * 
 * Functions you can use:
 * @set: set index or range to value.
 * @geteange: get value of given range.
 * @build: build tree with given vector or size.
 * 
 * make sure to look at item typedef.
 * you can change merge function to change it's oppration.
 * it you want to make change to segment work in checkLazy().
*/

typedef long long item;
/*
struct item
{
    int val;

    item(){
        val = 0;
    }
};
*/

class SegmentTree
{
public:

    void set(int index, int value) {
        set(0, 0, size - 1, index, value);
    }
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
        item res = a + b;
        return (res);
    }

    void checkLazy(int m, int lx, int rx) {
        if (lazy[m] == -1) return;
        tree[m] += lazy[m] * (rx - lx + 1);
        
        if (lx != rx) {
            lazy[2 * m + 1] = lazy[m];
            lazy[2 * m + 2] = lazy[m];
        }

        lazy[m] = -1;
    }

    void set(int m, int lx, int rx, int pos, int val) {
        checkLazy(m, lx, rx);
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
        if (rx < l || r < lx) return (0);
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


vp MonomaticStack(vi& X)
{
    ll n = X.size();
    stack<pair<ll, ll>> s;
    vp Z(n, {-1, n});

    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top().first > X[i]) {
            Z[s.top().second].second = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }
    while (!s.empty()) s.pop();
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && s.top().first >= X[i]) {
            Z[s.top().second].first = i;
            s.pop();
        }
        s.push({ X[i] , i });
    }

    return (Z);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n);
    vi Y(n);
    vp M(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        M[i] = {X[i], i};
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> Y[i];
    }
    
    SegmentTree sg;
    sg.build(n);
    sort(M.rbegin(), M.rend());
    auto Z = MonomaticStack(X);

    for (auto [v, ind] : M) {
        if (v > 0) {
            sg.set(ind, ind, v);
            continue;
        }

        ll l = INT32_MAX, r = INT32_MAX;
        if (Z[ind].first != -1) l = sg.getrange(Z[ind].first + 1, ind);
        if (Z[ind].second != n) l = sg.getrange(ind, Z[ind].second-1);

        if (min(l, r) + v >= 0) sg.set(ind, ind, v);
        else if (l < r) sg.set(l + 1, ind, 0);
        else sg.set(ind, r - 1, 0);
        cout << sg.getrange(0, n-1) << '\n';
    }

}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("dishes.in", "r", stdin);
    // freopen("dishes.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

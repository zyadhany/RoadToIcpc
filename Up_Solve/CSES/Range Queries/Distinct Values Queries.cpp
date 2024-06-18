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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;


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
        if (!lazy[m]) return;
        tree[m] += lazy[m];
        
        if (lx != rx) {
            lazy[2 * m + 1] += lazy[m];
            lazy[2 * m + 2] += lazy[m];
        }

        lazy[m] = 0;
    }

    void set(int m, int lx, int rx, int pos, int val) {
        checkLazy(m, lx, rx);
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] += val;
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

void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n + 1);
    vii Q(q + 1, vi(3));
    vi res(q + 1);
    mi Y;
    set<pl> st;
    SegmentTree sg;
    sg.build(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    

    for (int i = 1; i <= q; i++) {
        cin >> Q[i][0] >> Q[i][1];
        Q[i][2] = i;
        st.insert({Q[i][0], -i});
        st.insert({Q[i][1], i});
    }
    ll at = 1;    

    for (auto m : st) {
        while (m.first >= at)
        {
            ll re = X[at];
            if (Y[re])  sg.set(Y[re], -1);
            Y[re] = at;
            sg.set(at, 1);
            at++;
        }
        int ind = m.second;
        if (ind > 0) res[ind] = sg.getrange(Q[ind][0], m.first);
    }


    for (int i = 1; i <= q; i++)
        cout << res[i] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

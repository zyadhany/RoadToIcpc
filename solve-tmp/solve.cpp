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
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;

struct trie_node
{
    ll val;
    ll num;
    vector<int> next;

    trie_node() {
        val = -1;
        next.resize(2, -1);
    }
};

class Trie
{
public:
    ll get(ll n) {
        return (get(0, n, SIZE - 1));
    }

    void add(ll n, ll val) {
        add(0, n, SIZE - 1, val);
    }

    Trie() {
        tree.resize(1, trie_node());
    }
private:
    int SIZE = 32;
    vector<trie_node> tree;

    ll get(ll at, ll n, ll k) {
        if (k == -1) return (0);
        int re =  (n >> k) & 1;
        if (tree[at].next[re] != -1 && tree[at].val >= 2) return get(tree[at].next[re], n, k - 1);
        return (get(tree[at].next[!re], n, k - 1) | (1 << k));
    }

    void add(ll at, ll n, ll k, ll val) {
        if (k == -1) {
            return;
        }
        tree[at].val += val;
        tree[at].num = n;
        
        int re = (n >> k) & 1;

        if (tree[at].next[re] == -1) {
            tree[at].next[re] = tree.size();
            tree.push_back(trie_node());
        }

        add(tree[at].next[re], n, k - 1, val);
    }
};


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

struct item
{
    ll val;
    vi arr;
    Trie tr;

    item(){
        val = 0;
    }

    item(ll n){
        val = INT32_MAX;
        arr.assign(1, n);
        tr.add(n);
    }
};

class SegmentTree
{
public:

    void set(int index, int value) {
        set(0, 0, size - 1, index, value);
    }

    ll getrange(int l, int r) {
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
        item res = a;
        for (int i = 0; i < b.arr.size(); i++) {
            ll k = b.tr.get(a.arr[i]);
            res.val = min(res.val, k);
            res.arr.push_back(b.arr[i]);
            res.tr.add(b.arr[i]);
        }
        return (res);
    }


    void set(int m, int lx, int rx, int pos, int val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = item(val);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, pos, val);
        set(m * 2 + 2, mid + 1, rx, pos, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    ll getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return (INT32_MAX);
        if (l <= lx && rx <= r) return (tree[m].val);

        int mid = (lx + rx) / 2;
        ll s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return min(s1, s2);
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

void solve(ll tc) {
    ll n, q, re;

    cin >> n;

    vi X(n);
    SegmentTree sg;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sg.build(X);

    cin >> q;
    while (q--)
    {
        ll opp, l, r;
        cin >> opp >> l >> r;

        if (opp == 1) {
            re = sg.getrange(l - 1, r - 1);
            cout << re << '\n';
        }else {
            sg.set(l - 1, r);
        }
    }
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

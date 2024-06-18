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

//typedef long long item;
struct item
{
    ll val, mx, l, r;
    item(){
        val = mx = l = r = 0;
    }

    item(ll n){
        val = mx = l = r = max(n, 0ll);
        val = n;
    }
};

class SegmentTree
{
public:

    void set(int index, int value) {
        set(0, 0, size - 1, index, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(vector<ll>& X) {
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
        item res;
        res.l = max(a.l, a.val + b.l);
        res.r = max(b.r, b.val + a.r);
        res.val = a.val + b.val;

        res.mx = max(res.l, res.r);
        res.mx = max(res.mx, a.r + b.l);
        res.mx = max(res.mx, max(a.mx, b.mx));

        return (res);
    }


    void set(int m, int lx, int rx, int pos, int val) {
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
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<ll>& X, int m, int lx, int rx) {
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
    ll n, q;

    cin >> n >> q;

    vi X(n + 1);
    SegmentTree sg;

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    sg.build(X);

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        sg.set(l, r);
        cout << sg.getrange(1, n).mx << '\n';
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

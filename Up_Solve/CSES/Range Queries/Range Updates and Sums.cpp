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

typedef long long item;

class SegmentTree
{
public:
    void set(int l, int r, pl value) {
        set(0, 0, size - 1, l, r, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(vector<item>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        lazy.assign(size * 2, {0, 0});

        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<pl> lazy;

    item merge(item a, item b) {
        item res = a + b;
        return (res);
    }

    void checkLazy(int m, int lx, int rx) {
        if (!lazy[m].second && !lazy[m].first) return;
        ll summ = (rx - lx + 1) * lazy[m].first;
        if (!lazy[m].second) summ += tree[m];
        
        tree[m] = summ;
        
        if (lx != rx) {
            if (lazy[m].second) {
                lazy[2 * m + 1] = lazy[m];
                lazy[2 * m + 2] = lazy[m];
            }else {
                lazy[2 * m + 1].first += lazy[m].first;
                lazy[2 * m + 2].first += lazy[m].first;
            }
        }

        lazy[m] = {0, 0};
    }

    void set(int m, int lx, int rx, int l, int r, pl val) {
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
    SegmentTree sg, inc;

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    sg.build(X);

    while (q--)
    {
        ll opp, l, r, val;
        cin >> opp >> l >> r;

        if (opp == 3) cout << sg.getrange(l, r) << '\n';
        else {
            cin >>  val;
            sg.set(l, r, {val, opp - 1});
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

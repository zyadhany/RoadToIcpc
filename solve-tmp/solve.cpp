// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}

using namespace std;

const int MODE = 1e9+7;
const ll INF = 1e16;



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

    void set(int index, ll value) {
        set(0, 0, size - 1, index, value);
    }
    void set(int l, int r, ll value) {
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
        item res = (a*b)%MODE;
        return (res);
    }

    void checkLazy(int m, int lx, int rx) {
        if (!lazy[m]) return;
        tree[m] = lazy[m];
        
        if (lx != rx) {
            lazy[2 * m + 1] += lazy[m];
            lazy[2 * m + 2] += lazy[m];
        }

        lazy[m] = 0;
    }

    void set(int m, int lx, int rx, int pos, ll val) {
        checkLazy(m, lx, rx);
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = (tree[m] * val) % MODE;
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, pos, val);
        set(m * 2 + 2, mid + 1, rx, pos, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    void set(int m, int lx, int rx, int l, int r, ll val) {
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
        if (rx < l || r < lx) return (1);
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

SegmentTree sg;
const int N = 1e5+10;

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n+1), Y(n+1);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i+1];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> Y[i+1];
    }
    
    vii adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vii> Q(n+1);
    for (int i = 0; i < q; i++)
    {
        ll u, l, r; cin >> u >> l >> r;
        Q[u].push_back({i, l, r});
    }

    vi res(q);
    vi S(n+1);
    function<ll(ll, ll)> dfs2 = [&](ll u, ll p) -> ll {
        ll sz = 1;
        for (auto neg : adj[u]) if (neg != p) {
            sz += dfs2(neg, u);
        }
        return sz;
    };

    sg.build(N);
    function<vp(ll, ll)> dfs = [&](ll u, ll p) -> vp {
        vp Z(1, {X[u], Y[u]});
        sg.set(1, N-1, 1);
        cout << u << ' ' << sg.getrange(2, 2) << "||\n";
        sg.set(Y[u], X[u]);
        sort(all(adj[u]), [&](ll a, ll b) {
            return S[a] < S[b];
        });

        vector<vp> K(adj[u].size());
        ll at = 0;
        for (auto neg : adj[u]) if (neg != p) {
            sg.set(1, N-1, 1);
            K[at] = dfs(neg, u);
            swap(Z, K[at]);
            at++;
        }
        for (auto &H : K) {
            if (Z.size() < H.size()) swap(H, Z);
            for (auto a : H) Z.push_back(a);

            for (auto [a, b] : H) {
                // sg[b] -> a
                sg.set(b, a);
            }
        }
        // if (u == 3) 
        
        for (auto &H : Q[u]) {
            ll ind = H[0], l = H[1], r = H[2];
            // res[ind] = sg[l,r];
            res[ind] = sg.getrange(l, r);
        }
        return Z;
    };
    dfs2(1, 0);
    dfs(1, 0);

    for (auto a: res) cout << a << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
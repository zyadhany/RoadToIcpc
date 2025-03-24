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
#define int long long

using namespace std;


typedef long long item;

const ll INF = 1e16;

class SegmentTree
{
public:

    void set(int index, ll value) {
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
        tree.assign(size * 2, INF);
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
        item res = min(a, b);
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

    void set(int m, int lx, int rx, int pos, ll val) {
        checkLazy(m, lx, rx);
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = min(tree[m], val);
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
        if (rx < l || r < lx) return (INF);
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

struct query
{
    ll x, y, ty, ind;
    query(){}
    query(ll xa, ll ya, ll tya, ll inda) {
        x = xa, y = ya, ty = tya, ind = inda;
    }
    bool operator<(const query &q) {
        if (x != q.x) return x < q.x;
        if (y != q.y) return y < q.y;
        if (ind == q.ind) return ty > q.ty;
        return ty < q.ty;
    }
};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    set<ll> st;
    vector<pair<pl, pl>> X(m+1);
    X[m] = {{n,n}, {n,n}};
    for (int i = 0; i < m; i++)
    {
        ll a, b , c, d;
        cin >> a >> b >> c >> d;
        X[i] = {{a, b}, {c, d}};
        st.insert({a, b, c, d});
    }
    
    st.insert({0, n});
    vi IND(st.size());
    mi CO;
    for (auto a : st) {
        IND[CO.size()] = a;
        CO[a] = CO.size();
    }
    
    n = CO[n];
    vector<query> Q;
    for (int i = 0; i <= m; i++) {
        ll &x1 = X[i].first.first, &y1 = X[i].first.second;
        ll &x2 = X[i].second.first, &y2 = X[i].second.second;
        x1 = CO[x1], y1 = CO[y1];
        x2 = CO[x2], y2 = CO[y2];

        Q.push_back(query(x1, y1, 1, i));
        Q.push_back(query(x2, y2, 0, i));
    }

    sortx(Q);
    vi dis(m+1);
    SegmentTree sg; sg.build(st.size() + 10);
    sg.set(CO[0], 0);
    for (auto q : Q) {
        if (q.ty == 0) {
            dis[q.ind] = min(dis[q.ind], sg.getrange(0, q.y) + IND[q.x] + IND[q.y]);
            sg.set(q.y, dis[q.ind]-IND[q.x]-IND[q.y]);
        } else {
            dis[q.ind] = sg.getrange(0, q.y) + IND[q.x] + IND[q.y];
        }
    }

    cout << dis[m] << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

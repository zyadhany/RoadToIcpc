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
private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item &a, item &b) {
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
};


struct query
{
    ll l, r, x, ty;
    query(){}
    query(ll la, ll ra, ll xa, ll tya) {
        l = la;
        r = ra;
        x = xa;
        ty = tya;
    }
    bool operator<(const query& q) {
        if (l != q.l) return l < q.l;
        return ty < q.ty;
    }
};

const int MXN = 1e9+10;
 
void sol(vector<query> &Q, vi &res, vi &COV, ll n) {
    sortx(Q);
    SegmentTree sgl, sgr;
    sgl.build(n);
    sgr.build(n);
    for (auto q : Q) {
        ll a = COV[q.l];
        ll b = COV[q.r];
        if (q.ty == 0) {
            sgl.set(q.r, q.x+b-a); 
            sgr.set(q.r,q.x-b-a);
        } else {
            ll l = sgl.getrange(q.r, n-1)-b+a;
            ll r = sgr.getrange(0, q.r)+b+a;
            ll re = min(l, r);
            res[q.x] = min(res[q.x], re);
        }
    } 
}


void solve(int tc) {
    ll n, m;
 
    cin >> n >> m;

    vi RF;
    
    vector<query> Q;
    for (int i = 0; i < n; i++)
    {
        ll l, r, t; cin >> l >> r >> t;
        Q.push_back(query(l, r, t, 0));
        RF.push_back(l);
        RF.push_back(r);
    }
    
    vi res(m);
    for (int i = 0; i < m; i++)
    {
        ll l, r; cin >> l >> r;
        RF.push_back(l);
        RF.push_back(r);
        res[i] = abs(r - l);
        Q.push_back(query(l, r, i, 1));
    }
    
    set<ll> st(all(RF));
    unordered_map<ll, ll> CO;
    vi COV;
    for (auto a : st) {
        COV.push_back(a);
        CO[a]=CO.size();
    }
    for (auto &q : Q) q.l = CO[q.l], q.r = CO[q.r];
    ll sz = st.size() * 2;
    for (int i = COV.size() - 1; i >= 0; i--)
    {
        COV.push_back(1e9-COV[i]);
    }
    
    sol(Q, res, COV, sz);
    for (auto &q : Q) {
        q.l = sz - 1 - q.l;
        q.r = sz - 1 - q.r;
        swap(q.l, q.r);
    }
    sol(Q, res, COV, sz);
    for (auto &q : Q) {
        swap(q.l, q.r);
    }
    sol(Q, res, COV, sz);
    
    for (auto a : res) cout << a << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    // freopen("slingshot.in", "r", stdin);
    // freopen("slingshot.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}

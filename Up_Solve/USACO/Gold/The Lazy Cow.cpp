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


typedef long long item;

class SegmentTree
{
public:
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
private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item &a, item &b) {
        item res = max(a, b);
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
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }
};

const int MXV = 2e5+10;

 
struct query
{
    ll l, r1, r2, x;
    query(){}
    query(ll la, ll ra, ll ra2, ll xa) {
        l = la;
        r1 = ra;
        r2 = ra2;
        x = xa;
    }
    bool operator<(const query& q) {
        if (l != q.l) return l < q.l;
        return x < q.x;
    }
};
void solve(int tc) {
    ll n, k; cin >> n >> k;

    k *= 2;
    vector<query> Q;
    for (int i = 0; i < n; i++)
    {
        ll l, r, v;
        cin >> v >> l >> r;
        l *= 2, r *= 2;

        ll l1, l2, r1, r2;

        l1 = l-k+r;
        r1 = MXV -l-k + r -1 ;
        l2 = l+k+r;
        r2 = MXV-l+k+r-1;


        Q.push_back(query(l1, r1, r2, v));
        Q.push_back(query(l2+1, r1, r2, -v));
    }
    sortx(Q);

    SegmentTree sg;
    sg.build(2*MXV);

    ll mx = 0;
    for (auto q : Q) {
        sg.set(q.r1,q.r2, q.x);
        mx = max(mx, sg.getrange(0, 2*MXV-1));
    }

    cout << mx << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}

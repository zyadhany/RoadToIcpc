#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 1e9+7;


struct Matrix {
    ll a[2][2]={0};
    Matrix(){
        a[0][0] = a[1][0] = a[1][1] = a[0][1] = 0;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
    
    pl operator*(const pl &b) const {
        return {(b.first * a[0][0]+ b.second * a[0][1])%MODE,
        (b.first * a[1][0]+ b.second * a[1][1])%MODE};
    }
};  

Matrix matrixpower(Matrix a, ll n) {
    Matrix res;
    for (int i = 0; i < 2; i++)
    {
        res.a[i][i] = 1;
    }
        
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

Matrix fibbase;
const pl fibzer = {0, 1};
typedef pl item;
class SegmentTree
{
public:
    void set(int l, int r, int value) {
        set(0, 0, size - 1, l, r, value);
    }
 
    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }
 
    void build(vector<ll>& X) {
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
        item res = {(a.first + b.first)%MODE, (a.second + b.second)%MODE};
        return (res);
    }
 
    void checkLazy(int m, int lx, int rx) {
        if (!lazy[m]) return;
        tree[m] = matrixpower(fibbase, lazy[m]) * (tree[m]);
        
        if (lx != rx) {
            lazy[2 * m + 1] += lazy[m];
            lazy[2 * m + 2] += lazy[m];
        }
        
        lazy[m] = 0;
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
        
        set(m * 2 + 1, lx, mid, l, r, val);
        set(m * 2 + 2, mid + 1, rx, l, r, val);
        
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }
    
    item getrange(int m, int lx, int rx, int l, int r) {
        checkLazy(m, lx, rx);
        if (rx < l || r < lx) return (item());
        if (l <= lx && rx <= r) return (tree[m]);
        
        int mid = (lx + rx) / 2;
 
        item s1 = getrange(m * 2 + 1, lx, mid, l, r);
        item s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);
        
        return merge(s1, s2);
    }
    
    void build(vector<ll>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) {
                tree[m] = matrixpower(fibbase, X[lx]-1)*fibzer;
            }
            return;
        }
 
        int mid = (lx + rx) / 2;
 
        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }
};

void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    vi X(n);

    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
    }
    
    fibbase.a[1][0] = fibbase.a[1][1] = fibbase.a[0][1] = 1;
    SegmentTree sg;
    sg.build(X);

    
    while (q--)
    {
        ll ty; cin >> ty;
        if(ty == 1) {
            ll l, r, k; cin >> l >> r >> k; l--, r--;
            sg.set(l, r, k);
        } else {
            ll l, r; cin >> l >> r; l--, r--;
            auto re = sg.getrange(l, r);
            cout << re.second << '\n';
        }
    }
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

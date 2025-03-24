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

using namespace std;

struct item
{
    ll sol, a, b;
    item(){
        sol = a = b = 0;
    }

    item(pl k) {
        sol = 0;
        a = k.first, b = k.second;
    }
};

class SegmentTree
{
public:

    void set(int index, pl v) {
        set(0, 0, size - 1, index, v);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(int n, bool high) {
        ishigh = high;
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
    ll ishigh;

    item merge(item &a, item &b) {
        item res;
        ll tok;
        if (ishigh) tok = min(a.a, b.b);
        else tok = min(a.b, b.a);
        res.sol = a.sol + b.sol + tok;
        res.a = a.a + b.a - tok;
        res.b = a.b + b.b - tok;
        return res;
    }

    void set(int m, int lx, int rx, int pos, pl v) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = item(v);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, pos, v);
        set(m * 2 + 2, mid + 1, rx, pos, v);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return (item());
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;

        item s1 = getrange(m * 2 + 1, lx, mid, l, r);
        item s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }
};


const int MXN = 1e6+10;
void solve(int tc) {
    ll n;

    cin >> n;

    vi freq(2 * n + 1);
    vi X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        freq[X[i]] = 1;
    }
    
    vi Y;
    for (int i = 0; i < 2*n; i++)
    {
        if (!freq[i + 1]) Y.push_back(i + 1);
    }
    
    SegmentTree sgl, sgr;
    sgl.build(n*2+1, 1), sgr.build(n*2+1, 0);

    for (auto a : X) sgr.set(a, {1, 0});
    for (auto a : Y) sgr.set(a, {0, 1});
    
    
    sort(Y.rbegin(), Y.rend());
    
    ll sol = sgr.getrange(1, 2*n).sol;
    for (int i = 0; i < n; i++)
    {
        sgr.set(Y[i], {0, 0});
        sgr.set(X[i], {0, 0});
        sgl.set(Y[i], {0, 1});
        sgl.set(X[i], {1, 0});
        ll re = sgl.getrange(1, 2*n).sol + sgr.getrange(1, 2*n).sol;
        sol = max(sol, re);
    }
    sol = max(sol, sgl.getrange(1, 2*n).sol);

    cout << sol << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
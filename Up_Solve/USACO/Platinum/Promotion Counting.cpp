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
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

/**
 * Lowest Common Ancestor (LCA) in O(1) Time Complexity
 * We can use euler tour tequnique but adding node with it's depth with every visit.
 * The LCA of two nodes is the node with the smallest depth that lies in the subtree of both nodes.
 * We can use Sparse Table to find Minimum in range in O(1) time complexity.
 */
class Graph {
public:
    int timer;
    int size, SPSIZE;
    vi vis, Indeg, lvl, ST, Outdeg;
    vii adj;
    vp Trav;
    vector<vp> table;

    void dfs(int n, int p, ll deep) {
        lvl[n] = deep;
        ST[n] = timer++;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n, deep + 1);
            Trav.push_back({deep, n});
        }
        Outdeg[n] = timer - 1;
    }

    void BuildLCA() {
        dfs(1, 0, 1);
        ll n = Trav.size();
        SPSIZE = ceil(log2(n));
        table.resize(n, vp(SPSIZE + 1));
        for (int i = 0; i < n; i++)
            table[i][0] = Trav[i];
        
        for (int j = 1; j <= SPSIZE; j++)
            for (int i = 0; i <= n - (1 << j); i++)
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
    }

    ll LCA(ll a, ll b) {
        ll l = Indeg[a], r = Indeg[b];
        if (l > r) swap(l, r);
        int j = (int)log2(r - l + 1); 
        return min(table[l][j], table[r - (1 << j) + 1][j]).second;
    }

    ll dist(ll a, ll b) {
        return lvl[a] + lvl[b] - 2 * lvl[LCA(a, b)];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        timer = 1;
        size = n;
        lvl.resize(n + 1, 0);
        ST.assign(n + 1, 0);
        Outdeg.assign(n + 1, 0);
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


const long long INF = 1e18;
struct item
{
    vi arr;

    item() {
    }
};

class SegmentTree
{
public:

    ll getrange(int l, int r, ll k) {
        return (getrange(0, 0, size - 1, l, r, k));
    }

    void set(int ind, ll val) {
        set(0, 0, size - 1, ind, val);
    }

    void build(vi& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;

    ll getitemval(item& a, ll k) {
        auto it = upper_bound(all(a.arr), k) - a.arr.begin();
        it = a.arr.size() - it;
        return (it);
    }

    item merge(item& a, item& b) {
        item res = a;
        for (auto v : b.arr) res.arr.push_back(v);
        sortx(res.arr);
        return (res);
    }

    void set(int m, int lx, int rx, int ind, ll val) {

    }

    ll getrange(int m, int lx, int rx, int l, int r, ll k) {
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (getitemval(tree[m], k));

        int mid = (lx + rx) / 2;
        ll s1, s2, res;

        s1 = getrange(m * 2 + 1, lx, mid, l, r, k);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r, k);

        return (s1 + s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size())
                tree[m].arr.push_back(X[lx]);
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


void solve(int tc) {
    ll n;

    cin >> n;

    vi X(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i + 1];
    }
    
    Graph gr(n);
    for (int i = 2; i <= n; i++)
    {
        ll v; cin >> v;
        gr.addEdge(v, i);
    }
    
    gr.BuildLCA();
    vi Z(gr.timer);
    for (int i = 1; i <= n; i++)
    {
        Z[gr.ST[i]] = X[i];
    }
    
    SegmentTree sg; sg.build(Z);

    for (int i = 1; i <= n; i++)
    {
        ll re = sg.getrange(gr.ST[i], gr.Outdeg[i], X[i]);
        cout << re << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

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

class Graph {
public:
    int size, SPSIZE;
    vi vis, Indeg, Outdeg, lvl, VAL;
    vp Trav;
    vector<vp> table;

    void dfs( const vector<vp> &adj, int n, int p, ll deep, ll we) {
        VAL[n] = we;
        lvl[n] = deep;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        for (auto [neg, w] : adj[n]) {
            if (neg == p) continue;
            dfs(adj, neg, n, deep + 1, we + w);
            Trav.push_back({deep, n});
        }
        Outdeg[n] = Trav.size()-1;
    }

    void BuildLCA(const vector<vp> &adj) {
        dfs(adj, 1, 0, 1, 0);
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

    Graph(ll n, const vector<vp> &adj) {
        size = n;
        lvl.resize(n + 1, 0);
        Indeg.assign(n + 1, 0);
        Outdeg.assign(n + 1, 0);
        VAL.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        BuildLCA(adj);
    }
};

typedef long long item;
class SegmentTree
{
public:

    void set(int l, int r, ll value) {
        set(0, 0, size - 1, l, r, value);
    }

    item get(int l) {
        return (getrange(0, 0, size - 1, l, l));
    }
    void build(vi& X) {
        size = 1;
        while (size < X.size())
        size *= 2;
        tree.assign(size * 2, item());
        cout << size << "|" << endl;
        lazy.assign(size * 2, 0);
        
        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    item merge(item &a, item &b) {
        item res = a + b;
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

    void build(vi& X, int m, int lx, int rx) {
        cout << lx << ' ' << rx << endl;
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

 
void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    vii E;
    vector<vp> adj(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        E.push_back({u,v,w});
    }
    
    vi X(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v , w; cin >> u >> v >> w;
        X[u] = w;
        E.push_back({u, v, w});
    }
    
    Graph gr(n, adj);

    vi Z(n+1);
    for (int i = 1; i <= n; i++)
    {
        Z[gr.Indeg[i]] = gr.VAL[i];
    }
    
    SegmentTree sg;
    sg.build(Z);
    cout << "|" << endl;
    return;

    while (q--)
    {
        ll ty, l, r; cin >> ty >> l >> r;
        if (ty == 1) {
            l--;
            if (l <= n-1) {
                ll dif = r - E[l][2];
                sg.set(gr.Indeg[E[l][1]], gr.Outdeg[E[l][1]], dif);
                E[l][2] = r;
            } else {
                X[E[l][0]] = r;
            }
        } else {
            ll lc = gr.LCA(l, r);
            ll re;
            if (lc == l) {
                re  = sg.get(gr.Indeg[r]);
                re -= sg.get(gr.Indeg[l]);
            } else {
                re = X[l] + sg.get(gr.Indeg[r]);
            }

            cout << re << '\n';
        }     
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}

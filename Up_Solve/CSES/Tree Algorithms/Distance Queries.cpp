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
    int size, SPSIZE;
    vi vis, Indeg, lvl;
    vii adj;
    vp Trav;
    vector<vp> table;

    void dfs(int n, int p, ll deep) {
        lvl[n] = deep;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n, deep + 1);
            Trav.push_back({deep, n});
        }
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
        size = n;
        lvl.resize(n + 1, 0);
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    Graph gr(n);

    for (int i = 2; i <= n; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
        gr.addEdge(v, u);
    }
    
    gr.BuildLCA();
    while (q--)
    {
        ll a, b; cin >> a >> b;
        cout << gr.dist(a, b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("hopscotch.in", "r", stdin);
    // freopen("hopscotch.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

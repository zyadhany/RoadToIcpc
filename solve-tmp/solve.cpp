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
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9+7;

using namespace std;

class Graph {
public:
    int size;
    vi vis, lvl;
    vii adj, SPT;


    void BuildSparse(ll node=1, ll parent=0){
        lvl[node] = lvl[parent] + 1;
        SPT[node][0] = parent;
        for (int i = 1; i < SPT[node].size(); i++)
            SPT[node][i] = SPT[SPT[node][i - 1]][i - 1];        
        for (auto neg : adj[node])
            if (neg != parent) BuildSparse(neg, node);
    }

    ll getKth(ll u, ll k){
        for (int i = 0; i < SPT[u].size(); i++)
            if ((1 << i) & k) u = SPT[u][i];
        return (u);
    }

    ll LCA(ll u, ll v) {
        if (lvl[u] > lvl[v]) swap(u, v);
        v = getKth(v, lvl[v] - lvl[u]);
        if (u == v) return (u);
        for (int i = SPT[u].size() - 1; i >= 0; i--)
        {
            if (SPT[u][i] != SPT[v][i]){
                u = SPT[u][i], v = SPT[v][i];
            }
        }
        return (SPT[u][0]);
    }

    ll dist(ll u, ll v) {
        ll p = LCA(u , v);
        return (lvl[u] + lvl[v] - 2 * lvl[p]);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n, vii &adj) : adj(adj) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        SPT.resize(n + 1, vi(ceil(log2(n + 1)) + 1));
        BuildSparse(1, 0);
    }
};

ll fp(ll a, ll b) {
    ll res = 1;
    while (b)
    {
        if (b&1) res = (res * a) % MODE;
        a = (a * a) % MODE;
        b >>= 1;
    }
    return res;
}

ll inv(ll n) {
    return fp(n, MODE-2);
}

void solve(int tc) {
    ll n, m, q;
    cin >> n >> m >> q;

    vi V(n+1);
    for (int i = 0; i < m; i++)
    {
        ll a; cin >> a; V[a] = 1;
    }
    
    vii adj(n+1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Graph gr(n, adj);

    vi P(n+1);
    function<void(ll, ll, ll)> dfs = [&](ll u, ll p, ll nx) -> void {
        P[u] = nx;
        if (V[u]) nx = u;
        for (auto neg : adj[u]) if (neg != p) dfs(neg, u, nx);
    };
    dfs(1, 0, 0);

    vi prf(n+10);
    for (int i = 1; i < prf.size(); i++)
    {
        prf[i] = (inv(i) + prf[i-1]) % MODE;
    }
    for (int i = 1; i < prf.size(); i++)
    {
        prf[i] = (prf[i] + prf[i-1]) % MODE;
    }
    
    auto calc = [&](ll l, ll r) -> ll {
        ll summ = 0;
        // for (int i = 0; i <= l; i++)
        // {
        //     for (int j = 1; j <= r; j++)
        //     {
        //         summ = (summ + inv(j+i)) % MODE;
        //     }
        // }
        summ = prf[r+l] - prf[r-1] - prf[l];
        summ = (summ%MODE + MODE) % MODE;
        return summ;
    };
    while (q--)
    {
        ll u, v; cin >> u >> v;
        ll lc = gr.LCA(u, v);

        vi Z;
        ll at = u;
        while (gr.lvl[at] >= gr.lvl[lc])
        {
            if (V[at]) Z.push_back(gr.lvl[u]-gr.lvl[at]);
            at = P[at];
        }
        at = v;
        while (gr.lvl[at] > gr.lvl[lc])
        {
            if (V[at]) Z.push_back(gr.lvl[u]-gr.lvl[lc]+gr.lvl[at]-gr.lvl[lc]);
            at = P[at];
        }
        ll len = gr.dist(u, v)+1;
        ll sol = 0;
        for (auto a : Z) sol = (sol + calc(a, len-a)) % MODE;
        // for (auto a : Z) cout << a << ' ';
        // cout << "|\n";
        cout << sol << '\n';
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 1e9+7;

class Graph {
public:
    int size, SPSIZE;
    vi Indeg, lvl;
    vi P;
    vp Trav;
    vector<vp> table;

    void dfs( const vii &adj, int n, int p, ll deep) {
        lvl[n] = deep;
        P[n] = p;
        Indeg[n] = Trav.size();
        Trav.push_back({deep, n});
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(adj, neg, n, deep + 1);
            Trav.push_back({deep, n});
        }
    }

    void BuildLCA(const vii &adj) {
        dfs(adj, 1, 0, 1);
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

    Graph(ll n, const vii &adj) {
        size = n;
        P.resize(n + 1, 0);
        lvl.resize(n + 1, 0);
        Indeg.assign(n + 1, 0);
        BuildLCA(adj);
    }
};

void solve(int tc) {
    ll n, q, st, en;

    cin >> n >> q >> st >> en;

    vii adj(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
       
    Graph g(n, adj);

    auto getpath = [&](ll a, ll b) -> vi {
        vi Z;
        ll lc = g.LCA(a, b);
        while (a != lc) {
            Z.push_back(a);
            a = g.P[a];
        }
        Z.push_back(lc);
        vi tmp;
        while (b != lc) {
            tmp.push_back(b);
            b = g.P[b];
        }
        reverse(all(tmp));
        for (auto x : tmp) Z.push_back(x);
        return Z;
    };

    vii forb(n+1, vi(1, 0));

    while (q--) {
        ll a, b;
        cin >> a >> b;
        vi P = getpath(a, b);
        for (int i = 0; i < P.size(); i++)
        {
             forb[P[i]].push_back(i+1);
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        sortx(forb[i]);
    }
    auto Z = getpath(st, en);
    
    ll m = Z.size();
    vector<vp> AV(m);
    AV[0] = {{1, 3*n}};
    if (forb[st].size() > 1) {
        AV[0][0].second = forb[st][1]-1;
    }

    cout << AV[0][0].first << ' ' << AV[0][0].second << '\n';
    for (int i = 1; i < m; i++)
    {
        if (AV[i-1].empty()) continue;
        for (int j = 1; j < forb[Z[i]].size(); j++)
        {
            ll r = forb[Z[i]][j]-1;
            ll l = forb[Z[i]][j-1] + 1;
            if (l > r) continue;
            ll ind = lower_bound(all(AV[i-1]), pl(l, 0)) - AV[i-1].begin();

            if (ind > 0 && AV[i-1][ind-1].second >= l-1) {
                AV[i].push_back({l, r});
            } else if (ind < AV[i-1].size() && AV[i-1][ind].first < r) {
                AV[i].push_back({AV[i-1][ind].first+1, r});
            } 
        }
        ll r = 3*n;
        ll l = forb[Z[i]].back() + 1;
        ll ind = lower_bound(all(AV[i-1]), pl(l, 0)) - AV[i-1].begin();
        
        if (ind > 0 && AV[i-1][ind-1].second >= l-1) {
            AV[i].push_back({l, r});
        } else if (ind < AV[i-1].size() && AV[i-1][ind].first < r) {
            AV[i].push_back({AV[i-1][ind].first+1, r});
        } 
        
        cout << Z[i] << "|\n";
        for (auto x : AV[i]) {
            cout << x.first << " " << x.second << '\n';
        }
        cout << "-----------------" << endl;
    }
    
    if (AV[m-1].empty()) MUN;
    cout << AV[m-1][0].first << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("kangaroo.in", "r", stdin);
    // freopen("kangaroo.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
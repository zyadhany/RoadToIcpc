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

/**
 * Kosaraju’s algorithm: it about 2 dfs search.
 * 1: get order of node of it's outdegree.
 * 2: reverse order and all edge then start dfs
      and each node to reach is connected component.
 */
class Graph {
public:
    int size;
    vi vis;
    vii adj, radj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void dfs(vii &adjlist, vi &visited, vi &X, ll n) {
        if (visited[n]) return;
        visited[n] = 1;
        for (auto neg : adjlist[n]) dfs(adjlist, visited, X, neg);
        X.push_back(n);
    }

    vii stronglyConnectedComponents () {
        vii res;
        vi nodeOrder, visited(size + 1);
        for (int i = 1; i <= size; i++) dfs(adj, visited, nodeOrder, i);
        
        visited.assign(size + 1, 0);
        for (int i = nodeOrder.size() - 1; i >= 0; i--)
        {
            int ind = nodeOrder[i];
            if (visited[ind]) continue;
            vi Y;
            dfs(radj, visited, Y, ind);
            res.push_back(Y);
        }
        
        for (int i = 1; i <= size; i++) dfs(adj, visited, nodeOrder, i);        
        return (res);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
        radj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, m;
    cin >> n >> m;

    Graph gr(n);
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
    }
    
    auto Z = gr.stronglyConnectedComponents();
    
    vi X(n+1);
    for (int i = 0; i < Z.size(); i++)
    {
        for (auto a : Z[i]) X[a] = i + 1;
    }
    
    cout << Z.size() << '\n';
    for (int i = 1; i <= n; i++) cout << X[i] << ' ';
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
  
    // INIT();
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

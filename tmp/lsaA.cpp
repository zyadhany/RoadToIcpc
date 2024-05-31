#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

typedef ll item;


class Graph {
public:
    int size;
    vi vis, lvl;
    vii adj, SPT;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void BuildSparse(ll node, ll parent){
        lvl[node] = lvl[parent] + 1;
        SPT[node][0] = parent;
        for (int i = 1; i < SPT[node].size(); i++)
            SPT[node][i] = SPT[SPT[node][i - 1]][i - 1];        
        for (auto neg : adj[node]) BuildSparse(neg, node);
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

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
        SPT.resize(n, vi(ceil(log2(n)) + 1));
    }
};


void solve(int tc) {
    ll n, m, u, v;
 
    cin >> n;

    Graph gr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> u;
            gr.addEdge(i, u);
        }
    }

    cin >> m;
    gr.BuildSparse(0, 0);

    while (m--)
    {
        cin >> u >> v;
        cout << gr.LCA(u, v) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

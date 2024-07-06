#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;

class Graph 
{
public:
    int size;
    vi vis, val;
    vector<vp> adj;
    vector<vp> adjr;
    ll sol = 0;

    ll dfs(vi &X, ll dist, ll n, vector<vp> &add) 
    {
    	if (n == dist) X[n] = 0;
        if (X[n] != INT32_MIN) return X[n];
        X[n] = -1;
        for (auto neg : add[n]) 
        {
            dfs(X, dist, neg.second, add);
        	if(X[neg.second]!=-1)
            X[n] = max(X[n], neg.first + X[neg.second]);
        }
        return X[n];
    }

    void addEdge(int u, int v, ll k) 
    {
        adj[u].push_back({k, v});
        adjr[v].push_back({k, u});
    }

    Graph(ll n) 
    {
        size = n;
        vis.assign(n + 1, 0);   
        val.assign(n + 1, 0);
        adj.resize(n + 1);
        adjr.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, m, q;

    cin >> n >> m >> q;

    Graph gr(n);

    for (int i = 0; i < m; i++)
    {
       ll u, v, k;
       cin >> u >> v >> k;
       gr.addEdge(u, v, k);
    }
    
    vi L(n + 1, INT32_MIN), R(n + 1, INT32_MIN);
    for (int i = 1; i <= n; i++)
    {
        gr.dfs(L, 1, i, gr.adjr);
        gr.dfs(R, n, i, gr.adj);
    }

    while (q--)
    {
        ll k;
        cin >> k;
        if (L[k] == -1 || R[k] == -1) cout << "-1\n";
        else cout << L[k] + R[k] << '\n';
    }  
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

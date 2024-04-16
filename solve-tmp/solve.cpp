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

vi Z;

class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(ll n) {
        if (vis[n]) return;
        vis[n] = 1;
        for (auto neg : adj[n]) DFS(neg);
        Z.push_back(n);
    }

    bool isCyclicUtil(vector<bool> &visited, vector<bool> &recStack, int n, int p)
    {
        if (visited[n]) return false;
        visited[n] = recStack[n] = true;
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            if (recStack[neg]) return (true);
            if (isCyclicUtil(visited, recStack, neg, n)) return true;
        }
        return (recStack[n] = false);
    }

    
    bool isCyclic()
    {
        vector<bool> visited(size + 1), recStack(size + 1);
        for (int i = 1; i <= size; i++)
            if (!visited[i]) if(isCyclicUtil(visited, recStack, i, -1))
                return true;
        return false;
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, m, l, r;

    cin >> n >> m;

    mi X;
    Graph gr(n);

    if (n == 0 && n == m) exit(0);

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        gr.addEdge(l, r);
        X[r] = 1;
    }

    if (gr.isCyclic()) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    Z.clear();
    for (int i = 1; i <= n; i++)
        if (!X[i]) gr.DFS(i);
    for (int i = Z.size() - 1; i >= 0; i--)
        cout << Z[i] << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; ; i++) {
        solve(i);
    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll int
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

class Graph {
public:
    int size;
    vi vis, val;
    vii adj;
    ll sol = 0;

    void dfs(ll n, ll p) {
        if (vis[val[n]]) sol--, vis[val[n]] = 0;
        vis[val[n]]++;
        sol++;
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n);
        }
        vis[val[n]] = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        val.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n;

    cin >> n;

    Graph gr(n);

    for (int i = 1; i <= n; i++)
        cin >> gr.val[i];

    for (int i = 0; i < n - 1; i++)
    {
        ll l, r;
        cin >> l >> r;
        gr.addEdge(l, r);
        gr.addEdge(r, l);
    }
    
    gr.dfs(1, 0);
    cout << gr.sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

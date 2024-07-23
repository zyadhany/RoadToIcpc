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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
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
    vi vis;
    vii adj;
    bool isgood;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        isgood = 0;
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, k;

    cin >> n >> k;

    Graph gr(n);

    for (int i = 1; i <= n; i++)
        cin >> gr.vis[i];

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        gr.addEdge(u, v);
        gr.addEdge(v, u);
    }
       
    if (gr.isgood) YES;
    NO;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

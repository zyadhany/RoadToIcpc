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

class Graph
{
public:
    int size;
    vii adj;

    void addedge(ll u, ll v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(vi &Z, ll n, ll p, ll k) {
        Z[n] = k;
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(Z, neg, n, k + 1);
        }
    }

    Graph(ll n) {
        size = n;
        adj.resize(n + 1);
    }
};



void solve(int tc) {
    ll n, k;
    cin >> n >> k;

    Graph gr(n);
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        gr.addedge(u, v);
    }
    
    vi Z(n + 1);
    gr.dfs(Z, 1, 0, 1);
    ll re, mx;
    mx = re = -1;

    for (int i = 1; i <= n; i++)
    {
        if (Z[i] > mx) mx = Z[i], re = i;
    }

    gr.dfs(Z, re, 0, 1);
    ll cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (Z[i] > mx) mx = Z[i], re = i, cnt = 1;
        else if (Z[i] == mx) cnt++;    
    }
        
    ll summ;

    if (cnt <= k) summ = k - cnt;
    else summ = k, mx++;

    summ += mx % 2;
    cout << summ << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
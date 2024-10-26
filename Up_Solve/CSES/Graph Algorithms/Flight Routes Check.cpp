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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

void dfs(vii &adj, vi &vis, ll n) {
    if (vis[n]) return;
    vis[n] = 1;
    for (auto neg : adj[n]) dfs(adj, vis, neg);
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);
    vii radj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    
    vi vis(n + 1), rvis(n + 1);
    dfs(adj, vis, 1);    
    dfs(radj, rvis, 1);    
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) {
            cout << "NO\n";
            cout << "1 " << i << '\n';
            return;
        }
        
        if (!rvis[i]) {
            cout << "NO\n";
            cout << i << " 1" << '\n';
            return;
        }
    }
    
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("fenceplan.in", "r", stdin);
    //freopen("fenceplan.out", "w", stdout);
    
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

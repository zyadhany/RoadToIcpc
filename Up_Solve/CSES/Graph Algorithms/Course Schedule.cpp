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

const int MODE = 998244353;

using namespace std;

bool dfs(vii &adj, vi &Z, vi &vis, ll n) {
    if (vis[n] == 1) return 1;
    if (vis[n] == -1) return 0;
    vis[n] = -1;

    for (auto neg : adj[n])
        if (!dfs(adj, Z, vis, neg)) return 0; 

    Z.push_back(n);
    vis[n] = 1;
    return 1;
}

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    vi vis(n + 1);
    vi Z;
    for (int i = 1; i <= n; i++)
    {
        if (!dfs(adj, Z, vis, i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    
    reverse(all(Z));
    for (auto a : Z) cout << a << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("tractor.in", "r", stdin);
    // freopen("tractor.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

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
 
const int MODE = 1e9;
 
using namespace std;

map<pl, ll> ed;

bool req(vector<vp> &adj, vii &radj, vi &vis, vi &edvis, ll n, ll p) {
    if (vis[n]) return 0;
    vis[n] = 1;
    ll cnt = 0;

    for (auto [neg, id] : adj[n]) {
        if (edvis[id]) continue;
        edvis[id] = 1;
        ll re = req(adj, radj, vis, edvis, neg, n);

        if (re) radj[neg].push_back(n);
        else {
            cnt++;
            radj[n].push_back(neg);
        }
    }

    return cnt % 2;
}

void solve(int tc) {
    ll n, m; cin >> n >> m;

    vector<vp> adj(n + 1);
    vii radj(n + 1);

    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    
    vi vis(n + 1);
    vi edvis(m + 1);
    for (int i = 1; i <= n; i++) {
        if (req(adj, radj, vis, edvis, i, 0)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (auto neg : radj[i]) {
            cout << i << ' ' << neg << '\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("clocktree.in", "r", stdin);
    // freopen("clocktree.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

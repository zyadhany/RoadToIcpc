#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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

using namespace std;
 
const int MODE = 998244353;

const int MXN = 2e5+10;
int sz[MXN];

void dfs(vii &adj, ll n, ll p) {
    sz[n] = 1;
    for (auto neg : adj[n]) if (neg != p ){
        dfs(adj, neg, n); sz[n] += sz[neg];
    }
}

ll req(vii &adj, ll n, ll p) {
    for (auto neg : adj[n]) if (neg != p) if (sz[neg] > (adj.size()-1)/2) {
        return req(adj, neg, n);
    }
    return n;
}

void solve(ll tc) {
    ll n; cin >> n;

    vii adj(n + 1);

    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }
    dfs(adj, 1, 0);
    cout << req(adj, 1, 0) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

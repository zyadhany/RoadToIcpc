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
const int MXN = 5e4+10, MXL = 20; 


int PAR[MXN];

pair<set<ll>, multiset<ll>> req(vii &adj, vii &X, vi &Z, vi &dp, ll n, ll p) {
    PAR[n] = p;
    pair<set<ll>, multiset<ll>> res;
    for (auto a : X[n]) {
        res.first.insert(a);
        res.second.insert(Z[a]);
    }
    
    for (auto neg : adj[n]) if (neg != p) {
        auto re = req(adj, X, Z, dp, neg, n);
        
        if (res.first.size() < re.first.size()) swap(re, res);
        
        // cout << n << ' ' << p << ' ' << neg << "|" << endl;
        for (auto a : re.first) {
            if (res.first.count(a)) res.first.erase(a), res.second.erase(res.second.find(Z[a]));
            else res.first.insert(a), res.second.insert(Z[a]); 
        }
    }
    
    if (res.second.empty()) dp[n] = -1;
    else dp[n] = *res.second.begin();
    return res;
}


void solve(ll tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);
    vp edg;

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v ; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edg.push_back({u, v});
    }

    vii X(n + 1);
    vi Z(m);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        X[u].push_back(i);
        X[v].push_back(i);
        Z[i] = w;
    }
    
    vi dp(n + 1);
    req(adj, X, Z, dp,1, 0);
    

    for (auto [u, v] : edg) {
        if (PAR[u] == v) swap(u, v);
        cout << dp[v] << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("disrupt.in", "r", stdin   );
    freopen("disrupt.out", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

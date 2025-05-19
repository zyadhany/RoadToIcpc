#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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


struct graph {
    vi vis, lvl, prf;
    vii adj, dfsadj, backedge;
    vp bridges;

    ll dfstree(ll n=1, ll p=0) {
        lvl[n] = lvl[p] + 1;
        vis[n] = 1;

        ll v = 0;
        for (auto neg : adj[n]) if (neg != p) {
            if (vis[neg]) {
                if (lvl[neg] < lvl[n]) {
                    prf[n]++, prf[neg]--;
                    backedge[n].push_back(neg);
                }
            } else {
                dfsadj[n].push_back(neg);
                v += dfstree(neg, n);
            }
        }
        
        v += prf[n];
        if (!v && p != 0) bridges.push_back({n, p});
        return v;
    }

    graph(ll n): adj(n+1), dfsadj(n+1), vis(n+1), lvl(n+1)
    , backedge(n+1), prf(n+1) {}
};


void solve(int tc) {
    ll n, m;
    cin >> n >> m;

    graph gr(n);
    for (int i = 0; i < m; i++)
    {
        ll u, v; cin >> u >> v;
        gr.adj[u].push_back(v);
        gr.adj[v].push_back(u);
    }

    gr.dfstree();

    if (!gr.bridges.empty()) {
        cout << "0\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        for (auto neg : gr.dfsadj[i]) cout << i << ' ' << neg << '\n';
        for (auto neg : gr.backedge[i]) cout << i << ' ' << neg << '\n';       
    }
    
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
  
    // INIT();
    // freopen("lazy.in", "r", stdin);
    // freopen("lazy.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}

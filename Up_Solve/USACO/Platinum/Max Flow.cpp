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
const int MXN = 2e5+10, MXL = 20; 

class Graph {
    public:
        int size;
        vi vis, lvl;
        vii adj, SPT;
    
        ll req(vi &dp, ll n, ll p) {
            ll mx = dp[n];

            for (auto neg : adj[n]) if (neg != p) {
                mx = max(mx, req(dp, neg, n));
                dp[n] += dp[neg]; 
            }

            mx = max(mx, dp[n]);
            return mx;
        }
    
        void BuildSparse(ll node=1, ll parent=0){
            lvl[node] = lvl[parent] + 1;
            SPT[node][0] = parent;
            for (int i = 1; i < SPT[node].size(); i++)
                SPT[node][i] = SPT[SPT[node][i - 1]][i - 1];        
            for (auto neg : adj[node])
                if (neg != parent) BuildSparse(neg, node);
        }
    
        ll getKth(ll u, ll k){
            for (int i = 0; i < SPT[u].size(); i++)
                if ((1 << i) & k) u = SPT[u][i];
            return (u);
        }
    
        ll LCA(ll u, ll v) {
            if (lvl[u] > lvl[v]) swap(u, v);
            v = getKth(v, lvl[v] - lvl[u]);
            if (u == v) return (u);
            for (int i = SPT[u].size() - 1; i >= 0; i--)
            {
                if (SPT[u][i] != SPT[v][i]){
                    u = SPT[u][i], v = SPT[v][i];
                }
            }
            return (SPT[u][0]);
        }
    
        ll dist(ll u, ll v) {
            ll p = LCA(u , v);
            return (lvl[u] + lvl[v] - 2 * lvl[p]);
        }
    
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        Graph(ll n) {
            size = n;
            vis.assign(n + 1, 0);
            lvl.assign(n + 1, 0);
            adj.resize(n + 1);
            SPT.resize(n + 1, vi(ceil(log2(n + 1)) + 1));
        }
    };
    

void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    Graph gr(n);

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
    }
    
    gr.BuildSparse(1, 0);
    vi dp(n + 1);

    while (q--)
    {
        ll u, v; cin >> u >> v;
        ll p = gr.LCA(u, v);
        dp[u]++, dp[v]++;
        dp[p]--; dp[gr.getKth(p, 1)]--;
    }
    
    cout << gr.req(dp, 1, 0) << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    freopen("maxflow.in", "r", stdin   );
    freopen("maxflow.out", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

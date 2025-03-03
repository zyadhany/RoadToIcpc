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
 
const int MODE = 1e9 + 7;
 
using namespace std;
 
class Graph {
    public:
        int n;
        vi vis;
        vii adj;
    
        void addEdge(int u, int v) {
            adj[u].push_back(v);
        }
 
        vi TopologicalSort() {
            vi X, vis(n + 1);
            vi indeg(n + 1);
            
            for (int i = 1; i <= n; i++)
                for (auto neg : adj[i]) indeg[neg]++;
            
            priority_queue<ll, vi, greater<ll>> q;
            for (int i = 1; i <= n; i++) if (!indeg[i]) q.push(i);
        
            while (!q.empty())
            {
                ll tp = q.top();
                q.pop();
                X.push_back(tp);
                for (auto neg : adj[tp]) {
                    indeg[neg]--;
                    if (!indeg[neg]) q.push(neg);
                }
            }
        
            if (X.size() != n) return vi();
            return (X);
        }
    
        Graph(ll n) {
            this->n = n;
            vis.assign(n + 1, 0);
            adj.resize(n + 1);
        }
    };
    
 
void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vii adj(n + 1);

    vi indeg(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        indeg[u]++;
    }

    priority_queue<ll> pq;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) pq.push(i);

    ll at = n;
    vi leble(n + 1);

    while (!pq.empty())
    {
        ll tp = pq.top();
        leble[tp] = at;
        at--;
        pq.pop();

        for (auto neg : adj[tp]) {
            indeg[neg]--;
            if (indeg[neg] == 0) pq.push(neg);
        }
    }

    vi tps(n + 1);
    for (int i = 1; i <= n; i++)
        tps[leble[i]] = i;

    for (int i = 1; i <= n; i++)
        cout << tps[i] << ' ';
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    
    // freopen("milkorder.in", "r", stdin);
    // freopen("milkorder.out", "w", stdout);
        
    // cin >> size;
    for (int i = 1; i <= size; i++)
    solve(i);
}

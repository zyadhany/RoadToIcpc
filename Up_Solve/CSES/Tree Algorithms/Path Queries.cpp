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
    int size;
    vii adj;
    vi Indeg, Outdeg, X;
    int Timer;
 
    // each element from [Indeg[n], Outdeg[n]] is a subtree of node n
    void dfs(int n, int p) {
        X[n] += X[p];
        Indeg[n] = Timer++;
        for (auto neg : adj[n])
            if (neg != p) dfs(neg, n);
        Outdeg[n] = Timer - 1;
    }
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    Graph(ll n) {
        Timer = 1;
        size = n;
        Indeg.assign(n + 1, 0);
        X.assign(n + 1, 0);
        Outdeg.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};
 
 
ll rangequery(const vi& Z, ll ind) {
	ll summ = 0;
	for (int i = ind; i > 0; i -= i & -i)
		summ = (summ + Z[i]);
    return summ;
}
 
void updaterange(vi& Z, ll val, int l, ll r) {
	for (int i = l; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] + val);
    
    for (int i = r+1; i < Z.size(); i += i & -i)
		Z[i] = (Z[i] - val);
}
 
void solve(int tc) {
    ll n, q;
 
    cin >> n >> q;
 
    Graph gr(n);
    vi val(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i + 1];
        gr.X[i + 1] = val[i + 1];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        ll u, v; cin >> u >> v;
        gr.addEdge(u, v);
    }
    gr.dfs(1, 0);
    
    vi X(n + 10);
    for (int i = 1; i <= n; i++)
    {
        X[gr.Indeg[i]] = gr.X[i];
    }
    
    vi BIT(n + 10);

    for (int i = 1; i <= n; i++)
    {
        updaterange(BIT, X[i], i, i);
    }

    while (q--)
    {
        ll ty; cin >> ty;

        if (ty == 1) {
            ll ind, v; cin >> ind >> v;
            ll re = v - val[ind];
            val[ind] = v;
            updaterange(BIT, re, gr.Indeg[ind], gr.Outdeg[ind]);
        } else {
            ll ind; cin >> ind;
            cout << rangequery(BIT, gr.Indeg[ind]) << '\n';
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("hopscotch.in", "r", stdin);
    // freopen("hopscotch.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
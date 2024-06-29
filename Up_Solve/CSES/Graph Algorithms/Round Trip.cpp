#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
 
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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
const int MODE = 1e9 + 7;
 
using namespace std;
 
class Graph {
public:
    int size;
    vi vis, colorArr;
    vii adj;
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
 
    vi dfs(vi &Y, ll n, ll p) {
        if (vis[n] == -1) {
            vi X;
            X.push_back(n);
            while (Y.back() != n)
            {
                X.push_back(Y.back());
                Y.pop_back();
            }
            X.push_back(n);
            return (X);
        }
        if (vis[n]) return vi();
        vis[n] = -1;
        Y.push_back(n);
        for (auto neg : adj[n]) {
            if (neg != p) {
                vi X = dfs(Y, neg, n); 
                if (!X.empty()) return (X);
            }
        } 
        Y.pop_back();
        vis[n] = 1;
        return vi();
    }

    vi findCircule() {
        vi X, Y;
        for (int i = 1; i <= size; i++) {
            X = dfs(Y, i, 0);
            if (!X.empty()) return (X);
        }
        return (X);
    }
    
    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        colorArr.assign(size + 1, -1);
        adj.resize(n + 1);
    }
};

void solve(int tc) {
    ll n, m;
 
    cin >> n >> m;
 
    Graph gr(n);
 
 
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        gr.addEdge(a, b);
        gr.addEdge(b, a);
    }
 
    auto X = gr.findCircule();    
    if (X.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << X.size() << '\n';
    for (int i = 0; i < X.size(); i++)
        cout << X[i] << ' ';
    cout << '\n';
}
 
int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;
 
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
 
		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}

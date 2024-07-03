#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
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


const int MODE = 998244353;

using namespace std;

class Graph {
public:
    int size;
    vi vis, val;
    vii dp;
    vii adj;

    void dfs(ll n, ll p) {
        dp[n][val[n]] = 1;
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n);

            vi X = dp[n];
            for (int j = 0; j < dp[neg].size(); j++)
            if (dp[neg][j]) for (int h = X.size() - 1 - j; h >= 0; h--)
                X[h + j] = (X[h + j] + (dp[neg][j] * dp[n][h]) % MODE) % MODE;                
            dp[n]= X;
        }
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        vis.assign(2001, 0);
        val.assign(n + 1, 0);
        adj.resize(n + 1);
        dp.assign(n + 1, vi(2001));
    }
};


void solve(int tc) {
    ll n, k, x, q;

    cin >> n >> x >> q;

    Graph gr(n);        
    for (int i = 1; i <= n; i++)
        cin >> gr.val[i];
    
    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        gr.addEdge(u, v);
        gr.addEdge(v, u);
    }
    
    gr.dfs(x, 0);

    vi Z = gr.dp[x];
    for (int i = 1; i < Z.size(); i++)
        Z[i] = (Z[i] + Z[i - 1]) % MODE;    

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll res = ((Z[r] - Z[l - 1]) % MODE + MODE) % MODE;
        cout << res << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

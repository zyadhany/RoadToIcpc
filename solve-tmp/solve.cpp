#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll int
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

struct item
{
    vi dp;
    vi arr;
    ll node, res;

    item() {
        node = 0;
        dp = arr = vi();
        res = 0;
    }

    item(ll n, ll k) {
        node = 1;
        dp = vi(k + 1);
        if (n <= k) dp[n] = 1;
        dp[0] = 1;
        arr = vi(1, n);
        res = 0;
    }
};


class Graph {
public:
    int size;
    vi vis;
    vi szz;

    vii adj;
    vector<item> X;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(ll n, ll p, ll k) {
        ll at = n;
        
        vi Z (1, n);
        X[n] = item(vis[n], k);
        for (auto neg : adj[n]) {
            if (neg == p) continue;
            dfs(neg, n, k);
            szz[n] += szz[neg];
           
            if (X[szz[neg]].node > X[at].node) at = szz[neg];
            Z.push_back(szz[neg]);
        }

        ll cnt = 0;
        for (auto i : Z)
        {
            if (i == at) continue;
            X[at].node += X[i].node;

            for (int j = 0; j < X[i].arr.size(); j++)
            {
                ll a = X[i].arr[j];
                for (int h = k - a; h >= 0; h--)
                    X[at].dp[h + a] = (X[at].dp[h + a] + X[at].dp[h]) % MODE;
                cnt++;
                X[at].arr.push_back(a);
            }
            X[at].res = (X[at].res + X[i].res) % MODE;
        }

        szz[n] = at;
        X[at].res += X[at].dp[k];
        X[at].res %= MODE;
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        szz.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
            szz[i] = i;
        
        adj.resize(n + 1);
        X.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, k;

    cin >> n >> k;
    
    Graph gr(n);

    for (int i = 1; i <= n; i++)
        cin >> gr.vis[i];

    for (int i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        gr.addEdge(u, v);
        gr.addEdge(v, u);
    }
    
    gr.dfs(1, 0, k);
    for (int i = 1; i <= n; i++)
        if (gr.X[i].arr.size() == n) cout << gr.X[i].res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}
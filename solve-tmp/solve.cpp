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

const int MODE = 1e9 + 7;

using namespace std;


class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void BFS(int s)
    {
        queue<pl> que;
        que.push({s, 0});
        ll summ = 0;
        while (!que.empty())
        {
            pl m = que.front();
            que.pop();
            if (vis[m.first]) continue;
            vis[m.first] = 1;
            
            for (auto a : adj[m.first]) {
                if (!vis[a]) que.push({a, m.first});
            }
        }
    }


    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, m, mx, re, l, r, at, summ;

    cin >> n >> m;

    Graph gr(n);

    for (int i = 1; i <= m; i++)
    {  
        cin >>  l >> r; 
        gr.addEdge(l, r);
        gr.addEdge(r, l);
    }

    gr.BFS(1);
    for (int i = 1; i <= n; i++)
    {
        if (!gr.vis[i]) {
            cout << "NO\n";
            return;
        }
    }
    if (n != m) cout << "NO\n";
    else cout << "FHTAGN!\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    // freopen("mex.in", "r", stdi  n);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++) {
        solve(i);
    }
}   

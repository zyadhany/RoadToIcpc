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
    vi X;
    vector<ld> Y;
    vector<vector<ld>> Z, vis;
    vector<vector<pair<ll, ld>>> adj;

    void addEdge(int u, int v, ld w) {
        adj[u].push_back({v, w});
    }

    void floydWarshall(vector<vector<ld>> &dist)
    {   
        for (int k = 0; k < dist.size(); k++)
            for (int i = 0; i < dist.size(); i++)
                for (int j = 0; j < dist.size(); j++)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
    }

    vector<vector<ld>> floydBuild(){
        vector<vector<ld>> dist(size + 1, vector<ld>(size + 1, INT32_MAX));
        for (int i = 0; i <= size; i++) {
            dist[i][i] = 0;
            for (auto neg : adj[i])
                dist[i][neg.first] = min(dist[i][neg.first], neg.second);
        }
        floydWarshall(dist);
        return (dist);
    }

    ld req(ll n, bitset<12> bt){
        if (bt.count() == X.size()){
            return Z[n][0];
        }

        ld &ans = vis[n][bt.to_ullong()];
        if (ans != -1) return ans;
        ans = INT32_MAX;

        for (int i = 0; i < X.size(); i++)
        {
            if (bt[i]) continue;
            bt[i] = 1;
            ans = min(ans, req(X[i], bt) + Z[n][X[i]]);
            ans = min(ans, req(n, bt) + Y[i]);
            bt[i] = 0;
        }

        return ans;
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, vector<ld>(1 << 12, -1));
        adj.resize(n + 1);
    }
};


void solve(int tc) {
    ll n, m, u, v, k;
    ld w;

    cin >> n >> m;

    Graph gr(n);

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        gr.addEdge(u, v, w);
        gr.addEdge(v, u, w);
    }
    gr.Z = gr.floydBuild();

    cin >> k;
    gr.X.resize(k);
    gr.Y.resize(k);
    ld summ = 0, mn, re;

    for (int i = 0; i < k; i++)
    {
        cin >> gr.X[i] >> gr.Y[i];
        summ += gr.Y[i];
    }
    
    bitset<12> bt;

    mn = gr.req(0, bt);
    summ -= mn;
    if (summ <= 0) cout << "Don’t leave the house\n";
    else cout << fixed << setprecision(2) << "Daniel can save $" << summ << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

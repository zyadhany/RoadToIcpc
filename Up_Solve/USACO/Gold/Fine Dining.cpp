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
#define YES {cout << "Yes\n"; return;}
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

const int INF = 1e17;

vi dijkstra(vector<vp> &adj, ll size, ll v) {
    vi Z(size + 1, INF);

    priority_queue<pl, vp, greater<pl>> L;
    L.push({0, v});
    Z[v] = 0;

    while (!L.empty())
    {
        auto k = L.top();
        L.pop();
        if (k.first != Z[k.second]) continue;

        for (auto neg : adj[k.second]) {
            ll cost = neg.second + k.first;
            if (Z[neg.first] > cost) {
                Z[neg.first] = cost;
                L.push({cost, neg.first});
            }
        }
    }

    return (Z);
}

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vector<vp> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    vi dist = dijkstra(adj, n, n);

    priority_queue<pl, vp, greater<>> pq;
    vi dp(n + 1, INF);
    while (k--)
    {
        ll ind, v; cin >> ind >> v;
        if (dist[ind] != INF) {
            dp[ind] = dist[ind] - v;
            pq.push({dp[ind], ind});
        }
    }
    
    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();
        if (dp[u] != c) continue;
        for (auto [v, w] : adj[u]) {
            ll nw = c + w;
            if (nw < dp[v]) {
                dp[v] = nw;
                pq.push({nw, v});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (dist[i] != INF && dp[i] <= dist[i]) cout << 1 << '\n';
        else cout << "0\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
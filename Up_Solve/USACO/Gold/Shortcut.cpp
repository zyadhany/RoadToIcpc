// Time Complexity: O(nlogn + mlogm)

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

ll req(vii &adj, vi &Z, vi &X, ll n) {
    Z[n] += X[n];
    for (auto neg : adj[n]) Z[n] += req(adj, Z, X, neg);
    return Z[n];
}

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vector<vp> adj(n + 1);
    vi X(n + 1);

    for (int i = 0; i < n; i++)
        cin >> X[i + 1];
    

    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    priority_queue<pair<pl, ll>, vector<pair<pl, ll>>, greater<>> pq;
    vi dp(n + 1, INF); 
    dp[1] = 0;
    pq.push({{0,0}, 1});
    vii radj(n + 1);
    vi PAR(n + 1, -1);

    while (!pq.empty())
    {
        auto [c, p] = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (PAR[u] != -1) continue;
        
        PAR[u] = p;
        radj[PAR[u]].push_back(u);

        for (auto [v, w] : adj[u]) {
            ll nw = c + w;
            if (nw <= dp[v]) {
                dp[v] = nw;
                pq.push({{nw, u}, v});
            }
        }
    }

    vi Z(n + 1);
    req(radj, Z, X, 1);

    ll mx = 0;
    for (int i = 2; i <= n; i++)
        mx = max(mx, (dp[i]-k)*Z[i]);

    cout << mx << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
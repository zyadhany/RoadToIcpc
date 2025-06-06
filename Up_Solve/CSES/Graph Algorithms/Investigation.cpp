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

pl dijkstaminroad(vector<vp> &adj, ll n) {
    vp dp(n + 1, {INT64_MAX, 0});
    priority_queue<pl, vp, greater<pl>> pq;
    pq.push({0, 1});
    dp[1] = {0, 1};

    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();
        if (c > dp[u].first) continue;
        
        for (auto [v, w] : adj[u]) {
            ll nw = w + c;
            if (nw < dp[v].first) {
                dp[v] = {nw, dp[u].second};
                pq.push({nw, v});
            }
            else if (nw == dp[v].first)
            dp[v].second = (dp[u].second + dp[v].second) % MODE;
        }
    }
    
    return dp[n];
}

ll dijkstaminroadlen(vector<vp> &adj, ll n) {
    vp dp(n + 1, {INT64_MAX, 0});
    priority_queue<pair<pl, ll>, vector<pair<pl, ll>>, greater<pair<pl, ll>>> pq;
    pq.push({{0, 0}, 1});
    dp[1] = {0, 0};

    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();
        if (c > dp[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            pl nw = {c.first + w, c.second + 1};
            if (nw < dp[v]) {
                dp[v] = nw;
                pq.push({nw, v});
            }
        }
    }
    
    return dp[n].second;
}

ll dijkstamaxroadlen(vector<vp> &adj, ll n) {
    vp dp(n + 1, {INT64_MAX, 0});
    priority_queue<pair<pl, ll>, vector<pair<pl, ll>>, greater<pair<pl, ll>>> pq;
    pq.push({{0, 0}, 1});
    dp[1] = {0, 0};

    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();
        if (c > dp[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            pl nw = {c.first + w, c.second - 1};
            if (nw < dp[v]) {
                dp[v] = nw;
                pq.push({nw, v});
            }
        }
    }
    
    return dp[n].second;
}


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<vp> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    auto p = dijkstaminroad(adj, n);
    ll mn = dijkstaminroadlen(adj, n);
    ll mx = -dijkstamaxroadlen(adj, n);

    cout << p.first << ' ' << p.second << ' ' << mn << ' ' << mx;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("shortcut.in", "r", stdin);
    // freopen("shortcut.out", "w", stdout);
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
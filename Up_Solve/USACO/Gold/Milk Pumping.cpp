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

struct edge
{
    ll u, v, w, r;
    bool operator<(edge &e) {
        return r < e.r;
    }
};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<edge> E;

    for (int i = 0; i < m; i++)
    {
        edge e; cin >> e.u >> e.v >> e.w >> e.r;
        E.push_back(e);
    }
    sort(E.rbegin(), E.rend());

    ll sol = 0;
    vector<vp> adj(n + 1);
    for (auto e : E) {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
        
        vi dp(n + 1, INT32_MAX);
        dp[1] = 0;
        priority_queue<pl, vp, greater<>> pq;
        pq.push({0, 1});
        while (!pq.empty())
        {
            auto [c, u] = pq.top();
            pq.pop();
            if (c != dp[u]) continue;
            
            for (auto [v, w] :adj[u]) {
                ll nw = w + c;
                if (dp[v] > nw) {
                    dp[v] = nw;
                    pq.push({nw, v});
                }
            }
        }
        
        ll re = e.r * 1e6;
        re /= dp[n];
        sol = max(sol, re);
    }

    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
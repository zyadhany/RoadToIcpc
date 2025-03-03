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

struct voc
{
    ll val, ty, len, cost;
    voc (ll val, ll ty, ll len, ll cost) {
        this->val = val;
        this->ty = ty;
        this->len = len;
        this->cost = cost;
    }

    bool operator<(const voc& v) {
        if (val != v.val) return val < v.val;
        return ty < v.ty;
    }
};


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<vector<vp>> adj(2, vector<vp>(n + 1));
    vector<vp> radj(n + 1);

    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[0][u].push_back({v, w});
        adj[1][v].push_back({u, w});
    }
    
    priority_queue<pair<ll, pl>, vector<pair<ll, pl>>, greater<>> pq;
    vii dp(n + 1, vi(2, INT64_MAX));
    pq.push({0, {1, 0}});
    dp[1][0] = 0;

    while (!pq.empty())
    {
        ll cw = pq.top().first;
        ll u = pq.top().second.first;
        ll md = pq.top().second.second;
        pq.pop();

        if (cw > dp[u][md]) continue;
        if (!md && cw < dp[u][1]) {
            dp[u][1] = cw;
            pq.push({cw, {u, 1}});
        }

        for (auto [v, w] : adj[md][u]) {
            ll nw = cw + w;
            if (nw < dp[v][md]) {
                dp[v][md] = nw;
                pq.push({nw, {v, md}});
            }
        }
    }
    
    for (int i = 2; i <= n; i++)
    {
        ll dis = min(dp[i][0], dp[i][1]);
        if (dis == INT64_MAX) cout << "-1 ";
        else cout << dis << ' ';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

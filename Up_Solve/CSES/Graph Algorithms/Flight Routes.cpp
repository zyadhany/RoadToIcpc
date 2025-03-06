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

void solve(int tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    vector<vp> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    
    vii dp(n + 1);
    priority_queue<pl, vp, greater<pl>> pq;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();
        if (dp[u].size() >= k) continue;
        dp[u].push_back(c);

        for (auto [v, w] : adj[u]) {
            ll nw = w + c;
            pq.push({nw, v});
        }
    }

    for (auto a : dp[n]) cout << a << ' ';
    cout << '\n';
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
/*

for dp on tree solution can be in 2 cases:
    - from node to leafs (it's children)
    - from node to root (it's parent)
so we can use 2 dfs to calculate dp for each node
*/

// calculate longest path from every node to leafs

void dfs(vii &adj, vp &dp, ll n, ll p) {
    dp[n] = {0,0};
    for (auto neg : adj[n]) if (neg != p) {
        dfs(adj, dp, neg, n);
        ll len = dp[neg].first + 1;
        if (len > dp[n].first) {
            dp[n].second = dp[n].first;
            dp[n].first = len;
        } else if (len > dp[n].second) {
            dp[n].second = len;
        }
    }
}

void dfs2(vii &adj, vp &dp, vi &sol, ll n, ll p, ll tp) {
    ll &res = sol[n];
    res = max(tp+1, dp[n].first);
    for (auto neg : adj[n]) if (neg != p) {
        ll len = dp[neg].first;
        if (len + 1 == dp[n].first) {
            dfs2(adj, dp, sol, neg, n, max(tp+1, dp[n].second));
        } else {
            dfs2(adj, dp, sol, neg, n, max(tp+1, dp[n].first));
        }
    }
}

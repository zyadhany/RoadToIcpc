/*
You can combine two subtrees.
for i= 0->sz1+sz2-1, dp[i] = min(dp[i], dp1[j]+dp2[i-j]) for j=0->i

it look as n^3 if you move for every node but actually it is n^2!
*/

int sz1 = size(dp1), sz2 = size(dp2), sz = sz1 + sz2;
vi comp(sz, INF);
for (int k = 0; k < sz; k++)
    for (int i = k - min(k, sz2-1); i <= min(k, sz1 - 1); i++)
        comp[k] = min(comp[k], dp1[i] + dp2[k - i]);


// example for problem
const ll INF = 1e17;
const int MXN = 5005;
ll dp[MXN][2][MXN];
ll cnt[MXN]{};
 
void dfs(vii &adj, vp &X, ll n) {
    cnt[n] = 1;
    dp[n][0][0] = 0;
    dp[n][0][1] = X[n].first;
    dp[n][1][1] = X[n].second;
    
    for (auto neg : adj[n]) {
        dfs(adj, X, neg);
 
        // combine subtree
        int sz1 = cnt[n], sz2 = cnt[neg], sz = sz1+sz2;
        vi comp(sz+1, INF);
        for (int k = 0; k <= sz; k++)
            for (int i = k-min(k,sz2); i <= min(k, sz1); i++)
                comp[k] = min(comp[k], dp[n][0][i]+dp[neg][0][k-i]);
        for (int i = 0; i <= sz; i++) dp[n][0][i] = comp[i];
        
        comp.assign(sz+1, INF);
        for (int k = 0; k <= sz; k++)
            for (int i = k-min(k,sz2); i <= min(k, sz1); i++)
                comp[k] = min(comp[k], dp[n][1][i]+min(dp[neg][0][k-i], dp[neg][1][k-i]));
        for (int i = 0; i <= sz; i++) dp[n][1][i] = comp[i];
 
        cnt[n] += cnt[neg];
    }
}
 
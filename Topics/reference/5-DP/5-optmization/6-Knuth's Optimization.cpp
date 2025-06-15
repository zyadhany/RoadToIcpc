/*
optmize range dp in form: dp[i][j] = cost[i][j] + min(dp[i][j], dp[i][k] + dp[k+1][j]) for k=i:>j-1

The idea is we define new array opt[i][j] that stores the minimum index k such that dp[i][k] + dp[k+1][j] is minimum.

that only hold if cost[i][j] is monotonic in j, i.e. cost[i][j] <= cost[i][j+1] for all j >= i.

opt[i][j-1] <= opt[i][j] <= opt[i+1][j]

to get best value for dp[i][j], we need to only iterate from opt[i][j-1] to opt[i+1][j].
*/

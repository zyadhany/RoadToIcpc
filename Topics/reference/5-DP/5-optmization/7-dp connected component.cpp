/*
DP connected component

Way to solve problems which to count the number of permutations of a set of elements that have some characteristic.
*/

// calculate factorial using dp connected component
// dp[i][j] = number of ways to add up to i elements with j components
vii dp(n+10, vi(n+10));
dp[0][0] = 1;
for (int i = 1; i <= n; i++)
{
    for (int j = 0; j < i; j++)
    {
        // add new component
        dp[i][j+1] += dp[i-1][j] * (j + 1);
        // add i to existing component
        dp[i][j] += dp[i-1][j] * (2 * j);
        // merge two components
        dp[i][j] += dp[i-1][j+1] * j;
    }    
}

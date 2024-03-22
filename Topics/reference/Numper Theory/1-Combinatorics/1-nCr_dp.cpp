/**
 * dp solution to get 2d array of nCr.
 * C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
 * C(n, 0) = C(n, n) = 1.
 * Time O(n * k).
 * Space O(n * k).
*/
vii binomialCoeff(int n, int k)
{
    vii C(n + 1, vi(k + 1));

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= min(i, k); j++)
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];

    return (C);
}

/**
 * another approach of dp with less space.
 * it works in way of pascal triangle.
 * Time O(n * k).
 * Space O(k).
*/
ll binomialCoeff(int n, int k)
{
    vi C(k + 1);

    C[0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];

    return (C[k]);
}

// dp recursive solution
// Time O(n * k) Space O(n * k).
ll binomialCoeff(int n, int k, vii &dp)
{
    if (dp[n][k] != -1)  return dp[n][k];
    if (k == 0 || n == k) return (dp[n][k] = 1);

    dp[n][k] = binomialCoeff(n - 1, k - 1, dp) +
        binomialCoeff(n - 1, k, dp);

    return dp[n][k];
}

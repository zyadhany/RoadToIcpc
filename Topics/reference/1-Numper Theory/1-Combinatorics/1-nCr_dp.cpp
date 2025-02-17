/*
    Binomial Coefficients:
   
   - Number of ways to choose equal-length subsets from 2 sets of size x, y is C(x + y, x).

    Properties of Binomial Coefficients:

    1. Symmetry Rule:
       C(n, k) = C(n, n-k)

    2. Factoring In:
       C(n, k) = (n / k) * C(n-1, k-1)

    3. Sum over k:
       Σ(C(n, k) for k = 0 to n) = 2^n

    4. Sum over n:
       Σ(C(m, k) for m = 0 to n) = C(n+1, k+1)

    5. Sum over n and k:
       Σ(C(n + k, k) for k = 0 to m) = C(n + m + 1, m)

    6. Sum of the squares:
       C(n, 0)^2 + C(n, 1)^2 + ... + C(n, n)^2 = C(2n, n)

    7. Weighted Sum:
       1*C(n, 1) + 2*C(n, 2) + ... + n*C(n, n) = n * 2^(n-1)

    8. Connection with Fibonacci Numbers:
       C(n, 0) + C(n-1, 1) + ... + C(n-k, k) + ... + C(0, n) = F(n+1)
    
    9. Power Series Expansion:
        Σ(X^i * C(n, i) for i = 0 to n) = (1+X)^n
*/


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


// get nCr without taking mod.
ll nCrNoOverFlow(ll n, ll k) {
    if (n < k || k < 0) return 0;
    k = max(k, n - k);
    ll ans = 1;
    for (ll i = n; i > k; i--)
        ans = (ans * i) / (n - i + 1);
    return ans;
}

/**
 * get 2d array of lcp
 * lcp of sitring in index i and j
 */

int lcp[n][n];
for (int i = n - 1; i >= 0; i--)
{
    ll at = 0;
    for (int j = 0; j <= i; j++)
    {
        if (s[n - 1 - j] == s[i - j]) at++;
        else at = 0;
        lcp[n - j - 1][i - j] = lcp[i - j][n - j - 1] = at;
    }
}


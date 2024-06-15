vii buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vii table(n, vi(m + 1));
    for (int i = 0; i < n; i++)
        table[i][0] = X[i];
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = table[i][j - 1] +
               table[i + (1 << (j - 1))][j - 1];

    return (table);
}
 
// Returns the sum of range L and R, 0-index.
long long query(vii &table, int L, int R)
{
    int m = table[0].size() - 1;
    long long answer = 0;
    for (int j = m; j >= 0; j--) {
        if (L + (1 << j) - 1 <= R) {
            answer = answer + table[L][j];
            L += 1 << j;
        }
    }
    return answer;
}

// optmization to get in O(1)
long long query(vii &table, int L, int R) 
{ 
    int j = (int)log2(R - L + 1); 
    return min (table[L][j], table[R - (1 << j) + 1][j]);
}
struct sparse {
    int n, m;
    vii table;
    vii buildSparseTable(vi &X)
    {
        n = X.size(); m = ceil(log2(n));
        table.assign(n, vi(m + 1));
        for (int i = 0; i < n; i++)
            table[i][0] = X[i];

        for (int j = 1; j <= m; j++)
            for (int i = 0; i <= n - (1 << j); i++)
                table[i][j] = max(table[i][j - 1],
                   table[i + (1 << (j - 1))][j - 1]);
    
        return (table);
    }
    ll firstgreater(ll l, ll k) {
        for (int j = m; j >= 0; j--) {
            if (l + (1 << j) - 1 < n && table[l][j] <= k) {
                l += 1 << j;
            }
        }
        if (l >= n || table[l][0] <= k) return -1;
        return l;
    }
    long long query(int L, int R) 
    { 
        int j = (int)log2(R - L + 1); 
        return max(table[L][j], table[R - (1 << j) + 1][j]);
    }
    sparse(vi &X){
        buildSparseTable(X);
    }
};

struct item
{
    int val, freq, ind;

    item(){
        val = INT32_MAX;
        freq = 0;
        ind = -1;
    }
};


item Spmarge(item a, item b) {
    item res = a;
    if (a.val > b.val) res = b;
    else if (a.val == b.val) res.freq += b.freq;
    return res;
}

vector<vector<item>> buildSparseTable(vi &X)
{
    ll n, m;
    n = X.size(); m = ceil(log2(n));
    vector<vector<item>> table(n, vector<item>(m + 1));
    for (int i = 0; i < n; i++){
        table[i][0].val = X[i];
        table[i][0].freq = 1;
        table[i][0].ind = i;
    }
 
    for (int j = 1; j <= m; j++)
        for (int i = 0; i <= n - (1 << j); i++)
            table[i][j] = Spmarge(table[i][j - 1], 
                        table[i + (1 << (j - 1))][j - 1]);

    return (table);
}
 
item query(vector<vector<item>> &table, int L, int R)
{
    int m = table[0].size() - 1;
    item answer = item();
    for (int j = m; j >= 0; j--) {
        if (L + (1 << j) - 1 <= R) {
            answer = Spmarge(answer, table[L][j]);
            L += 1 << j;
        }
    }
    return answer;
}

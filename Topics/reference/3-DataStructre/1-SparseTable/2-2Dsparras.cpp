ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}

vector<vii> buildSparseTable(vii &X)
{
    ll n, m, k;
    n = X.size(); m = X[0].size(); k = ceil(log2(max(n, m)));

    viii table(n, vii(m, vi(k + 1)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            table[i][j][0] = X[i][j];
 
    for (int h = 1; h <= k; h++)
        for (int i = 0; i <= n - (1 << h); i++) {
            for (int j = 0; j <= m - (1 << h) ; j++)
            {
                ll a, b, c, d;
                ll sht = (1 << (h - 1));
                a = table[i][j][h - 1];
                b = table[i][j + sht][h - 1];
                c = table[i + sht][j][h - 1];
                d = table[i + sht][j + sht][h - 1];
                table[i][j][h] = gcd(gcd(a, b), gcd(c, d));
            }
        }

    return (table);
}
 
// optmization to get in O(1)
long long query(vector<vii> &table, int x1, int y1, ll x2, ll y2) 
{ 
    int j = (int)log2(x2 - x1 + 1);
    ll a, b, c, d;
    ll sht = (1 << j) - 1;
    a = table[x1][y1][j];
    b = table[x1][y2 - sht][j];
    c = table[x2 - sht][y1][j];
    d = table[x2 - sht][y2 - sht][j];
    return gcd(gcd(a, b), gcd(c, d));
}

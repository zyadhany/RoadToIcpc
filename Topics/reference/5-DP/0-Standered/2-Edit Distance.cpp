/**
 * Given 2 string s, t: make them equal.
 * you can only switch element, delete, insert.
 */
void solve(ll tc) {
    ll n, m;
    string s, t;

    cin >> s >> t;

    n = s.size(), m = t.size();
    vii Z(n + 1, vi(m + 1, INT32_MAX));

    for (int i = 0; i <= m; i++)
        Z[0][i] = i;        

    for (int i = 1; i <= n; i++)
    {
        Z[i][0] = i;
        for (int j = 1; j <= m; j++)
            Z[i][j] = min(Z[i - 1][j - 1] + (s[i - 1] != t[j - 1]),
                        min(Z[i - 1][j], Z[i][j - 1]) + 1);
    }
    
    cout << Z[n][m] << '\n';
}

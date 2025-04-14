struct Matrix {
    ll n, m;
    vii a;
    Matrix(ll n) : n(n), m(n), a(n, vi(n, 0)) {}
    Matrix(ll n, ll m) : n(n), m(m), a(n, vi(m, 0)) {}
    Matrix operator*(const Matrix &b) const {
        Matrix c(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    if (a[i][k] != INF && b.a[k][j] != INF)
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
};

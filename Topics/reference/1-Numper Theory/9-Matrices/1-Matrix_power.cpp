/*
to get fib(n), combute {{0, 1}, {1, 1}}^n
*/

struct Matrix {
    ll a[2][2];
    Matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
};

Matrix matrixpower(Matrix a, ll n) {
    Matrix res;
    for (int i = 0; i < 2; i++) res.a[i][i] = 1;
    
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

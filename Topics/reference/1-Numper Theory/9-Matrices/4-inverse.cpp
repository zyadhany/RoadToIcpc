// Not sure if it work, From GPT

struct Matrix {
    ld a[2][2];
    Matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    c.a[i][j] += a[i][k] * b.a[k][j];
        return c;
    }
};

Matrix inverse(Matrix A) {
    Matrix B;
    ld a = A.a[0][0], b = A.a[0][1], c = A.a[1][0], d = A.a[1][1];
    ld det = a * d - b * c;

    B.a[0][0] =  d / det;
    B.a[0][1] = -b / det;
    B.a[1][0] = -c / det;
    B.a[1][1] =  a / det;

    return B;
}

//// another with mode

ll modinv(ll x) {
    ll res = 1, y = MODE - 2;
    while (y) {
        if (y & 1) res = (1LL * res * x) % MODE;
        x = (1LL * x * x) % MODE;
        y >>= 1;
    }
    return res;
}

Matrix inverse(Matrix A) {
    Matrix B;
    ll a = A.a[0][0], b = A.a[0][1], c = A.a[1][0], d = A.a[1][1];
    ll det = (1LL * a * d - 1LL * b * c + MODE) % MODE;
    ll inv_det = modinv(det);

    B.a[0][0] = 1LL * d * inv_det % MODE;
    B.a[0][1] = (MODE - 1LL * b % MODE) * inv_det % MODE;
    B.a[1][0] = (MODE - 1LL * c % MODE) * inv_det % MODE;
    B.a[1][1] = 1LL * a * inv_det % MODE;

    return B;
}
/*
For and adjacency matrix of a graph, A^n[i][j] = number of paths of length n from vertex i to vertex j.

we can make it weighted and compute the min cost of the path between two vertices of length n.
A^n[i][j] = min cost of the path of length n from vertex i to vertex j.
let multiply(A, B), AB[i][j] = min A[i][k] + B[k][j], for k = 1 to n.
*/

/*
Kirchhoff's theorem:
The number of spanning trees of a connected graph is equal to the determinant of the specialized Laplacian matrix of the graph.

The Laplacian matrix: A[i][i] = degree of vertex i, A[i][j] = -1 if there is an edge between i and j, 0 otherwise.
*/

struct Matrix {
    ll n;
    vii a;
    Matrix(ll n) : n(n), a(n, vi(n)) {}
    Matrix operator*(const Matrix &b) const {
        Matrix c(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
};

Matrix matrixpower(Matrix a, ll n) {
    Matrix res(a.n);
    for (int i = 0; i < res.n; i++) res.a[i][i] = 1;
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

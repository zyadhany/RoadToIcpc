/*
Matrices: 2D array of numbers arranged in rows and columns.

Matrix A = [a11, a12, a13, ...]
           [a21, a22, a23, ...]
           [a31, a32, a33, ...]

Transpose of a matrix: A^T is the matrix obtained by swapping the rows and columns of A.
A^T = [a11, a21, a31, ...]
       [a12, a22, a32, ...]
       [a13, a23, a33, ...]

Matrix square: A is a square matrix if the number of rows is equal to the number of columns.

identity matrix: A square matrix with 1s on the diagonal and 0s elsewhere.
I = [1, 0, 0, ...]
    [0, 1, 0, ...]
    [0, 0, 1, ...]

Definition of a matrix:
A is an n x m matrix with n rows and m columns.

A + B = [a11 + b11, a12 + b12, a13 + b13, ...]
          [a21 + b21, a22 + b22, a23 + b23, ...]
          [a31 + b31, a32 + b32, a33 + b33, ...]

A - B = [a11 - b11, a12 - b12, a13 - b13, ...]
          [a21 - b21, a22 - b22, a23 - b23, ...]
          [a31 - b31, a32 - b32, a33 - b33, ...]

k * A = [k * a11, k * a12, k * a13, ...]
          [k * a21, k * a22, k * a23, ...]
          [k * a31, k * a32, k * a33, ...]

A*B: A of size a x n and B of size n x b, the product AB is a x b matrix. (column of A = row of B).
AB[i][j] = sum(A[i][k] * B[k][j]) for k = 1 to n.
A*(BC) = (AB)C
A^T * B^T = (AB)^T
A*I = A
*/

/*
Determinant of a matrix: A is a square matrix, the determinant of A is a scalar value that can be calculated from the elements of A.

if det(A) != 0, A is invertible. (A^-1 exists)
if det(A) = 0, A is singular. (A^-1 does not exist)

det(A) = sum(A[1][j] * C[1][j]) for j = 1 to n, where C[1][j] is the cofactor of A[1][j].
C[i][j] = (-1)^(i+j) * det(M[i][j]), where M[i][j] is the matrix obtained by removing the i-th row and j-th column from A.

to get inverse of a matrix (A^-1).
A^-1[i][j] = C[i][j] / det(A) (C is the cofactor matrix of A)
*/
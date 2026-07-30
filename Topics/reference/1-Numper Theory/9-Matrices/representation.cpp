/*
 * ============================================================================
 *               MATRIX REPRESENTATION OF FUNCTIONS IN CP
 * ============================================================================
 *
 * Core Idea:
 * Function composition f_1(f_2(...f_k(x)...)) can be computed using range 
 * matrix multiplication M_1 * M_2 * ... * M_k on a segment tree or via 
 * binary lifting / matrix exponentiation.
 *
 * ----------------------------------------------------------------------------
 * 1. MOBIUS / RATIONAL TRANSFORMATIONS
 * ----------------------------------------------------------------------------
 * General Form: f(x) = (a*x + b) / (c*x + d)
 * Represent x as fraction p/q  ==>  Vector [p, q]^T
 * 
 * Matrix M:
 *   [ a  b ] * [ p ] = [ a*p + b*q ]  ==>  New fraction: (a*p + b*q) / (c*p + d*q)
 *   [ c  d ]   [ q ]   [ c*p + d*q ]
 *
 * Examples in CP:
 * 
 * a) f(x) = C / (A*x + B)   <-- (Your problem!)
 *    Here: a = 0, b = C, c = A, d = B
 *    Matrix:
 *      [ 0  C ]
 *      [ A  B ]
 *    Base input x = 0 is represented as p = 0, q = 1  ->  Vector [0, 1]^T
 *
 * b) f(x) = a + (b / x) = (a*x + b) / x
 *    Matrix:
 *      [ a  b ]
 *      [ 1  0 ]
 *
 * c) Continued Fractions: f(x) = a + (1 / x)
 *    Matrix:
 *      [ a  1 ]
 *      [ 1  0 ]
 *
 * ----------------------------------------------------------------------------
 * 2. AFFINE / LINEAR FUNCTIONS
 * ----------------------------------------------------------------------------
 * General Form: f(x) = a*x + b
 * Vector: [x, 1]^T
 *
 * Matrix M:
 *   [ a  b ] * [ x ] = [ a*x + b ]
 *   [ 0  1 ]   [ 1 ]   [    1    ]
 *
 * Composing f1(f2(x)) where f1(x)=a1*x+b1 and f2(x)=a2*x+b2:
 *   [ a1  b1 ] * [ a2  b2 ] = [ a1*a2   a1*b2 + b1 ]
 *   [  0   1 ]   [  0   1 ]   [   0         1      ]
 *
 * ----------------------------------------------------------------------------
 * 3. 2D / 3D AFFINE TRANSFORMATIONS (Geometry / Graph DP)
 * ----------------------------------------------------------------------------
 * General Form:
 *   x' = a*x + b*y + c
 *   y' = d*x + e*y + f
 * Vector: [x, y, 1]^T
 *
 * Matrix M:
 *   [ a  b  c ]   [ x ]   [ a*x + b*y + c ]
 *   [ d  e  f ] * [ y ] = [ d*x + e*y + f ]
 *   [ 0  0  1 ]   [ 1 ]   [       1       ]
 *
 * Common Transformations:
 * - Shift (dx, dy):      a=1, b=0, c=dx, d=0, e=1, f=dy
 * - Scale (sx, sy):      a=sx, b=0, c=0, d=0, e=sy, f=0
 * - Swap x and y:        a=0, b=1, c=0, d=1, e=0, f=0
 *
 * ----------------------------------------------------------------------------
 * 4. LINEAR RECURRENCES (DP / Fibonacci)
 * ----------------------------------------------------------------------------
 * General Form: F(n) = c1*F(n-1) + c2*F(n-2) + ... + ck*F(n-k)
 *
 * Fibonacci Example: F(n) = F(n-1) + F(n-2)
 * Vector: [F(n-1), F(n-2)]^T
 * Matrix:
 *   [ 1  1 ] * [ F(n-1) ] = [ F(n-1) + F(n-2) ] = [  F(n)  ]
 *   [ 1  0 ]   [ F(n-2) ]   [     F(n-1)     ]   [ F(n-1) ]
 *
 * DP with constant term: F(n) = a*F(n-1) + b*F(n-2) + c
 * Vector: [F(n-1), F(n-2), 1]^T
 * Matrix:
 *   [ a  b  c ]
 *   [ 1  0  0 ]
 *   [ 0  0  1 ]
 *
 * ----------------------------------------------------------------------------
 * 5. TROPICAL SEMIRING / MAX-PLUS ALGEBRA (Shortest Path / Range DP)
 * ----------------------------------------------------------------------------
 * Used when DP state looks like: DP[i] = min_j (DP[j] + weight(j, i))
 * Replace normal arithmetic operations:
 *   Standard Matrix Mul : C[i][j] = sum_k (A[i][k] * B[k][j])
 *   Tropical Matrix Mul : C[i][j] = min_k (A[i][k] + B[k][j])   [or max_k]
 *
 * Identity Matrix for Min-Plus:
 *   Diagonal = 0, Off-diagonal = INF
 * ============================================================================
 */
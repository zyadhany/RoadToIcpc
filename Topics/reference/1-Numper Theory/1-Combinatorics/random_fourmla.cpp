/*
----------------------------------------------------------------------------
COMBINATORICS & COUNTING
----------------------------------------------------------------------------
Stars & Bars (x1 + ... + xk = n):
  Non-negative (xi >= 0): C(n + k - 1, k - 1)
  Positive     (xi >= 1): C(n - 1, k - 1)

Catalan Numbers: C_n = (1 / (n + 1)) * C(2n, n)
  Applications: Valid parens, BSTs with n nodes, Dyck paths, (n+2)-gon triangulations

Derangements: D_n = (n - 1) * (D_{n-1} + D_{n-2}) = n * D_{n-1} + (-1)^n
  Base: D_0 = 1, D_1 = 0

Stirling 2nd Kind S(n, k): Partition n labeled items into k unlabeled non-empty sets
  S(n, k) = k * S(n - 1, k) + S(n - 1, k - 1)

Kirkman Dissection: Partition n-gon into k sub-polygons using k-1 diagonals
  Ans = (1 / k) * C(n - 3, k - 1) * C(n + k - 2, k - 1)

Burnside's Lemma: Unique configs under symmetry group G
  N = (1 / |G|) * sum(|X^g|) over all g in G

----------------------------------------------------------------------------
NUMBER THEORY
----------------------------------------------------------------------------
Euler's Totient phi(n): Count x in [1, n] with gcd(x, n) = 1
  phi(n) = n * prod(1 - 1/p) for prime factors p|n
  Property: sum_{d|n} phi(d) = n

Euler's Power Reduction (for large exponent b >= phi(m)):
  a^b = a^( (b % phi(m)) + phi(m) ) (mod m)

Divisors (n = prod(p_i^e_i)):
  Count: d(n) = prod(e_i + 1)
  Sum:   sigma(n) = prod( (p_i^(e_i + 1) - 1) / (p_i - 1) )

Lucas' Theorem (C(n, r) % p for prime p):
  C(n, r) = prod( C(n_i, r_i) ) (mod p), where n_i, r_i are base-p digits

----------------------------------------------------------------------------
GRAPH THEORY & TREES
----------------------------------------------------------------------------
Labeled Trees:
  Spanning trees on n labeled vertices = n^(n - 2) (Cayley's Formula)
  Spanning trees on Complete Bipartite K_{m,n} = m^(n-1) * n^(m-1)

Kirchhoff's Matrix Tree Theorem:
  Total spanning trees = Any cofactor of Laplacian matrix L = Degree - Adjacency

Euler's Planar Formula:
  V - E + F = 1 + C  (C = components, F = faces)
  Connected graph (C = 1): V - E + F = 2

----------------------------------------------------------------------------
GEOMETRY
----------------------------------------------------------------------------
Shoelace Area (n-gon):
  Area = 0.5 * |sum_{i=1}^n (x_i * y_{i+1} - x_{i+1} * y_i)|, with (x_{n+1}, y_{n+1}) = (x_1, y_1)
  
  Pick's Theorem (Lattice Polygon Area):
  Area = I + (B / 2) - 1  (I = inside grid points, B = boundary grid points)

Lattice points on segment (x1, y1) to (x2, y2):
  Boundary points = gcd(|x2 - x1|, |y2 - y1|) + 1

----------------------------------------------------------------------------
ALGEBRA & SERIES
----------------------------------------------------------------------------
Sum i   = n * (n + 1) / 2
Sum i^2 = n * (n + 1) * (2n + 1) / 6
Sum i^3 = (n * (n + 1) / 2)^2

Lagrange Interpolation (k points (x_i, y_i) -> degree k-1 poly P(x)):
  P(x) = sum_{i=1}^k y_i * prod_{j != i} (x - x_j) / (x_i - x_j)

----------------------------------------------------------------------------
GAME THEORY
----------------------------------------------------------------------------
Sprague-Grundy:
  G(S) = mex({G(S') : S -> S'})
  Combined games: G(S1 + S2) = G(S1) ^ G(S2). First player wins iff XOR sum != 0
*/
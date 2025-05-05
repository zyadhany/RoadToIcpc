k^n: Getting all probabilities of n objects with k values.

/* Permutations */
P(n, k) = n! / (n - k)!: Calculates the number of permutations of choosing 'k' objects out of 'n' without repetition, where order matters.

/* Binomial Coefficients */
C(n, k) = n! / (k! * (n − k)!): Calculates the number of combinations of choosing 'k' objects out of 'n' without repetition, where order doesn’t matter.
C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
C(n, k) = C(n, n - k).

// It can be used to get the coefficient of the n-th power (a + b)
(a + b)^n = C(n, 0) * a^n * b^0 + C(n, 1) * a^{n-1} * b^1 + ... + C(n, n) * a^0 * b^n
(a + b)^n = Sum from i = 0 to n: C(n, i) * a^{n-i} * b^i

// Put k balls in n boxes, where each box can have multiple balls.
f(n, k) = C(n + k - 1, k)

// Put k balls in n boxes such that no two adjacent boxes contain a ball.
f(n, k) = C(n - k + 1, k)

// number of way we build array of leanght l with summ x
nCr(x-l + l-1, l-1) = nCr(x-1, l-1)

/* Multinomial Coefficient */
// Equals the number of ways we can divide n elements into subsets of sizes k1, k2, ..., km, where k1 + k2 + ... + km = n.
// num of way to shuffel array
= n! / (k1! * k2! * k3! * ... * km!)

/* Catalan Numbers */
// The Catalan number C_n equals the number of valid parenthesis expressions that consist of n left parentheses and n right parentheses.
Catalan number: C(n) = (2n)! / ((n + 1)! * n!)
C_0 = C_1 = 1
C_n = Sum from i = 0 to n-1: C(i) * C(n - i - 1)
C_n = C(2n, n) / (n + 1)
C(n) = (C(n - 1) * (4 * n - 2)) / (n + 1)

/**
 * - There are C_n binary trees with n nodes.
 * - There are C_(n-1) rooted trees with n nodes.
 */


/* Burnside's Lemma */
// Used to count distinct objects under group symmetries (e.g., rotations, reflections).
// Formula: Distinct Objects = (1 / |G|) * Sum of |Fix(g)| for all g in G
// Where:
//   - G is the group of symmetries.
//   - Fix(g) is the number of configurations that remain unchanged under symmetry g.

/* Example: Counting distinct necklaces with n beads and m colors */
// Rotate k steps: Fix(g_k) = m^(gcd(n, k)).
// Distinct necklaces = (1 / n) * Sum from k = 0 to n-1: m^(gcd(n, k)).


/* Cayley's Formula */
T(K_n) = n^(n-2) :- This formula gives the number of labeled spanning trees in a complete graph K_n with n vertices.
- A spanning tree is a tree that connects all n vertices without cycles.
- Labeled means the vertices are distinct and labeled, meaning the arrangement of vertices matters.

/* Inclusion-Exclusion Principle */

// Used to calculate the size of the union of multiple sets by accounting for overlaps between sets.

|A1 ∪ A2 ∪ ... ∪ Ak| = ∑|Ai| - ∑|Ai ∩ Aj| + ∑|Ai ∩ Aj ∩ Ak| - ... + (-1)^(k+1) |A1 ∩ A2 ∩ ... ∩ Ak|.

// Explanation:
// - Add sizes of individual sets.
// - Subtract pairwise intersections to remove double-counting.
// - Add back triple intersections to fix over-subtraction.
// - Continue alternation until all intersections are accounted for.

Example with three sets A, B, C:
|A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|.


/**
 * restricted inclusion-exclusion principle.
 * Standard Equation:
 * Summation formula for Inclusion-Exclusion:
 * 
 * Total = Summation{i = 0 to n} [ (-1)^i * nCr(n, i) * f(i) ]
 * 
 * Explanation:
 * - (-1)^i alternates between addition and subtraction.
 * - nCr(n, i) chooses 'i' sets from 'n'.
 * - f(i) represents the count or size of the intersection of chosen sets.
 */

// Count combinations where a_1 + a_2 + ... + a_n = k, with 0 <= a_i < m.
ll count_combinations(ll n, ll m, ll k) {
    /**
     * Total combinations if there are no restrictions:
     * total = nCr(n + k - 1, k)
     *
     * Define f(i): Count of combinations where at least i elements are >= m.
     * Using Inclusion-Exclusion:
     * result = f(0) - nCr(n, 1) * f(1) + nCr(n, 2) * f(2) - ... + nCr(n, n) * f(n)
     */

    ll result = 0; // Final result
    for (int i = 0; i <= n; i++) {
        // If k - i * m becomes negative, no valid combinations exist.
        if (k - i * m < 0) break;

        // Calculate current term using Inclusion-Exclusion
        ll term = (nCr(n, i) * nCr(n + k - i * m - 1, n - 1)) % MODE;

        // Alternate addition and subtraction based on Inclusion-Exclusion principle
        if (i % 2 == 1) result = (result + MODE - term) % MODE;
        else result = (result + term) % MODE;
    }

    return result;
}

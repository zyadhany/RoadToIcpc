/*
    Given a set of 2^n elements, we need to calculate f[mask] = sum of A[i] for all i subset of mask.

    we define G(mask, i) = summ of A[j] for all j subset of mask and mask^j < 2^i
    - ie. only first i bits of mask can differ and rest are fixed.
    
    we get recurance:
    - if i-th bit is 0, then G(mask, i) = G(mask, i-1)
    - if i-th bit is 1, then G(mask, i) = G(mask, i-1) + G(mask^2^i, i-1)
*/

// brute force solution
vector<int> sos(1 << n);
for (int x = 0; x < (1 << n); x++) {
	// iterate over all other sets and checks whether they're a subset of x
	for (int i = 0; i < (1 << n); i++) {
		if ((i & x) == i) { sos[x] += a[i]; }
	}
}

// dp solution
vector<int> sos(1 << n);
vector<vector<int>> dp(1 << n, vector<int>(n + 1));
for (int x = 0; x < (1 << n); x++) {
	dp[x][0] = a[x];
	for (int i = 0; i < n; i++) {
		dp[x][i + 1] = dp[x][i];
		if (x & (1 << i)) { dp[x][i + 1] += dp[x ^ (1 << i)][i]; }
	}
	sos[x] = dp[x][n];
}

// memory optimization solution
for (int i = 0; i < n; i++) {
	for (int x = 0; x < (1 << n); x++) {
		if (x & (1 << i)) { sos[x] += sos[x ^ (1 << i)]; }
	}
}

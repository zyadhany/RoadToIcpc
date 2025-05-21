A simple and more scalable approach would be to sweep through each dimensions one at a time and compute the prefix sum step by step:

<LanguageSection>
<CPPSection>

```cpp
// Initialize
for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) { S[i][j] = A[i][j]; }
}

// Sweep along x-axis
for (int i = 1; i < n; i++) {
	for (int j = 0; j < m; j++) { S[i][j] += S[i - 1][j]; }
}

// Sweep along y-axis
for (int i = 0; i < n; i++) {
	for (int j = 1; j < m; j++) { S[i][j] += S[i][j - 1]; }
}
```

</CPPSection>
<PySection>

```py
# Initialize
for i in range(n):
	for j in range(m):
		S[i][j] = A[i][j]

# Sweep along the x-axis
for i in range(1, n):
	for j in range(m):
		S[i][j] += S[i - 1][j]

# Sweep along the y-axis
for i in range(n):
	for j in range(1, m):
		S[i][j] += S[i][j - 1]
```

</PySection>
</LanguageSection>

This approach generalizes to higher dimensions.

Let's say we want to calculate the prefix sum array for 4D grid. We can calculate this by sweeping along each axis of a 4D grid, one at a time:

- After sweeping along the x-axis, $S[i][j][k][l]$ contains the sum of $A[a][b][c][d]$ where:
	- $a \leq i$
	- $b = j, c = k,$ and $d = l$.
- After sweeping along the y-axis, $S[i][j][k][l]$ contains the sum of $A[a][b][c][d]$ where:
	- $a \leq i, b \leq j$
	- $c = k,$ and $d = l$.
- After sweeping along the z-axis, $S[i][j][k][l]$ contains the sum of $A[a][b][c][d]$ where:
	- $a \leq i, b \leq j, c \leq k$
	- $d = l$.
- Finally, after sweeping along the w-axis, $S[i][j][k][l]$ contains the sum of $A[a][b][c][d]$ where:
	- $a \leq i, b \leq j, c \leq k,$ and $d \leq l$.

If we extend this idea to $n$ dimensions, here's what happens: after sweeping along the $i$-th axis, $S[x]$ contains the sum of the values in $A$ where the first $i$ coordinates are less than or equal to the $x$, and the remaining coordinates match $x$. Sound familiar? That's exactly what $F(x)$ represents in the SOS problem!

If we think of each bit in a bitmask as its own axis, then a bitmask $x$ with $n$ bits can be viewed as an $n$-dimensional coordinate, where each component is either $0$ or $1$. A submask of $x$ corresponds to an $n$-dimensional coordinate where each component is less than or equal to $x$.

Therefore, when we interpret the bitmask as an $n$-dimensional coordinate, $F(x)$ aligns with the definition of an $n$-dimensional prefix sum!

By applying the sweeping algorithm along each axis, we get the memory-optimized SOS DP solution mentioned earlier, demonstrating that SOS DP is indeed an **n-dimensional prefix sum**.

<LanguageSection>
<CPPSection>

```cpp
F = A;

for (int i = 0; i < n; i++) {  // Sweep along the i-th axis
	for (int x = 0; x < (1 << n); x++) {
		if (x & (1 << i))  // If the i-th bit is set, accumulate
			F[x] += F[x ^ (1 << i)];
	}
}
```

</CPPSection>

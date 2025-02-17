/*
    If $x$ is in $T$ but not in $S$, $T$ isn't a valid subset.
    Given that each element can be in three possible states, our overall complexity is actually $\mathcal{O}(3^N)$.
    To implement this, we can do some bitwise tricks:
*/
for (int mask = 0; mask < (1 << n); mask++) {
	for (int submask = mask; submask != 0; submask = (submask - 1) & mask) {
		int subset = mask ^ submask;
		// do whatever you need to do here
	}
}
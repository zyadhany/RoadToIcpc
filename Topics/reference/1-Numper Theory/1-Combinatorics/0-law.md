k^n :- getting all probabilities of n opjects with k values.


P(n, k) = n! / (n - k)! :- calculates the number of permutations of choosing 'k' objects out of 'n' without repetition, where order matters.

C(n, k) = n! / (k! * (n − k)!):- calculates the number of combinations of choosing 'k' objects out of 'n' without repetition, where order doesn't matter.
C(n, k) = C(n - 1, k - 1) + C(n - 1, k).
C(n, k) = C(n, n - k).

Catalan number - C(n) = (2n)! / ((n + 1)! * n!) 
C_0 = C_1 = 1
C_n = sum{i=0}^{n-1}(C_i * C_{n-i-1})
C_n = nCr(2 * n, n) / (n + 1)
C(n) = (C(n - 1) * (4 * n - 2)) / (n + 1).

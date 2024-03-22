# Referance
Great topic for jumper theory
https://www.geeksforgeeks.org/number-theory-competitive-programming/


# Topics

## Basics

#### steps
- Gcd/LCM
- Get Factorial of number
- Prime factors of number

--------
### Binomial Coefficient (nCr) 

#### steps

- C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
- Dp solution
- Sieve prime factorization & fast power
- Modular Inversion

#### Problems
- https://leetcode.com/problems/pascals-triangle/description/

--------
### Catalan Number

#### steps
```
- Catalan number - C(n) = (2n)! / ((n + 1)! * n!)
- C_0 = C_1 = 1
- C_n = sum{i=0}^{n-1}(C_i * C_{n-i-1})
- C_n = nCr(2 * n, n) / (n + 1)

```

- Dp solution
- Using nCr

#### Problems
- https://leetcode.com/problems/unique-binary-search-trees/submissions/1210461052/

--------


	

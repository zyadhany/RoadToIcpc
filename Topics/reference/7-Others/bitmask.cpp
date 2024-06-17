/**
 * 1 << k: 1 bit at postion k.
 * x & (1 << k): check value of x[k] bit.
 * x | (1 << k): x[k] = 1.
 * x & ~(1 << k): x[k] = 0.
 * x ^ (1 << k): invert x[k].
 * x & (x−1): set last one in x to zero.
 * x & (x−1): make all one in x to zero expect the last.
 * x | (x−1): invert all bit agter last one bit.
 * if (x & (x−1) == 0): x in power of 2.
 */

/**
 * __builtin_clz(x): the number of zeros at the beginning of the number.
 * __builtin_ctz(x): the number of zeros at the end of the number.
 * __builtin_popcount(x): the number of ones in the number.
 * __builtin_parity(x): the parity (even or odd) of the number of ones.
 */

int x = 5328; // 00000000000000000001010011010000
cout << __builtin_clz(x) << "\n"; // 19
cout << __builtin_ctz(x) << "\n"; // 4
cout << __builtin_popcount(x) << "\n"; // 5
cout << __builtin_parity(x) << "\n"; // 1


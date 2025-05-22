/**
 * 1 << k: 1 bit at postion k.
 * x & (1 << k): check value of x[k] bit.
 * x | (1 << k): x[k] = 1.
 * x & ~(1 << k): x[k] = 0.
 * x ^ (1 << k): invert x[k].
 * x & (x−1): set last one in x to zero.
 * x & (-x): make all one in x to zero expect the last.
 * x | (x−1): invert all bit after last one bit.
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


/* Interval */

// itrate over all subset from 1 to n-1.
for (int b = 0; b < (1<<n); b++) {
    // process subset b
}

// itrate over all subset of lenght k.
for (int b = 0; b < (1<<n); b++) {
    if (__builtin_popcount(b) == k) {
        // process subset b
    }
}

// itrate over all subset of x
int b = 0;
do {
    // process subset b
} while (b=(b-x)&x);



// sand[i]: count of element y such that (i&y)=y (ie. i|y=i).
vector<int> sor(all(frq));
for (int i = 0; i < m; i++) {
    for (int x = 0; x < (1 << m); x++) {
        if (x & (1 << i)) { sor[x] += sor[x ^ (1 << i)]; }
    }
}

vector<int> sand(all(frq));
for (int i = m-1; i >= 0; i--) {
    for (int x = (1 << m)-1; x > 0; x--) {
        if ((x & (1 << i))==0) { sand[x] += sand[x ^ (1 << i)]; }
    }
}
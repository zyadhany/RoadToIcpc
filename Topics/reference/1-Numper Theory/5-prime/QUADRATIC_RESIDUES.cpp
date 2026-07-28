/*
 ===============================================================================
  QUADRATIC RESIDUES & MODULAR SQUARE ROOTS (MOD p, prime p > 2)
 ===============================================================================
  DEFINITION:
   - x (1 <= x < p) is a Quadratic Residue (QR) if a^2 = x (mod p) has a solution.
   - Otherwise, x is a Quadratic Non-Residue (QNR). 0 is neither.
   - Exactly (p-1)/2 QRs and (p-1)/2 QNRs in [1, p-1].

  MULTIPLICATIVE PROPERTIES:
   - QR * QR = QR
   - QR * QNR = QNR
   - QNR * QNR = QR

  EULER'S CRITERION:
   - a is QR  <=> a^((p-1)/2) = 1  (mod p)
   - a is QNR <=> a^((p-1)/2) = -1 (mod p) [or p-1]
   - (-1) is QR <=> p = 1 (mod 4). (-1) is QNR <=> p = 3 (mod 4).

  FINDING i^2 = -1 (mod p):
   - If p % 4 == 3: No solution (-1).
   - If p == 2: i = 1.
   - If p % 4 == 1: Pick random QNR 'a',
        - if a^((p-1)/2) = -1 (mod p),
            then i = a^((p-1)/4) (mod p).
 ===============================================================================
*/

// Fast modular exponentiation: O(log exp)
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

// Check if 'a' is a Quadratic Residue mod p (Legendre Symbol)
// Returns 1 if QR, -1 (p-1) if QNR, 0 if a % p == 0
int legendre(long long a, long long p) {
    long long res = power(a, (p - 1) / 2, p);
    return res == p - 1 ? -1 : res;
}

// Find i such that i^2 = -1 (mod p)
long long find_i(long long p) {
    if (p == 2) return 1;
    if (p % 4 == 3) return -1; // No solution
    
    static mt19937_64 rng(1337);
    while (true) {
        long long a = rng() % (p - 1) + 1;
        if (legendre(a, p) == -1) { // Found QNR
            return power(a, (p - 1) / 4, p);
        }
    }
}

/*
  GENERAL MODULAR SQUARE ROOT: x^2 = n (mod p)
  
  1. TONELLI-SHANKS ALGORITHM (O(log^2 p) average):
     - Solves x^2 = n (mod p) for any prime p and QR n.
*/
long long tonelli_shanks(long long n, long long p) { administration:
    n %= p;
    if (n == 0) return 0;
    if (p == 2) return n;
    if (legendre(n, p) != 1) return -1; // No square root exists

    // Special fast case: p = 3 (mod 4)
    if (p % 4 == 3) return power(n, (p + 1) / 4, p);

    // Factor p - 1 = Q * 2^S (Q odd)
    long long Q = p - 1;
    int S = 0;
    while (Q % 2 == 0) {
        Q /= 2;
        S++;
    }

    // Find a QNR 'z'
    static mt19937_64 rng(1337);
    long long z = rng() % (p - 1) + 1;
    while (legendre(z, p) != -1) {
        z = rng() % (p - 1) + 1;
    }

    long long M = S;
    long long c = power(z, Q, p);
    long long t = power(n, Q, p);
    long long R = power(n, (Q + 1) / 2, p);

    while (t != 1) {
        if (t == 0) return 0;
        long long temp = t;
        int i = 0;
        for (i = 1; i < M; i++) {
            temp = (__int128)temp * temp % p;
            if (temp == 1) break;
        }

        long long b = power(c, 1LL << (M - i - 1), p);
        M = i;
        c = (__int128)b * b % p;
        t = (__int128)t * c % p;
        R = (__int128)R * b % p;
    }

    return R; // Other root is p - R
}
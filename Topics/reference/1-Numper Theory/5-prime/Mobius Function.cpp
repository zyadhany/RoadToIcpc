/*
Mobius Function
The Möbius function is a multiplicative function defined on the positive integers. It is denoted by μ(n) and is defined as follows:
Y(1) = 1
Y(n) = 0 if n has a squared prime factor
Y(n) = (-1)^k if n is a product of k distinct prime factors, where k is the number of distinct prime factors of n.
*/
const int MAXSZ = 1e7 + 1;
int mobius[MAXSZ] = {0};
void INIT() {
    mobius[1] = -1;
    for (int i = 1; i < MAXSZ; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < MAXSZ; j += i) { mobius[j] += mobius[i]; }
        }
    }
}

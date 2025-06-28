/*
Chinese Remainder Theorem (CRT):
Given a system of linear congruences:
x ≡ a1 (mod m1)
x ≡ a2 (mod m2)
...
x ≡ an (mod mn)
where m1, m2, ..., mn are pairwise coprime, there exists a unique solution x modulo M = m1 * m2 * ... * mn.
*/

/*
Case 2 equations:
x ≡ a1 (mod m1)
x ≡ a2 (mod m2)

To solve this, we can use the Extended Euclidean Algorithm to find the modular inverse of m1 modulo m2, and then combine the two equations.

a = a1*n2*m2 + a2*n1*m1 (mod m1*m2)
Where:
- n1 = modular inverse of m2 modulo m1
- n2 = modular inverse of m1 modulo m2
- m1, m2 are coprime
*/


/*
for general case with n equations: we can us lagrange interpolation to find the solution.
as: m1, m2, ..., mn are pairwise coprime.   
*/
struct Congruence {
    long long a, m;
};

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}


// if given equations are not coprime.
#include<bits/stdc++.h>
using namespace std;
const int N = 20;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
int testCases;
int t;
long long a[N], n[N], ans, lcm;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) cin >> a[i] >> n[i], normalize(a[i], n[i]);
    ans = a[1];
    lcm = n[1];
    for(int i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lcm, n[i]);
        int x1 = pom.x;
        int d = pom.d;
        if((a[i] - ans) % d != 0) return cerr << "No solutions" << endl, 0;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i] / d);
        lcm = LCM(lcm, n[i]); // you can save time by replacing above lcm * n[i] /d by lcm = lcm * n[i] / d
    }
    cout << ans << " " << lcm << endl;

    return 0;
}

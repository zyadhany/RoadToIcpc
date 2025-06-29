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
for general case with n equations: 
we can run solution for each pair of equations iteratively.
*/

/*
we can us lagrange interpolation to find the solution.
as: m1, m2, ..., mn are pairwise coprime.   
*/
pl crt(const vector<ll> &remainders, const vector<ll> &moduli) {
	ll MOD = accumulate(moduli.begin(), moduli.end(), 1LL, multiplies<ll>());
	ll x = 0;
	for (int i = 0; i < (int)moduli.size(); i++) {
		ll a = remainders[i] * inv(MOD / moduli[i], moduli[i]) % moduli[i];
		x = (x + a * (MOD / moduli[i])) % MOD;
	}
	return {x, MOD};
}

// if given equations are not coprime.
// get a where a = a1 (mod m1) and a = a2 (mod m2)
pl CRT(ll a1, ll m1, ll a2, ll m2) {
	if (a2 < a1) {
		swap(a1, a2);
		swap(m1, m2);
	}
	ll x, y;
	ll d = a2 - a1;
	ll m = lcm(m1, m2);
	ll g = gcdExtended(m1, m2, &x, &y);
	if (d % g != 0) return {-1, -1}; // no solution
	x = (x * (d / g)) % (m2 / g);
	if (x < 0) x += (m2 / g);
	ll ans = (a1 + x * m1) % m;
	if (ans < 0) ans += m;
	return {ans, m};
}
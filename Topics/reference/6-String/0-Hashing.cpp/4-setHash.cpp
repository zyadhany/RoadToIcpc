/*
Given Array and queries each to tell if set(L,R) == set(L',R') or not

Set-Hash we can use 2 coff
K(Large): 31415926 
H(Small): 37

F(Set[l,r]) = ((Set[l] + K)^H + (Set[l+1] + K)^H + ... + (Set[r] + K)^H) % MOD
*/

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MODE = 1e9+9;
const int K = uniform_int_distribution<ll>(0, MODE - 1)(rng);

ll hashval(ll v) {
    return (v + K) % MODE;
}
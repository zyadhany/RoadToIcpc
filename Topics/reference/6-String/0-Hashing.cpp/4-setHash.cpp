/*
Given Array and queries each to tell if set(L,R) == set(L',R') or not

Set-Hash we can use 2 coff
K(Large): 31415926 
H(Small): 37

F(Set[l,r]) = ((Set[l] + K)^H + (Set[l+1] + K)^H + ... + (Set[r] + K)^H) % MOD
*/

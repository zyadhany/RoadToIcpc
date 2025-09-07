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


//  Given array find 2 index where a_i and a_j are coprime
pl sol(vp &X) {
    ll m = 0;
    for (auto [a, b] : X) m = max(a, m);

    vi dp(m+1);

    ll n = 0;
    for (auto [v, ind] : X) {
        n++;
        
        vi P;
        ll a = v;
        while (a > 1)
        {
            ll p = prime[a];
            P.push_back(p);
            while (a%p==0) a/=p;
        }
        
        ll cnt = 0;
        for (int i = 0; i < (1ll<<P.size()); i++)
        {
            ll sing = 1;
            ll v = 1;
            for (int j = 0; j < P.size(); j++)
            {
                if (i & (1<<j)) v *= P[j], sing *= -1;
            }
            cnt += sing * dp[v];
            dp[v]++;
        }

        if (cnt) {
            for (auto [v2, ind2] : X) {
                if (gcd(v2, v) == 1) {
                    return {ind, ind2};
                }
            }
        }
    }
    
    return {-1, -1};
}

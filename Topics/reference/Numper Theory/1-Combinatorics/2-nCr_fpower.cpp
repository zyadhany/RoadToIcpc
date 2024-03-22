/**
 * C(n, k) = n! / (k! * (n − k)!)
 * C(n, k) = (n-r+1)*(n-r+2)*...*(n)/(r!).
 * we calculate the first part then divide it.
 * using sive prime factorization and fpower.
 * Time O(n*log(n)).
 * Space O(n).
*/

ll fpowr(ll b, ll exp)
{
    ll ret = 1;

    while (exp > 0) {
        if ((exp & 1) > 0)
            ret = (ret * b) % MODE;
        b = (b * b) % MODE;
        exp >>= 1;
    }

    return (ret % MODE);
}

ll nCr(ll n, ll r)
{
    if (r > n) return 0;
    if (n - r > r) r = n - r;

    // sieve factoriazation
    vi SPF(n + 1, 0);
    for (int i = 1; i <= n; i++) SPF[i] = i;
    for (int i = 4; i <= n; i += 2) SPF[i] = 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (SPF[i] != i) continue;
        for (int j = i * i; j <= n; j += i)
            if (SPF[j] == j) SPF[j] = i;
    }

    map<int, int> prime_pow;
    for (int i = r + 1; i <= n; i++) {
        int t = i;
        while (t > 1) prime_pow[SPF[t]]++, t /= SPF[t];
    }
    for (int i = 1; i <= n - r; i++) {
        int t = i;
        while (t > 1) prime_pow[SPF[t]]--, t /= SPF[t];
    }

    ll ans = 1;
    for (auto it : prime_pow)
        ans = (ans * fpowr(it.first, prime_pow[it.first])) % MODE;
    return (ans);
}

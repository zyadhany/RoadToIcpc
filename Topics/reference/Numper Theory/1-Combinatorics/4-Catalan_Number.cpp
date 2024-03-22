// number of possibilities of various combinations.

/**
 * dp solution return array catalon numbers.
 * C(n) = summtion(C(i) * C(n - i - 1)).
 * Time O(n * n).
 * Space O(n).
*/
vi catalanDP(int n)
{
    vi C(n + 1, 0);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++)
            C[i] += C[j] * C[i - j - 1];
    return (C);
}

/**
 * C(n) = (C(n - 1) * (4 * n - 2)) / (n + 1).
 * Time O(n).
 * Space O(n).
*/
vi catalanDP(int n)
{
    vi C(n + 1, 0);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; i++)
        C[i] += (C[i - 1] * (4 * i - 2)) / (i + 1);
    return (C);
}

// C(n) = nCr(2 * n, n) / (n + 1)
ll catalan(int n)
{
    return nCr(2 * n, n) / (n + 1);
}

// C(n) = (2n)! / ((n + 1)! * n!) 
ll catalan(int n)
{
    ll res = fac[2 * n];
    res *= modeenv((fac[n + 1] * fac[n]) % MODE);
    return (res) % MODE;
}

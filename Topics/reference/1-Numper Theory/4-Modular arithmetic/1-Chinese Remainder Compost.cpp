
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

pair<long, long> CRT(vector<long long> rem, vector<long long> num)
{   
    for (int i = 0; i < num.size(); i++)
        rem[i] = (rem[i] % num[i] + num[i]) % num[i];

    long long ans = rem[0];
    long long lc = num[0];

    for (int i = 1; i < num.size(); i++)
    {
        auto pom = ex_GCD(lc, num[i]);
        int x1 = pom.x;
        int d = pom.d;

        if ((rem[i] - ans) % d != 0)
            return {-1, -1};
    
        ans = ans + x1 * (rem[i] - ans) / d % (num[i] / d) * lc;
        lc =  lc * num[i] / d;
        ans = (ans % lc + lc) % lc;
    }

    return {ans, lc};    
}

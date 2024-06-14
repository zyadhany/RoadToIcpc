// get how many factorial of n devided by k.
// !n / k.
ll CalcFactorial(ll n, ll k) {
    ll summ = 0;

    while (k <= n)
    {
        summ += n / k;
        k *= 5;
    }

    return (summ);
}

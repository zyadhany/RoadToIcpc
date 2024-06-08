vi primeFactors(int n)
{
    vi X;

    while (n % 2 == 0)
    {
        X.push_back(2);
        n = n / 2;
    }
    
    for (int i = 3; i * i<= n; i = i + 2)
    {
        while (n % i == 0)
        {
            X.push_back(i);
            n = n / i;
        }
    }
    
    if (n != 1) X.push_back(n);

    return (X);
}
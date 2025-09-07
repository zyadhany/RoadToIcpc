// fib[0] = fib[1] = 1
// fib[i] = fib[i-1] + fib[i-2]
// You can find the nth fibo using matrix power in log(n)

// gcd(fib[n], fib[m]) = fib[gcd(n, m)]
// gcd between any two concutive fib numbers is 1: and it's worth case for gcd function

// check if number x is fibo number
bool isPerfectSquare(int x)
{
    int s = sqrt(x);
    return (s * s == x);
}
// Returns true if n is a Fibonacci Number, else false
bool isFibonacci(int n)
{
    // n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or
    // both is a perfect square
    return isPerfectSquare(5 * n * n + 4)
        || isPerfectSquare(5 * n * n - 4);
}
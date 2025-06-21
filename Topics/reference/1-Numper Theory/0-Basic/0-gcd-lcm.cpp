
/**
 * we keep devide/substract
 * bigger number to smaller number
 *  
 * we can get product of all common prime factors of a&b.
*/

ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}

/**
 * a*b = lcm() / gcd()
 * lcm() = union prime factors.
 * */  
ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
}

// faster gcd
int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

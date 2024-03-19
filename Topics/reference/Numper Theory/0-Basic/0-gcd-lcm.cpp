
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

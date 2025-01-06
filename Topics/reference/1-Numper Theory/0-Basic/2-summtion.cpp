// summ of num from 1 to n.
ll summtion(ll n) {
    return n * (n + 1) / 2;
}
/*
    ll summ = (sqrt((8 * k) + 1) + 1) / 2 - 1; 
    get value of n from summtion lowered down.
*/

const int MODE = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

// summ from st to en % MODE.
long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MODE) * ((start + end) % MODE) % MODE) * TWO_MOD_INV %
	        MODE);
}

 
// summ of num from 1 to n that divide by k.
ll summk(ll n, ll k) {
    ll lastTerm = n - (n % k);
    ll numTerms = lastTerm / k;
    ll sum = (numTerms * (k + lastTerm)) / 2;
    return (sum);
}

// summ i^2 to n^2 .. 1^2 + 2^2 + 3^2 .. + n^2
    // n(n + 1)(2n + 1) / 6
ll SummSquir(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

/**
 * arithmetic: summ where the difference between any
 *    two consecutive numbers is constant 3, 7, 11, 15
 *  n(a + b) / 2 
 *  a:first numb, b:second, n:number of element.
*/ 
ll SummArithmetic (ll n, ll a, ll b){
    return n * (a + b) / 2;
}

/*
 * Geometric Sequence:
 * A sequence where each term is multiplied by a constant ratio (r).
 * Formula: a_n = a * r^(n-1), where:
 *   - a: first term
 *   - r: common ratio
 *   - n: term index (1-based)
 * 
 * Sum of first k terms (if |r| < 1): S_k = a * (1 - r^k) / (1 - r)
 * Sum of infinite terms (|r| < 1): S_inf = a / (1 - r)
 * 
 * Example usage:
 */
// Returns the nth term of a geometric sequence
long long geometric_nth_term(long long a, long long r, long long n) {
    return a * pow(r, n - 1); // a_n = a * r^(n-1)
}
// Returns the sum of the first k terms of a geometric sequence
long long geometric_sum(long long a, long long r, long long k) {
    if (r == 1) return a * k; // Special case when r = 1
    return a * (1 - pow(r, k)) / (1 - r); // S_k = a * (1 - r^k) / (1 - r)
}
// Returns the sum of an infinite geometric sequence (|r| < 1)
double geometric_sum_infinite(double a, double r) {
    return a / (1 - r); // S_inf = a / (1 - r)
}

// summtion(x^i): 1 + x + x^2 + x^3 +...+ x^k
// (x^(r+1) - 1) / (x-1)
ll summPower(ll n, ll k) {
    ll l, r;
    l = (fpowr(n, k + 1) - 1 + MODE) % MODE;
    r = modeenv(n - 1);
    return (l * r) % MODE;
}

// summtion(i*x^i): x + 2*x^2 + 3*x^3 +...+ k*x^k
// ( x - (n+1) * x^(n+1) + n*x^(n+2)) / (1-x)^2
ll summKthPower(ll n, ll k) {
    ll l, r;
    ll a, b;
    
    a = ((k + 1) * fpowr(n, k + 1)) % MODE;
    b = (k * fpowr(n, k + 2)) % MODE;
     
    l = ((n - a + b) % MODE + MODE) % MODE;
    
    r = modeenv((1 - n + MODE) % MODE);
    r = (r * r) % MODE;
    return (l * r) % MODE;
}

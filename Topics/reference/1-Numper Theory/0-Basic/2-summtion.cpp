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

/**
 * geometric progression: a + ak + a k^2 + a k^2 + ... + b
 * (bk - a) / (k - 1);
*/
ll GeometricProgression (ll a, ll b, ll k) {
    return (b * k - a) / (k - 1);
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

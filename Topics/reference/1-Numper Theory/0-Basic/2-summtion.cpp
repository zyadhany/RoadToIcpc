// summ of num from 1 to n.
ll summtion(ll n) {
    return n * (n + 1) / 2;
}
 
// summ of num from 1 to n that divide by k.
ll summk(ll n, ll k) {
    ll lastTerm = n - (n % k);
    ll numTerms = lastTerm / k;
    ll sum = (numTerms * (k + lastTerm)) / 2;
    return (sum);
}
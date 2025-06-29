
// Fermat test: You can fast check, if return false then it's not prime else it may be prime
mtd::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
bool canBePrime(long long n) {
    ll a = std::uniform_int_distribution<ll>(1, n - 1)(rng);
    if (gcd(a, n) != 1) return 0;
    if (fpow(a, n - 1, n) != 1) return 0;
    return 1;
}

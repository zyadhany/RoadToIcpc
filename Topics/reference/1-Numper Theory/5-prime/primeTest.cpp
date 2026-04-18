
// Fermat test: You can fast check, if return false then it's not prime else it may be prime
mtd::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
bool canBePrime(long long n) {
    ll a = std::uniform_int_distribution<ll>(1, n - 1)(rng);
    if (gcd(a, n) != 1) return 0;
    if (fpow(a, n - 1, n) != 1) return 0;
    return 1;
}

bool isprime(ll n){
    if(n<2) return 0;
    for(ll p : {2,3,5,7,11,13,17,19,23,29,31,37}){
        if(n%p==0) return n==p;
    }
    ll d = n-1;
    ll s = 0;
    while((d & 1) == 0){ d >>= 1; s++; }
    auto powmod = [](ll a, ll b, ll m){
        ll r=1;
        a %= m;
        while(b){
            if(b&1) r = (__int128)r * a % m;
            a = (__int128)a * a % m;
            b >>=1;
        }
        return r;
    };
    for(ll a : {2,3,5,7,11,13,17,19,23,29,31,37}){
        if(a>=n) break;
        ll x = powmod(a,d,n);
        if(x==1 || x==n-1) continue;
        bool composite = true;
        for(ll r=1;r<s;r++){
            x = (__int128)x * x % n;
            if(x==n-1){ composite=false; break; }
        }
        if(composite) return false;
    }
    return true;
}
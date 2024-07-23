(a+b)%c= ((a%c)+(b%c))%c
(a*b)%c= ((a%c)*(b%c))%c
(a-b)%c= ((a%c)-(b%c)+c)%c
(a/b)%c= ((a%c)*((b^-1)%c))%c

ll add (ll a,ll b)
{
    return ((a%MOD)+(b%MOD))%MOD;
}

ll mul (ll a,ll b)
{
  return ((a%MOD)*(b%MOD))%MOD;
}

ll inv(ll a)
{
    return modfpow(a,MOD-2,MOD);
}

-----------------------------------------
last digit 788*789 equal last digit 8*9
-----------------------------------------
ll fpow(ll x,ll y)
{
    ll result=1;
    while(y>0)
    {
        if (y%2==1)result=result*x;

        x=x*x;
        y=y/2;
    }
    return result;
}

ll modfpow(ll x,ll y,ll z)
{
    ll result=1;
    while(y>0)
    {
        if (y%2==1)result=((result%z)*(x%z))%z;

        x=((x%z)*(x%z))%z;
        y=y/2;
    }
    return result;
}
-----------------------------------------
// summ of numpers divisible by m from 1 to n

ll n,m;cin>>n>>m;
    ll first_term = m;
    ll last_term = (n / m) * m;
    ll num_terms = (last_term - first_term) / m + 1;
    ll sum = (num_terms * (first_term + last_term)) / 2;
    cout<<sum<<"\n";

----------------------------------------------------------
factor for i*i<n only &&  factors= i + n/i 
i*i better than sqrt(n) ---> log(n) time
----------------------------------------------------------
// prime factorization

ll n;cin>>n;
    vector<ll>primefactors;
    for (ll i = 2; i*i <=n ; ++i) {
        while(n%i==0)
        {
            n/=i;
            primefactors.push_back(i);
        }
    }
    if (n!=1)primefactors.push_back(n);

------------------------------------------------------------
// sum of first n even numpers

int evenSum(int n)
{
    return (n * (n + 1));
}

// sum of first odd numpers 
n^2

// sum of numpers from 1 to n

ll sum = (a/2)*(a+1);

// sum even and odd

int sum_even = (n/2) * (n/2 + 1);
int sum_odd = ((n+1)/2) * ((n+1)/2);

-------------------------------------------------------------
#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)      ((a / gcd(a, b)) * b)
gcd(a,b)=gcd(b,a%b)
-------------------------------------------------------------
Extended Euclidean Algorithm iterative

//ax+by=gcd(a,b)

int extendedEuclid(int a, int b, int& x, int& y){
        if(b == 0){
            x= 1; y = 0;
            return a;
        }
        int x1, y1;
        int d = extendedEuclid(b, a%b, x1, y1);
        x = y1;
        y = x1 - y1*(a/b);
        return d;
}

int a,b;
cin>>a>>b;
int x,y;
cout<<extendedEuclid(a,b,x,y)<<" ";//gcd
cout<<x<<" "<<y<<endl;

----------------------------------------------------------------
// Modular Multiplicative Inverse B:
// (A*B)=1(mod M)
// 0<=B<=M-1

// B exist if A and M coprime ( gcd(A,M)=1 )

void modInverse(int A, int M)
{
    int x, y;
    int g = extendedEuclid(A, M, x, y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {
        int res = (x % M + M) % M;  // m is added to handle negative x
        cout << "Modular multiplicative inverse is " << res;
    }
}


b here = x from ax+by=gcd(a,b)

-----------------------------------------------------------------
// ncr

int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// ncr less time

ll ncr(ll n, ll r) {
    if (r > n) {
        return 0;
    }
    ll res = 1;
    for (ll i = 0; i < r; i++) {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

ll nCr(ll n, ll r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    ld res = 0;
    for (int i = 0; i < r; i++) {
        res += log(n-i) - log(i+1);
    }
    return (ll)round(exp(res));
}


// ncr mod p

// A modular inverse based solution to
// compute nCr % p
/* Iterative Function to calculate (x^y)%p
in O(log y) */

unsigned long long power(unsigned long long x, int y, int p)
{
	unsigned long long res = 1;

	x = x % p; // Update x if it is more than or
	// equal to p

	while (y > 0) {

		// If y is odd, multiply x with result
		if (y & 1)
			res = (res * x) % p;

		// y must be even now
		y = y >> 1; // y = y/2
		x = (x * x) % p;
	}
	return res;
}

// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n, int p)
{
	return power(n, p - 2, p);
}
unsigned long long mul(unsigned long long x,
					unsigned long long y, int p)
{
	return x * 1ull * y % p;
}
unsigned long long divide(unsigned long long x,
						unsigned long long y, int p)
{
	return mul(x, modInverse(y, p), p);
}

// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
								int r, int p)
{
	// If n<r, then nCr should return 0
	if (n < r)
		return 0;
	// Base case
	if (r == 0)
		return 1;
	// if n-r is less calculate nCn-r
	if (n - r < r)
		return nCrModPFermat(n, n - r, p);

	// Fill factorial array so that we
	// can find all factorial of r, n
	// and n-r
	unsigned long long res = 1;
	// keep multiplying numerator terms and dividing denominator terms in res
	for (int i = r; i >= 1; i--)
		res = divide(mul(res, n - i + 1, p), i, p);
	return res;
}

// Driver program
int main()
{
	// p must be a prime greater than n.
	int n = 10, r = 2, p = 13;
	cout << "Value of nCr % p is "
		<< nCrModPFermat(n, r, p);
	return 0;
}




-------------------------------------------------------------------------
// sum of numpers from a to b divisible by x

long long sum ( long long n ) { return n * (n + 1) / 2; }
         
         long long a,b,x;cin>>a>>b>>x;
         long long  mx = max(a, b);
         long long  mn = min(a, b);
 
        cout << (sum(mx / x) * x) - (sum((mn - 1) / x) * x) << endl;
-------------------------------------------------------------------------

// linear seive

bool com[10000000];
vi prime;
void seive(ll n)
{
    com[0]=com[1]=1;
    for (int i = 2; i <n ; ++i) {
        if (!com[i])prime.push_back(i);
        for (int j = 0; j <prime.size()&&i*prime[j]<n ; ++j) {
            com[i*prime[j]]=true;
            if (i%prime[j]==0)break;
        }
    }
}

----------------------------------------------------------------------------
ceil(n/d)=(n+d-1)/d
----------------------
اول رقم بعد 10 بيقبل القسمة علي 3

ceil(10/3)*3=12

-------------------------
vector<bool> segmentSeive(ll L,ll R)
{
    ll lim=sqrt(R);
    vector<bool>mark(lim+1,false);
    vector<ll>primes;
    for (ll i = 2; i <=lim ; ++i) {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (ll j = i*i; j <=lim ; j+=i) {
                mark[j]=true;
            }
        }
    }
    vector<bool>iscomposite(R-L+1,false);
    for(ll i:primes)
    {
        for (ll j = max(i*i,(L+i-1)/i*i); j <=R ; j+=i) {
            iscomposite[j-L]=true;
        }
    }
    if (L==1)iscomposite[0]=true;
    return iscomposite;
}


void solve() {

    ll l,r;cin>>l>>r;
    if (l>r)swap(l,r);
    vector<bool>iscomposite= segmentSeive(l,r);
    for (ll i = l; i <=r ; ++i) {
        if (!iscomposite[i-l])cout<<i<<"\n";
    }
    
}
------------------------------------------------------------
Miller Rabin Primality Testing
Fermat Primality testing //حاسسهم مش مهمين علشان مش اكيد 
not 100%
------------------------------------------------
// Euler Totient 
// كام رقم اصغر منه ال gcd
// معاه بيساوي 1
// coprimes

phi(a*b)=phi(a)*phi(b)

time=sqrt(n)


ll phi(ll n)
{
    ld result=n;
    for (int i = 2; i*i <=n ; ++i) {
        if (n%i==0)
        {
            while(n%i==0) n/=i;
            result*=(1.0-(1.0/float(i)));
        }
    }
    if (n>1)result*=(1.0-(1.0/float(n)));
    ll jj=result;
    return jj;
}



    مثلث الارقام
    ll sum= (n * (n + 1) * (n + 2)) / 6;



// num of pairs have lcm = G and gcd = L

ll countPairs(ll G, ll L)
{
    // To store count
    ll count = 0;

    // To store product a*b = G*L
    ll p = G*L;

    // p/a will be b if a divides p
    for (ll a=1; a<=L; a++)
        if (!(p%a) && gcd(a, p/a)==G)
            count++;

    return count;
}

// faster

ll totalPrimeFactors(ll n)
{
    ll count = 0;
    if (!(n%2))
    {
        count++;
        while (!(n%2))
            n /= 2;
    }
    for (ll i = 3; i*i <= n; i = i+2)
    {
        if (!(n%i))
        {
            count++;
            while (!(n%i))
                n /= i;
        }
    }
    if (n>2)
        count++;
    return count;
}
ll countPairs(ll G, ll L)
{
    if (L % G != 0)
        return 0;
    ll div = L/G;
    return (1<<totalPrimeFactors(div));
}



// NPR mod

long long mod_pow(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    return result;
}

long long mod_inverse(long long x) {
    return mod_pow(x, MOD - 2);
}

long long nPrModM(long long n, long long m) {
    if (n < m) {
        return 0;
    }

    long long result = 1;

    for (ll i = 1; i <= n; i++) {
        result = (result * i) % MOD;
    }

    for (ll i = 1; i <= (n - m); i++) {
        result = (result * mod_inverse(i)) % MOD;
    }
    return result;
}

ll mid = st + (end - st) / 2;


ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}




// npr for big numbers

ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(ll n, ll p) {
    return power(n, p - 2, p);
}

const ll MAXN = 200010; // Maximum N across all test cases
vi factorials(MAXN + 1, 1);
vi inv_factorials(MAXN + 1, 1);
void fact() {
    for (int i = 2; i <= MAXN; ++i) {
        factorials[i] = (factorials[i - 1] * i) % MOD;
    }
    inv_factorials[MAXN] = modInverse(factorials[MAXN], MOD);
    for (int i = MAXN - 1; i >= 1; --i) {
        inv_factorials[i] = (inv_factorials[i + 1] * (i + 1)) % MOD;
    }
}
ll nPr(int n, int r) {
    if (r > n || r < 0) return 0;
    ll numerator = factorials[n];
    ll denominator = inv_factorials[n - r];
    return (numerator * denominator) % MOD;
}


void solve() {

    nPr(n, r))

}

int main() {

    fact();

}












// spf (smallest prime factor)

const int MAX_SIEVE = 20000000; // sqrt(n) for seive

vi generatePrimes(ll max) {
    vector<bool> is_prime(max + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= max; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= max; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vi primes;
    for (ll i = 2; i <= max; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

ll spf(ll n, vi& primes) {
    for (ll prime : primes) {
        if (n % prime == 0) {
            return prime;
        }
        if (prime * prime > n) {
            break;
        }
    }
    return n;
}

vi primes;


void solve() {
    
    ans = spf(mn, primes);

}

int main() {

    primes = generatePrimes(MAX_SIEVE);

}






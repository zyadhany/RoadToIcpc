// big mod
bool mod(string &n, long long k) {
    long long rem = 0;
    for (auto i : n)
        rem = ((rem * 10) + i - '0') % k;
    return rem == 0;
}


double log_a_to_base_b(double a, double b) {
    return log2(a) / log2(b);
}


vector<pair<ll, ll>> prime_factoraization(ll n) {
    vector<pair<ll, ll>> fact;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt) {
            fact.push_back({i, cnt});
            if (cnt == 2)      fact.push_back({n, 1});
            else    fact.push_back({sqrt(n), 1});
            break;
        }
    }
    if (n > 1) fact.push_back({n, 1});
    return fact;
}


void matrix_multiply(vector<std::vector<int>>& A, 
                    vector<std::vector<int>>& B, 
                    vector<std::vector<int>>& C, 
                     int m, int n, int p) {
                        // A = m*n, B = n*p, C = m*p
    C.resize(m, std::vector<int>(p, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}


void greatest_prime_factor(int n) {
    // Check if N is prime
    if (prime(n)) {
        cout << "Prime" << endl;
        return;
    }

    // Find the greatest prime factor
    int max_prime = 1;
    int i = 2;
    while (i <= n / i) {
        if (n % i == 0) {
            n /= i;
            max_prime = i;
        } else {
            i++;
        }
    }
    if (n > max_prime) {
        max_prime = n;
    }

    cout << max_prime << endl;
}



// Function to calculate Euler's totient function of a
int phi(int a) {
    int result = a;
    for (int p = 2; p * p <= a; p++) {
        if (a % p == 0) {
            while (a % p == 0) {
                a /= p;
            }
            result -= result / p;
        }
    }
    if (a > 1) {
        result -= result / a;
    }
    return result;
}


// sum of odds up to num
long long sumOdd(long long num){
	long long res = (num + 1) / 2;
	long long finalRes = res * res;
	return finalRes;	
}

// sum of evens up to num
long long sumEven(long long n) {
    long long largestEven = (n % 2 == 0) ? n : n - 1;
    long long k = largestEven / 2;
    return k * (k + 1);
}


//sum of first n odds
long long sumOdd(long long n) {
    // The sum of the first n odd numbers is n^2
    return n * n;
}

// sum of first n evens
long long sumEven(long long num){
	long long res = (num*(num+1));
	return res;
}



// check if x,y,z can make traingle and prints its area
void triangle()
{
    int a,b,c;cin>>a>>b>>c;
    if (a+b>c && a+c>b && b+c>a)
    {
        cout<<"Valid\n";
        long double gg=(a+b+c)/2;
        cout<<fixed<<setprecision(6)<<sqrt(double(gg*(gg-a)*(gg-b)*(gg-c)));

    }

    else cout<<"Invalid";
}





long long gcd(long long int a, long long int b)
{
    // Recursive function to return gcd of a and b
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


long long lcm(int a, int b)
{
    // Function to return LCM of two numbers
    return (a / gcd(a, b)) * b;
}


// From decimal to binary
string bin(int x)
{
    string s;
    while(x)
    {
        if (x%2==0)s+="0";
        else s+="1";

        x=x/2;
    }
    reverse(s.begin(), s.end());
    return s;
}


// rotate matrix 90 degree
vector<vector<char>> rotate90DegreesClockwise(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
 
    vector<vector<char>> rotatedMatrix(cols, vector<char>(rows));
 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotatedMatrix[j][rows - 1 - i] = matrix[i][j];
        }
    }
 
    return rotatedMatrix;
}





// Function to count the number of times p divides n!
long long countDivisors(long long n, long long p) {
    long long count = 0;
    while (n > 0) {
        n /= p;
        count += n;
    }
    return count;
}

// Function to check if n! is divisible by m^k
bool isDivisible(long long n, long long m, long long k) {
    for (long long p = 2; p * p <= m; ++p) {
        if (m % p == 0) {
            long long cnt_m = 0;
            while (m % p == 0) {
                m /= p;
                ++cnt_m;
            }
            long long cnt_n = countDivisors(n, p);
            if (cnt_n < cnt_m * k) {
                return false;
            }
        }
    }
    if (m > 1) {
        long long cnt_n = countDivisors(n, m);
        if (cnt_n < k) {
            return false;
        }
    }
    return true;
}




// Find divisors from 1 to 1e6 in O(1)
const int MAXN = 1e6 + 5;
vi divisors(MAXN);

void preprocess_divisors() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j]++;
            //cout<<i<<' '<<j<<endl;
        }
    }
}

void solve(ll test){
    preprocess_divisors();
}
#include <vector>
#include <iostream>

 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 

const int SIZE = 1e6 + 1;
const int MODE = 998244353;
vi fac(SIZE, 1), facinv(SIZE, 1);

ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

ll modeenv(ll n) {
    ll x, y;
    gcdExtended(n, MODE, &x, &y);
    return (x + MODE) % MODE;
}

// nCr = fac(n)/fac(r)*fac(n-r)
ll nCr(ll n, ll r) {
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

// nPr = fac(n) / fac(n - r)
ll nPr(ll n, ll r) {
    ll res = (fac[n] * facinv[n - r]) % MODE;
    return (res);
}

void INIT() {
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = modeenv(fac[i]);
    }
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll summ = 0;

    for (int i = 1; i <= n; i++)
        summ = (summ + nPr(n, i)) % MODE;    

    cout << summ << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int size = 1;
    INIT();

    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
    return (0);
}

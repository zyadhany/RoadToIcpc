#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define viii vector<vii>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

/**
 * It use factorial fourmal of nCr,
 * use mod inv to avoid overflow.
 * Time O(n) - Build.
 * Time O(log(n)) - query.
 * Space O(n).
*/

const int SIZE = 1e6 + 1;
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
    if (r > n) return (0);
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

void INIT() {
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = modeenv(fac[i]);
    }
}


void solve(int tc) {
    ll n, k, summ = 0, l, r;

    cin >> n >> k;
    vi X(n + 1, INT32_MIN);

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    sortx(X);

    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        
        a = nCr(i - 1, k - 1);
        b = nCr(n - i, k - 1);
        //cout << a << ' ' << b << ' ' << X[i] << '\n';
        summ = (summ + (a * X[i]) % MODE) % MODE;
        summ = (summ - (b * X[i]) % MODE) % MODE;
        summ = (summ % MODE + MODE) % MODE;     
    }

    ll re = modeenv(nCr(n, k));
    summ *= re;
    summ %= MODE;
    cout << summ << '\n';
}

int main()
{
    INIT();
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

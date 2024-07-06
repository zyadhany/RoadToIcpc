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
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;


ll fpowr(ll b, ll exp)
{
    ll ret = 1;

    while (exp > 0) {
        if ((exp & 1) > 0)
            ret = (ret * b) % MODE;
        b = (b * b) % MODE;
        exp >>= 1;
    }

    return (ret % MODE);
}

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

/**
 * sol: r * (2^r - 1) - summtion(i*2^i)
 */
void solve(int tc) {
    ll n, sol, l, r;
    cin >> n;

    l = n * summPower(2, n - 1);
    l %= MODE;

    r = summKthPower(2, n - 1);

    sol = ((l - r) % MODE + MODE) % MODE;
    cout << sol << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

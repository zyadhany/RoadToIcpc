#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
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
 
const int SIZE = 1e7 + 1;
vi fac(SIZE, 1);
 
ll gcdExtended(ll a, ll b, ll* x, ll* y)
{
    if (a == 0) {
        *x = 0, * y = 1;
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
 
ll nCr(ll n, ll r) {
    ll res = fac[n];
    res *= modeenv((fac[r] * fac[n - r]) % MODE);
    return (res) % MODE;
}
 
// C(n) = (2n)! / ((n + 1)! * n!) 
vi catalanKparts(int n, ll k)
{
    vi C(n + 1, 0);
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i] = C[i - 1];
        C[i] *= ((2 * i + k - 1) * (2 * i + k)) % MODE;
        C[i] %= MODE;
        C[i] *= modeenv((i * (i + k + 1)) % MODE);
        C[i] %= MODE;
    }
    return (C);
}
 
void INIT() {
    for (int i = 2; i < SIZE; i++)
        fac[i] = (i * fac[i - 1]) % MODE;
}
 
 
void solve(int tc) {
    ll n, re = 0;
    string s;
    bool isit = 1;
    cin >> n >> s;
 
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') re++;
        else re--;
        if (re < 0) isit = 0;
    }
 
    n -= s.size();
    n -= re;
 
    if (n % 2 || !isit || n < 0) 
    {
        cout << "0\n";
        return;
    }
 
    vi X = catalanKparts(n / 2, re);
    cout << X[n / 2];
}
 
int main()
{
 
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    INIT();
 
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

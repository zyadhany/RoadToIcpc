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


using namespace std;

const int MODE = 1e9 + 7;


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

ll getExtendedRange(ll a, ll b, ll n) {
    ll x, y, d, xl, yl, l, r, re;
    d = gcdExtended(a, b, &x, &y);

    if (n % d) return -1;
    x *= n / d, y *= n / d;
    xl = b / d, yl = a / d;

    re = y / yl;

    if (y - re * yl > 0) re += abs(re)/re;

    return (x + re * xl) * a;
}

void solve() {
    ll n, m, a, b, re;

    cin >> n >> b >> a >> m;
    if (!n && !b && !a && !m) exit(0);

    m += a;
    if (n < m)swap(n, m), swap(a, b);

    re = getExtendedRange(a, b, n - m);

    if (re == -1) cout << "Impossible\n";
    else cout << re + m << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    while (1)
    {
        solve();
    }
}

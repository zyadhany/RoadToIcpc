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

/*
* solve: x*a + y*b = n.
*
* let d = gcd(a, b).
* from: x*a + y*b = d.
* if n = d * k -->>.
* (x * k) * a + (y * k) * b = d * k = n.
* now i got the value of x, y just need to make them postive.
* i can keep adding and subbstract by same value of x, y
*
* X = x + n * (b/d) ||| Y = y - n * (a/d).
* n can be any int from - to +.
*
* I want X & Y to be postive so.
* n >= ceil(-x / (b/d)) || n <= floor(y / (a/d)).
*
* Return: range l, r that n can be so x, y are postive.
*/
pair<ll, ll> getExtendedRange(ll a, ll b, ll n) {
    ll x, y, d, xl, yl, l, r;
    d = gcdExtended(a, b, &x, &y);

    // if n not divided by d then no sol.
    if (n % d) return { 0, -1 };

    x *= n / d, y *= n / d;
    xl = b / d, yl = a / d;
    l = ceil(-(double)x / xl);
    r = floor((double)y / yl);

    // l > r: so no value make them postive
    if (l > r) return { 0, -1 };
    return { l , r };
}


void solve(int tc) {
    ll n, a, b, c, summ = 0;

    cin >> a >> b >> c >> n;

    while (n >= 0)
    {
        pl res = getExtendedRange(a, b, n);
        summ += res.second - res.first + 1;
        n -= c;
    }

    cout << "Case " << tc << ": " << summ << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

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


pair<ll, ll> getRange(ll a, ll b, ll n) {
    ll x, y, g, xl, yl, l, r;

    g = gcdExtended(a, b, &x, &y);

    if (n % g) return { INT32_MAX, INT32_MAX };

    x *= n / g, y *= n / g;
    xl = b / g, yl = a / g;

    l = ceil(-(double)x / xl);
    r = floor((double)y / yl);

    if (l > r) return { INT32_MAX, INT32_MAX };
    return {l , r};
}

void solve(int n) {
    ll a, b, l, r, x, y, g;

    cin >> l >> a;
    cin >> r >> b;
    
    pl re = getRange(a, b, n);

    if (re.first == INT32_MAX) {
        cout << "failed\n";
        return;
    }


    ll s1, s2, xl, yl;

    g = gcdExtended(a, b, &x, &y);
    x *= n/g;
    y *= n/g;
    xl = b / g;
    yl = a / g;
    s1 = (x + xl * re.first) * l + (y - yl * re.first) * r;
    s2 = (x + xl * re.second) * l + (y - yl * re.second) * r;


    if (s1 <= s2)
    {
        x = x + xl * re.first;
        y = y - yl * re.first;
    }
    else
    {
        x = x + xl * re.second;
        y = y - yl * re.second;
    }

    cout << x << ' ' << y << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    cin >> size;
    while (size)
    {
        solve(size);
        cin >> size;
    }
}

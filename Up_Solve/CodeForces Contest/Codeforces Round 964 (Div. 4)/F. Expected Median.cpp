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
#define mc map<char,ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

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
    ll n, k;

    cin >> n >> k;

    ll one = 0, zer = 0;

    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;

        if (a) one++;
        else zer++;
    }
    
    ll summ = 0;
    for (int i = k / 2 + 1; i <= k; i++)
    {
        ll lef = k - i;

        if (i > one || lef > zer) continue;
        ll re = (nCr(one, i) * nCr(zer, lef)) % MODE; 
        summ = (summ + re) % MODE;
    }
    
    cout << summ << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    INIT();

    //freopen("buckets.in", "r", stdin);
    //freopen("buckets.out", "w", stdout);
    cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

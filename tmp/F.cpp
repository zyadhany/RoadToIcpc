// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 998244353;

using namespace std;

const int N = 1e7+1;
ll fac[N], facinv[N];

ll gcdex(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll ggcd = gcdex(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return ggcd;
}

ll inv(ll n) {
    ll x, y;
    gcdex(n, MODE, &x, &y);
    return (x+MODE) % MODE;
}
ll nPr(ll n, ll r) {
    ll res = (fac[n] * facinv[n - r]) % MODE;
    return (res);
}

ll nCr(ll n, ll r) {
    if (n<r || n <0) return 0;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n-r]) % MODE;
    return res % MODE;
}

ll catalon(ll n, ll k=0) {
    ll res = ((k+1) * nCr(2*n+k,n)) % MODE;
    res *= inv(n+1+k);
    return res % MODE;
}

void INIT() {
    fill(fac, fac+N, 1);
    fill(facinv, facinv+N, 1);
    for (int i = 2; i < N; i++)
    {
        fac[i] = (i*fac[i-1]) % MODE;
        facinv[i] = MODE - MODE/i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < N; i++)
    {
        facinv[i] =  (facinv[i] * facinv[i-1]) % MODE;
    }
}

void solve(int tc) {
    ll n;

    cin >> n;

    ll summ = 0, cnt = 0;

    for (int i = 1; i < n; i++)
    {
        ll re = catalon(n-1-i, i);
        cnt = (cnt + re) % MODE;
        summ = (summ + re*i) % MODE;
        cout << i << ' ' << re << "|\n";
    }
    
    cout << summ << ' ' << cnt << '\n';

    summ *= inv(cnt);
    cout << summ % MODE << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    INIT();
    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

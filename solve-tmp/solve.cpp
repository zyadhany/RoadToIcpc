#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <memory>
#include <sstream>
#include <cmath>

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


const int SIZE = 2e5 + 1;
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
    if (n < r) return 0;
    ll res = fac[n];
    res *= (facinv[r] * facinv[n - r]) % MODE;
    return (res) % MODE;
}

void INIT() {
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i < SIZE; i++) {
        fac[i] = (i * fac[i - 1]) % MODE;
        facinv[i] = MODE - MODE / i * facinv[MODE%i] % MODE;
    }
    for (int i = 2; i < SIZE; i++)
        facinv[i] = (facinv[i] * facinv[i-1])%MODE;
}

// Count combinations where a_1 + a_2 + ... + a_n = k, with 0 <= a_i < m.
ll count_combinations(ll n, ll m, ll k) {
    /**
     * Total combinations if there are no restrictions:
     * total = nCr(n + k - 1, k)
     *
     * Define f(i): Count of combinations where at least i elements are >= m.
     * Using Inclusion-Exclusion:
     * result = f(0) - nCr(n, 1) * f(1) + nCr(n, 2) * f(2) - ... + nCr(n, n) * f(n)
     */

    ll result = 0; // Final result
    for (int i = 0; i <= n; i++) {
        // If k - i * m becomes negative, no valid combinations exist.
        if (k - i * m < 0) break;

        // Calculate current term using Inclusion-Exclusion
        ll term = (nCr(n, i) * nCr(n + k - i * m - 1, n - 1)) % MODE;

        // Alternate addition and subtraction based on Inclusion-Exclusion principle
        if (i % 2 == 1) result = (result + MODE - term) % MODE;
        else result = (result + term) % MODE;
    }

    return result;
}

void solve(int tc) {
    ll n, m, k;
    cin >> m >> n >> k;
    cout << count_combinations(n, m, k) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

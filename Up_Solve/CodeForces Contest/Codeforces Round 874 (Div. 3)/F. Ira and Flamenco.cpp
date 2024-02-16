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

void solve(int tc) {
    ll n, m, summ = 0, l = 0, re = 1, k;
    
    cin >> n >> m;

    vi X(n);
    vp Z;

    for (int i = 0; i < n; i++)
        cin >> X[i];
    sortx(X);
    Z.push_back({ X[0] , 1 });

    for (int i = 1; i < n; i++)
    {
        if (X[i] == Z.back().first) Z.back().second++;
        else Z.push_back({ X[i] , 1 });
    }


    for (int i = 0; i < Z.size(); i++)
    {
        re *= Z[i].second;
        re %= MODE;
        if (i - l == m - 1) {
            if (Z[i].first - Z[l].first < m) {
                summ += re;
                summ %= MODE;
            }
            k = modeenv(Z[l].second);
            re *= k;
            re %= MODE;
            l++;
        }
    }

    cout << summ << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
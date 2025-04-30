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

const int MODE = 1e9 + 7;

using namespace std;


struct Matrix {
    ll n;
    vii a;
    Matrix(ll n) : n(n), a(n, vi(n)) {}
    Matrix operator*(const Matrix &b) const {
        Matrix c(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
};

Matrix matrixpower(Matrix a, ll n) {
    Matrix res(a.n);
    for (int i = 0; i < res.n; i++) res.a[i][i] = 1;
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll getpa(Matrix &adj, ll n) {
    auto dd = matrixpower(adj, n);
    ll summ = 0;
    for (auto a : dd.a) for (auto b : a) summ = (summ + b) % MODE;
    return summ;
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


void solve(int tc) {
    ll m, k;

    cin >> m >> k;

    ll n = 100;
    Matrix matt(n);
    matt.a[0][1] = k;
    matt.a[1][1] = 1;
    matt.a[2][3] = MODE-2;
    matt.a[3][3] = 1;


    assert(getpa(matt, m) == k);

    cout << n << '\n';
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matt.a[i][j] << ' ';
        }
        cout << '\n';
    }    
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

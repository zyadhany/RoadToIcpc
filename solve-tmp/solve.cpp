#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
using namespace std;
 
const int MODE = 1e9+7;

struct Matrix {
    ll n, m;
    vector<vector<ld>> a;
    Matrix(ll n) : n(n), m(n), a(n, vector<ld>(n, 0)) {}
    Matrix(ll n, ll m) : n(n), m(m), a(n, vector<ld>(m, 0)) {}
    Matrix operator*(const Matrix &b) const {
        Matrix c(n, b.m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < b.m; j++) {
                for (int k = 0; k < m; k++) {
                    c.a[i][j] += a[i][k] * b.a[k][j];
                }
            }
        }
        return c;
    }
};

Matrix matrixpower(Matrix a, ll n) {
    Matrix res(a.n);
    for (int i = 0; i < a.n; i++) res.a[i][i] = 1;
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}


void solve(int tc)  {
    ll n, m, k; cin >> n >> m >> k;

    vector<ld> X(n);
    Matrix Y(n, 1);
    for (int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        X[i] = (a <= m);
        Y.a[i][0] = X[i];
    }

    Matrix mt(n);
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cnt++;
            for (int h = i; h <= j; h++)
            {
                mt.a[h][j+i-h]++;
            }
            for (int h = 0; h < i; h++) mt.a[h][h]++;
            for (int h = j+1; h < n; h++) mt.a[h][h]++;            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mt.a[i][j] /= cnt;
        }
    }

    mt = matrixpower(mt, k);
    auto res = mt * Y;

    for (int i = 0; i < n; i++)
    {
        cout << fixed << setprecision(7) << res.a[i][0] << ' ';
    }
    cout << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    freopen("exam.in", "r", stdin);
    // freopen("phosphate.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}
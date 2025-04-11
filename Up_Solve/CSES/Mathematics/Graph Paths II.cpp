#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define vi vector<ll>
#define vii vector<vi>
#define pl pair<ll, ll>
#define all(X) X.begin(),X.end()
#define vp vector<pl>
#define mi map<ll,ll>
 
#define ld long double
#define vc vector<char>
#define vcc vector<vc>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;

const int MODE = 1e9+7;
const ll INF = (1ll << 62)-10;

struct Matrix {
    ll n;
    vii a;
    Matrix(ll n) : n(n), a(n, vi(n, INF)) {}
    Matrix operator*(const Matrix &b) const {
        Matrix c(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c.a[i][j] = min(c.a[i][j], a[i][k] + b.a[k][j]);
                }
            }
        }
        return c;
    }
};

Matrix matrixpower(Matrix a, ll n) {
    Matrix res(a.n);
    for (int i = 0; i < a.n; i++)
    {
        res.a[i][i] = 0;
    }
        
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solve(ll tc) {
    ll n, m, k;

    cin >> n >> m >> k;

    Matrix X(n);

    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        X.a[u][v] = min(X.a[u][v], w);
    }
    X = matrixpower(X, k);
    

    if (X.a[0][n-1] == INF) cout << -1 << '\n';
    else cout << X.a[0][n-1] << '\n';
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;   

    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

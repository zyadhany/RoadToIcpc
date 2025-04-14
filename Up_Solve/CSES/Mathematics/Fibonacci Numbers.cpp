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

struct Matrix {
    ll a[2][2];
    Matrix() {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix c;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MODE;
                }
            }
        }
        return c;
    }
};

Matrix matrixpower(Matrix a, ll n) {
    Matrix res;
    for (int i = 0; i < 2; i++) res.a[i][i] = 1;
    
    while (n) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

void solve(ll tc) {
    ll n;
    cin >> n;
    
    if (n == 0) cout << "0\n";
    else if (n <= 2) cout << "1\n";
    else {
        Matrix a;
        a.a[1][1] = a.a[0][1] = a.a[1][0] = 1;
        a.a[0][0] = 0;
        Matrix re = matrixpower(a, n);
        cout << re.a[1][0] << '\n';
    }
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

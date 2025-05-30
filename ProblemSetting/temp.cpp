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
    int a[20][20]={0};
    Matrix(ll n) : n(n) {}
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

const int MXN = 1e5 + 200;
vector<int> divs[MXN];

void solve(int tc) {
    ll n, q; cin >> n >> q;

    Matrix adj(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj.a[i][j];
        }
    }

    while (q--)
    {
        ll ty, u, v; cin >> ty >> u >> v;
        u--, v--;

        if (ty == 1) adj.a[u][v]++;
        else if(ty == 2) adj.a[u][v]--;
        else {
            ll sol = 0;
            ll k; cin >> k;
            for (auto d : divs[k])
            {
                sol += getpa(adj, d);
            }
            sol %= MODE;
            cout << sol << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    for (int i = 1; i < MXN; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                divs[i].push_back(j);
                if (j * j != i) divs[i].push_back(i / j);
            }
        }
    }
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

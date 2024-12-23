#define _CRT_SECURE_NO_WARNINGS
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>

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


const int SIZE = 1e6 + 1;
vi fac(SIZE, 1), facinv(SIZE, 1);

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

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vi Z(n + 10); Z[0] = Z[1] = 0, Z[2] = 1;
    for (int i = 3; i <= n; i++)
        Z[i] = ((i - 1) * (Z[i - 1] + Z[i - 2])) % m; 

    for (int i = 1; i <= n; i++) cout << Z[i] << ' ';    
    cout << '\n';    
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    INIT();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

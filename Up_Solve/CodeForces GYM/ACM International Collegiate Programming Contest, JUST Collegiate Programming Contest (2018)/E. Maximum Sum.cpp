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
#define vpp vector<vp>
#define vppp vector<vpp>
#define mi map<ll,ll>
#define unmi unordered_map<ll, ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 1e9 + 7;

using namespace std;
  
ll req(viii &Z, vii &X, ll at, ll bit) {
    ll n = X.size();
    ll l = at / n;
    ll r = at % n;
    if (l >= n) return(0);
    ll &res = Z[l][r][bit];
    if (~res) return(res);
    res = 0;

    if (bit & (1 << r)) return (res = req(Z, X, at + 1, bit - (1 << r)));
    res = req(Z, X, at + 1, bit);
    
    int bt = bit | (1 << r);
    if (r) bt |= (1 << (r - 1));
    if (r < n - 1) bt |= (1 << (r + 1));
    res = max(res, req(Z, X, at + 1 + (r != n - 1), bt) + X[l][r]);
    
    return (res);
}

void solve(int tc) {
    ll n;

    cin >> n;

    vii X(n, vi(n));
    viii Z(n, vii(n, vi(1 << n, -1)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];    

    cout << req(Z, X, 0, 0) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

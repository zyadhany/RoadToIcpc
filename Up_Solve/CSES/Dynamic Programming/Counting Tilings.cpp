#include <bits/stdc++.h>
#include <unordered_map>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char, ll>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
using namespace std;
 
const int MODE = 1e9 + 7;

void gnrateMask(vi &X, ll n, ll at, ll curmask, ll newmask) {
    if (at == n) {
        X.push_back(newmask);
        return;
    }

    if (at < n - 1 && !(curmask & (1 << at)) && !(curmask & (1 << (at + 1)))) {
        gnrateMask(X, n, at + 2, curmask, newmask);
    }

    if (curmask & (1 << at)) gnrateMask(X, n, at + 1, curmask, newmask);
    else gnrateMask(X, n, at + 1, curmask, newmask | (1 << at));
}

ll req(vii &Z, ll n, ll k) {
    if (n == Z.size()) return (k == 0);
    ll &res = Z[n][k];
    if (~res) return (res);
    res = 0;
    vi X;
    gnrateMask(X, log2(Z[0].size()), 0, k, 0);

    for (auto m : X)
        res = (res + req(Z, n + 1, m)) % MODE;

    return (res); 
}

void solve(ll tc) {
    ll n, m;

    cin >> n >> m;

    vii Z(m, vi(1 << n, -1));
    cout << req(Z, 0, 0);
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    //freopen("input.txt", "r", stdin   );
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

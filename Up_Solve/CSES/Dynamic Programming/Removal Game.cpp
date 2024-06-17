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
pl NEG = {-1, -1}; 

pl req(vector<vp> &Z, vi &X, ll l, ll r, ll tr) {
    if (l == r) {
        if (tr) return {X[l], 0};
        return {0, X[l]};
    }

    pl &res = Z[l][r];
    if (res != NEG) return (res);
    res= {0, 0};
    pl a = req(Z, X, l, r - 1, tr ^ 1);
    pl b = req(Z, X, l + 1, r, tr ^ 1);

    if (tr) a.first += X[r], b.first += X[l];
    else a.second += X[r], b.second += X[l];

    if (!tr) {
        if (a.second > b.second) res = a;
        else if (b.second > a.second) res = b;
        else res = min(a, b);
    }else {
        if (a.first > b.first) res = a;
        else if (b.first > a.first) res = b;
        else res = min(a, b);
    }

    return (res);
}

void solve(ll tc) {
    ll n;

    cin >> n;

    vi X(n + 1);
    vector<vp> Z(n + 1, vp(n + 1, {-1, -1}));
    for (int i = 1; i <= n; i++)
        cin >> X[i];

    cout << req(Z, X, 1, n, 1).first << '\n';
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

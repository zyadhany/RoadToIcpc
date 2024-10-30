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

const int MODE = 998244353;

using namespace std;

ll req(vii &dp, set<ll> &X, set<ll> &Y, ll l, ll r) {
    if (!l && !r) return (1);
    ll &res = dp[l][r];
    if (res != -1) return res;
    res = 0;

    ll at = l + r;

    if (l == r) {
        if (X.count(at)) return res;
        res += req(dp, X, Y, l, r - 1);
        return res;
    }

    if (l && !Y.count(at)) res += req(dp, X, Y, l - 1, r);
    if (r && !X.count(at)) res += req(dp, X, Y, l, r - 1);

    return res % MODE;
}

void solve(int tc) {
    ll n;

    cin >> n;
    ll x; cin >> x;
    set<ll> X;
    for (int i = 0; i < x; i++) {
        ll a; cin >> a;
        X.insert(a);
    }
    ll y; cin >> y;
    set<ll> Y;
    for (int i = 0; i < y; i++) {
        ll a; cin >> a;
        Y.insert(a);
    }

    vii dp(n + 1, vi(n + 1, -1));    
    cout << req(dp, X, Y, n, n);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

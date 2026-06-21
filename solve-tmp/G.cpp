// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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
#define int long long

using namespace std;

const int MODE = 998244353;
const int MOD2 = (MODE+1)/2;

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
    ll n;

    cin >> n;
    n = (1ll << n);
    vc X(n, '0');

    ll at = 0;
    X[1] = '1';
    for (int i = 0; i < n; i++)
    {
        cin >> X[i];
        if (X[i] == 'x') at = i;
    }
    

    ll nod = 0;
    vi N(n);
    vi V(4*n);
    vi P(4*n, -1);
    vp C(4*n);
    function<ll(ll, ll)> dfs = [&](ll l, ll r) -> ll {
        ll myn = nod;
        nod++;
        if (l == r) {
            N[l] = myn;
            if (X[l] == '1') V[myn] = 1;
            else if (X[l] == '?') V[myn] = MOD2;
            return myn;
        }

        ll mid = (l + r) / 2;
        ll a = dfs(l, mid);
        ll b = dfs(mid+1, r);
        P[a] = myn;
        P[b] = myn;
        C[myn] = {a, b};
        V[myn] = ((V[a] + V[b]) % MODE) * MOD2;
        V[myn] %= MODE;
        return myn;
    };

    function<ll(ll, ll)> get = [&](ll u, ll c) -> ll {
        if (u == -1) return 0;
        ll a = C[u].first;
        ll b = C[u].second;
        ll ret;
        if (a == c) ret = V[b];
        else ret = V[a];

        ret += (MOD2 * get(P[u], u)) % MODE;
        ret %= MODE;
        return ret;
    };

    dfs(0, n-1);
    ll res = get(P[N[at]], N[at]);
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

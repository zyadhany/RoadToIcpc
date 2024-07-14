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

ll k;
vector<viii> dp;


ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a % b));
}

/**
 * a*b = lcm() / gcd()
 * lcm() = union prime factors.
 * */  
ll lcm(ll a, ll b) 
{ 
    return (a / gcd(a, b)) * b; 
}

ll req(vector<viii> &dp, string &s, ll pos, ll lc, ll sml, ll zer) {
    if (pos == s.size()) return (lc == k);
    ll &res = dp[pos][lc][sml][zer];
    if (~res) return (res);
    res = 0;
    if (zer) res = req(dp, s, pos + 1, lc, 1, zer);

    ll lim = 9;
    if (!sml) lim = s[pos] - '0';

    for (int i = 1; i <= lim; i++)
        res += req(dp, s, pos + 1, lcm(lc, i), sml | i < lim, 0);
    
    if (pos < s.size() - 1)
    for (int i = 10; i <= lim * 10; i+=10) {
        int xsml = sml;
        if (i < lim * 10 || s[pos + 1] != '0') xsml = 1;
        res += req(dp, s, pos + 2, lcm(lc, i), xsml, 0);
    }
    
    return (res);
}

ll sol(ll n) {
    string s = to_string(n);
    dp.assign(12, viii(25201, vii(2, vi(2, -1))));
    return req(dp, s, 0, 1, 0, 1);
}

void solve(int tc) {
    ll l, r, res;
    cin >> l >> r >> k;

    res = sol(r) - sol(l - 1);
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);1
    //freopen("output.txt", "w", stdout);
    //cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
}

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
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}


const int MODE = 998244353;

using namespace std;

ll fpowr(ll b, ll exp)
{
    ll ret = 1;

    while (exp > 0) {
        if ((exp & 1) > 0)
            ret = (ret * b) % MODE;
        b = (b * b) % MODE;
        exp >>= 1;
    }

    return (ret % MODE);
}

map<ll, pl> dp;
pl req(ll n) {
    if (n == 0) return {0, 0};
    if (n == 1) return {1, 0};
    if (dp.count(n)) return dp[n];
    pl &res = dp[n];

    ll m = (n + 1) / 2;
    pl l = req(m);
    pl r = req(n - m);
    ll re = ((fpowr(2, m) - 1 + MODE) % MODE * (fpowr(2, n - m) - 1 + MODE) % MODE) % MODE;
    res.first = (re + 2 * l.first + 2 * r.first) % MODE;
    res.second = (l.second + r.first + r.second) % MODE;
    return (res);
}

void solve(int tc) {
    ll n;
    cin >> n;
    auto re = req(n);
    cout << (re.first + re.second) % MODE << '\n';
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
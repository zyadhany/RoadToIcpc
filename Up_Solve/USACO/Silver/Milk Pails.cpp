#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

#define ll long long
#define ld long double
#define pl pair<int, int>
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

const int MODE = 1e9;

using namespace std;

const int SZ = 4e3 + 10;
ll x, y, k, m;

ll req(vector<vii> &dp, ll l, ll r, ll t) {
    ll &res = dp[l][r][t];
    if (res != -1) return res;
    res = abs(m - l - r);
    if (!t) return res;
    res = min(res, req(dp, l, 0, t - 1));
    res = min(res, req(dp, l, y, t - 1));
    res = min(res, req(dp, 0, r, t - 1));
    res = min(res, req(dp, x, r, t - 1));
    res = min(res, req(dp, l - min(l, y - r), r + min(l, y - r), t - 1));
    res = min(res, req(dp, l + min(r, x - l), r - min(r, x - l), t - 1));

    return res;
}

void solve(int tc) {

    cin >> x >> y >> k >> m;

    vector<vii> dp(x + 1, vii(y + 1, vi(k + 1, -1)));

    cout << req(dp, 0, 0, k);
}  

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

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

// cur - prev - lead zero - tight
vector<vector<vii>> dp(20, vector<vii>(11, vii(2, vi(2, -1))));

ll req(string &s, ll cur, ll prev, ll lead, ll tight) {
    if (cur == s.size() - 1) {
        ll re;
        if (tight) re = s[cur] - '0';
        else re = 9;
        return (re + (prev > re)); 
    }
    ll &res = dp[cur][prev][lead][tight];
    if (~res) return (res);
    res = 0;

    ll l, r;
    if (tight) r = s[cur] - '0' - 1; 
    else r = 9;
    if (lead) l = 1;
    else l = 0;

    
    for (int i = l; i <= r; i++)
        if (i != prev) res += req(s, cur + 1, i, 0, 0);
    
    if (tight && s[cur] - '0' != prev) {
        res += req(s, cur + 1, s[cur] - '0', 0, 1);
    }

    if (lead) {
        res += req(s, cur + 1, 10, 1, 0);
    }
    return (res);
}
 
void solve(ll tc) {
    ll a, b;

    cin >> a >> b;

    string s = to_string(b);
    string t = to_string(a - 1);
    
    ll res = req(s, 0, 10, 1, 1);
    dp.assign(20, vector<vii>(11, vii(2, vi(2, -1))));
    if (a) res -= req(t, 0, 10, 1, 1);
    cout << res << '\n';
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

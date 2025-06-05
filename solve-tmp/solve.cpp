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
using namespace std;

const int MODE = 998244353;

vp get(ll s, ll n) {
    ll tm1 = sqrt(n);
    ll tm2 = tm1 + (tm1 * tm1 != n);
    tm1 += (tm1 * tm2 < n);
    ll mxv = 2*n+2;
    ll mnv = 2*(tm1 + tm2); 
    if (s > mxv || s < mnv || s%2) return {};
    ll rem = 4*n - s;
    rem /= 2;
    
    vp res(1, {0, 0});
    
    ll len = 1;
    while (n - res.size() < rem && res.size()<n) {
        for (int i = 0; i < len && n - res.size() < rem && res.size()<n; i++) {
            res.push_back({i, len});
            rem--;
            if (i) rem--;
        }
        for (int i = 0; i < len && n - res.size() < rem && res.size()<n; i++) {
            res.push_back({len, i});
            rem--;
            if (i) rem--;
        }
        if (n - res.size() < rem && res.size()<n) {
            res.push_back({len, len});
            rem-=2;
        }
        len++;
    }

    for (int i = -1; res.size() < n; i--) res.push_back({i, 0}), rem--;
    return res;
}

void solve(int tc) {
    ll n; 
    cin >> n;
 
    ll cnt = 1, at = 1;
    while (at < n)
    {
        at = at * 2 + 1;
        cnt++;
    }
    
    cout << cnt * 2 + 1 << '\n';
}

void solve(int tc) {
    ll a, b;
    cin >> a >> b;

    ll g = gcd(a, b);
    a /= g, b /= g;

    vp res;
    for (int i = 1; i*b <= 5e4; i++)
    {
        res = get(i*a, i*b);
        if (!res.empty()) break;
    }    

    if (res.empty()) MUN;
    cout << res.size() << '\n';
    for (auto p : res) cout << p.first << ' ' << p.second << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("cownav.in", "r", stdin);
    // freopen("cownav.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
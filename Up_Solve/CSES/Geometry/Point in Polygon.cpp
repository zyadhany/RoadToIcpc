#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
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
 
ll CrossProduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}
 
// 1(LEFT), 0(TOUCH), -1(RIGHT)
int PointLocation(pl a, pl b, pl c) {
    ll res = CrossProduct({b.first - a.first, b.second - a.second}, {c.first - a.first, c.second - a.second});
    if (res > 0) return 1;  // LEFT
    if (res < 0) return -1; // RIGHT
    return 0; // TOUCH (collinear)
}
 
bool online(pl a, pl b, pl c) {
    ll re = PointLocation(a, b, c);
    return (re == 0 && c.first >= min(a.first, b.first) && c.first <= max(a.first, b.first) && c.second >= min(a.second, b.second) && c.second <= max(a.second, b.second));
}
 
bool intersect(pl a1, pl a2, pl b1, pl b2) {
	ll x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = min(a1.first, a2.first), x2 = max(a1.first, a2.first);
	y1 = min(a1.second, a2.second), y2 = max(a1.second, a2.second);
	x3 = min(b1.first, b2.first), x4 = max(b1.first, b2.first);
	y3 = min(b1.second, b2.second), y4 = max(b1.second, b2.second);
	if ((x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1)) return 0;
 
    int d1 = PointLocation(a1, a2, b1);
    int d2 = PointLocation(a1, a2, b2);
    int d3 = PointLocation(b1, b2, a1);
    int d4 = PointLocation(b1, b2, a2);
 
    return (d1 * d2 <= 0 && d3 * d4 <= 0);
}
 
int isInside(vp &X, pl p) {
    ll cnt = 0;
    pl p2 = {p.first+1, INT32_MAX}; // No int point between p and p2
    for (int i = 0; i < X.size(); i++) {
        cnt += intersect(X[i], X[(i + 1) % X.size()], p, p2);
        if (online(X[i], X[(i + 1) % X.size()], p)) return 0; // TOUCH
    }
    if (cnt % 2) return 1; // INSIDE
    return -1; // OUTSIDE
}
 
void solve(ll tc) {
    ll n, m;
 
    cin >> n >> m;
 
    vp X(n);
    for (int i = 0; i < n; i++)
    {
        cin >> X[i].first >> X[i].second;
    }
    
    while (m--)
    {
        ll a, b; cin >> a >> b;
        ll re = isInside(X, {a, b});
        if (re == 1) cout << "INSIDE\n";
        else if (re == -1) cout << "OUTSIDE\n";   
        else cout << "BOUNDARY\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
 
    // freopen("disrupt.in", "r", stdin   );
    // freopen("disrupt.out", "w", stdout);
    // cin >> size;
    for (int tc = 1; tc <= size; tc++){
        solve(tc);
       // if (tc != size) cout << '\n';
    }
}

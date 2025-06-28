#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
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
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 998244353;

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

// get a where a = a1 (mod m1) and a = a2 (mod m2)
pl CRT(ll a1, ll m1, ll a2, ll m2) {
	if (a2 < a1) {
		swap(a1, a2);
		swap(m1, m2);
	}
	ll x, y;
	ll d = a2 - a1;
	ll m = lcm(m1, m2);
	ll g = gcdExtended(m1, m2, &x, &y);
	if (d % g != 0) return {-1, -1}; // no solution
	x = (x * (d / g)) % (m2 / g);
	if (x < 0) x += (m2 / g);
	ll ans = (a1 + x * m1) % m;
	if (ans < 0) ans += m;
	return {ans, m};
}

void solve(int tc) {
	ll a, n, b, m;

	cin >> a >> n >> b >> m;
	cout << CRT(a, n, b, m).first << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

	// freopen("yinyang.in", "r", stdin);
    // freopen("yinyang.out", "w", stdout);
 
    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

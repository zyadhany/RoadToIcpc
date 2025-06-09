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
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
const int MODE = 1e9 + 7;
 
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
 
struct LineContainer {
    multiset<Line> hull;
 
    static const ll inf = LLONG_MAX;
 
    struct cmpK {
        bool operator()(const Line &a, const Line &b) const {
            return a.k < b.k;
        }
    };
 
    struct cmpP {
        bool operator()(const Line &a, const Line &b) const {
            return a.p < b.p;
        }
        bool operator()(const Line &a, const ll &x) const {
            return a.p < x;
        }
        bool operator()(const ll &x, const Line &a) const {
            return x < a.p;
        }
    };
 
    using iter = multiset<Line, cmpK>::iterator;
    multiset<Line, cmpK> s;
 
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
 
    bool isect(iter x, iter y) {
        if (y == s.end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
 
    void add(ll k, ll m) {
        k *= -1, m *= -1;
        auto z = s.insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = s.erase(z);
        if (x != s.begin() && isect(--x, y)) isect(x, y = s.erase(y));
        while ((y = x) != s.begin() && (--x)->p >= y->p)
            isect(x, s.erase(y));
    }
 
    ll query(ll x) {
        assert(!s.empty());
        Line dummy{0, 0, x};
        auto l = *lower_bound(s.begin(), s.end(), x, cmpP());
        return -(l.k * x + l.m);
    }
};
 
 
void solve(int tc) {
	ll n, k;
	cin >> n >> k;
 
	vi X(n), V(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
		V[i] = X[i] * i;
		if (i) X[i] += X[i-1], V[i] += V[i-1];
	}
 
	viii dp(n, vii(k+1, vi(2)));
	vector<vector<LineContainer>> lc(k+1, vector<LineContainer>(2));
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			lc[i][j].add(0, 0);
		}
	}
 
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// from j to m
			dp[i][j][0] = lc[j-1][1].query(i) + i*X[i]-V[i];
			lc[j][0].add(-i, i*X[i]-V[i]+dp[i][j][0]);
			
						cout << dp[i][j][0] << ' ' << i*X[i]-V[i]+dp[i][j][0] << " ";
			cout << lc[j][0].query(X[i]) << "||\n";
			// from m to i
			dp[i][j][1] = lc[j][0].query(X[i])+V[i];
			lc[j][1].add(-X[i],dp[i][j][1]+V[i]);
		}
	}
	
 
	cout << dp[n-1][k][1] << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	// freopen("cownav.in", "r", stdin);
    // freopen("cownav.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
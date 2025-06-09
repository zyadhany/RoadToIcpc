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

struct monotonic_dp_hull {
    struct line {
        ll k, b;
        ll eval(ll x) { return k * x + b; }
    };

    bool bad(const line &a, const line &b, const line &c) {
        return (c.b - a.b) * (a.k - b.k) <= (b.b - a.b) * (a.k - c.k);
    	// return (__int128)(c.b - a.b) * (a.k - b.k) <= (__int128)(b.b - a.b) * (a.k - c.k); if overflow is a concern
    }

    std::deque<line> lines;

    void add(ll k, ll b) {
        assert(lines.empty() ||
               k >= lines.back().k); // ensure slope is monotonic
        line cur{k, b};
        while (lines.size() >= 2 && bad(lines.rbegin()[1], lines.back(), cur))
            lines.pop_back();
        lines.push_back(cur);
    }

    ll query(ll x) {
        assert(!lines.empty());
        while (lines.size() >= 2 && lines[0].eval(x) <= lines[1].eval(x))
            lines.pop_front();
        return lines[0].eval(x);
    }
};

void solve(int tc) {
	ll n, k;

	cin >> n >> k;

	vi X(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
		if (i) X[i] += X[i-1];
	}
	

	vii dp(n, vi(k+1));
	vector<monotonic_dp_hull> lc(k+1);
	for (int i = 0; i <= k; i++)
	{
		lc[i].add(0, 0);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{	
			dp[i][j] = -lc[j-1].query(X[i]) + X[i]*X[i];
			lc[j].add(2*X[i], -(X[i]*X[i]+dp[i][j]));
		}
	}	

	cout << dp[n-1][k];
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

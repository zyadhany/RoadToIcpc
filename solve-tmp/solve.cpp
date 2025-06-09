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

struct line {
	ll k, b;
	ll eval(ll x) { return k * x + b; }
};

bool bad(const line &a, const line &b, const line &c) {
	return (__int128)(c.b - a.b) * (a.k - b.k) <= (__int128)(b.b - a.b) * (a.k - c.k);
}

struct monotonic_dp_hull {


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

const int MXN = 3010;
ll dp[MXN][MXN][2]{};
deque<line> lc[MXN][2];

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
	
	for (int i = 0; i <= k; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			lc[i][j] = deque<line>(1, {0, 0});
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			// from j to m
			// while (lines.size() >= 2 && lines[0].eval(x) <= lines[1].eval(x))
    	    //     lines.pop_front();
	        // return lines[0].eval(x);

			while (lc[j-1][1].size() >= 2 && lc[j-1][1][0].eval(i) <= lc[j-1][1][1].eval(i))
				lc[j-1][1].pop_front();
			dp[i][j][0] = -lc[j-1][1][0].eval(i) + i*X[i]-V[i];
			line cur{i, -(i*X[i]-V[i]+dp[i][j][0])};
			while (lc[j][0].size() >= 2 && bad(lc[j][0].rbegin()[1], lc[j][0].back(), cur))
				lc[j][0].pop_back();
			lc[j][0].push_back(cur);
			
			// from m to i

			while (lc[j][1].size() >= 2 && lc[j][1][0].eval(X[i]) <= lc[j][1][1].eval(X[i]))
				lc[j][1].pop_front();
			dp[i][j][1] = -lc[j][0][0].eval(X[i])+V[i];

			cur = {X[i], -(dp[i][j][1]+V[i])};
			while (lc[j][1].size() >= 2 && bad(lc[j][1].rbegin()[1], lc[j][1].back(), cur))
				lc[j][1].pop_back();
			lc[j][1].push_back(cur);
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
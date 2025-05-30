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
const int MXN =	1e6+10;
const int lg = 63;
int dp[MXN][lg];


void solve(int tc) {
	ll n, k, m;

	cin >> n >> k >> m;

	vi X(n), Z(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
	}

	for (int i = 0; i < n; i++)
	{
		ll l = 0, r = i - 1;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			ll cnt = i - mid + 1;
			
			ll la = i, ra = n-1;
			while (la < ra)
			{
				ll ma = (la + ra + 1) / 2;
				if (X[ma]-X[i]<X[i]-X[mid]) la = ma;
				else ra = ma - 1;
			}
			cnt += la-i;

			if (cnt == k-1) Z[i]=mid;
			if (cnt < k) r = mid - 1;
			else l = mid + 1;
		}
	}
	reverse(all(X));
	for (int i = 0; i < n; i++)
	{
		ll l = 0, r = i - 1;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			ll cnt = i - mid + 1;
			
			ll la = i, ra = n-1;
			while (la < ra)
			{
				ll ma = (la + ra + 1) / 2;
				if (X[ma]-X[i]<=X[i]-X[mid]) la = ma;
				else ra = ma - 1;
			}
			cnt += la-i;

			if (cnt == k-1) Z[i]=n-mid-1;
			if (cnt < k) r = mid - 1;
			else l = mid + 1;
		}
	}
	
	

	for (int i = 0; i < n; i++) dp[i][0] = Z[i];
	for (int j = 1; j < lg; j++)
	{
		for (int i = 0; i < n; i++)
		{
			dp[i][lg] = dp[dp[i][lg-1]][lg-1];
		}
	}
	
	vi res(n);

	for (int i = 0; i < n; i++)
	{
		ll at = i;
		for (ll j = 0; j < lg; j++)
		{
			if (m & (1ll<<j)) {
				at = dp[at][j];
			}
		}
		
		res[i] = at + 1;
	}
	

	for (auto a : res) cout << a << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("lightsout.in", "r", stdin);
    // freopen("lightsout.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
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

const ll INF = 1e16;
const int MXN = 3e3 + 10;
ll dp[MXN][MXN];

void dac(deque<ll> &X, deque<ll> &V, ll k, ll l, ll r, ll optl, ll optr) {
	if (l > r) return;
	ll mid = (l+r)>>1;

	pl best = {INF, optl};
	for (int i = optl; i <= min(mid, optr); i++)
	{
		ll c = V[mid]-V[i] - (i+1)*(X[mid]-X[i]);
		best = min(best, pl(dp[i][k-1] + c, i));
	}
	
	dp[mid][k] = best.first;
	ll opt = best.second;
	dac(X, V, k, l, mid-1, optl, opt);
	dac(X, V, k, mid+1, r, opt, optr);
}

void solve(int tc) {
	ll n, k;

	cin >> n >> k;

	deque<ll> X(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
	}
	
	for (int i = 1; i <= n; i++) dp[i][0] = INF;
	dp[0][0] = 0;

	ll mn = INF;
	for (int i = 0; i < n; i++)
	{
		X.push_back(X[0]);
		X.pop_front();
		deque<ll> Z(all(X));
		deque<ll> V(all(X));
		Z.push_front(0);
		V.push_front(0);
		for (int j = 1; j <= n; j++)
		{
			Z[j] += Z[j-1];
			V[j] = j*V[j] + V[j-1];
		}
		
		for (int j = 1; j <= k; j++)
		{
			dac(Z, V, j, 1, n, 0, n-1);
		}
	
		mn = min(mn, dp[n][k]);
	}
	
	cout << mn << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
	freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

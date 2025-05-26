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


ll req(ll n) {
	if (n % 2) return 1;
	return 2 * req(n / 2);
}

void solve(int tc) {
	ll n, k;
	cin >> n >> k;

	vi X(n+10);

	ll summ = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> X[i];
		summ += req(X[i]);
	}
	
	vi dpl(n+10), dpr(n+10);

	for (int i = 2; i <= n; i++)
	{
		ll nv = 1;
		ll x = X[i];
		while (x % 2 == 0 && x/2 != X[i-1])
		{
			nv *= 2;
			x /= 2;
		}
		dpr[i] = req(X[i]) - nv + dpr[i-1];
	}
	
	for (int i = n-1; i >= 1; i--)
	{
		ll nv = 1;
		ll x = X[i];
		while (x % 2 == 0 && x/2 != X[i+1])
		{
			nv *= 2;
			x /= 2;
		}
		dpl[i] = req(X[i]) - nv + dpl[i+1];
	}

	ll mn = INT32_MAX;
	for (int i = 1; i <= n; i++) {
		cout << dpl[i] << " " << dpr[i] << ln;
		mn = min(mn, dpl[i-1] + dpr[i+1]);
	}

	summ -= mn;
	if (summ >= k) YES;
	NO;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("lightsout.in", "r", stdin);
    // freopen("lightsout.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

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

void solve(int tc) {
	ll n;

	cin >> n;
	vi X(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> X[i];
	}
	sortx(X);

	vi prf(X);
	for (int i = 1; i <= n; i++)
	{
		prf[i] += prf[i - 1];
	}
	

	ll ind=1, sz=1, val = -1;

	auto f = [&](ll i, ll k) -> ld {
		ll sz = k*2+1;
		ld summ = prf[n]-prf[n-k] + prf[i]-prf[i-1-k];
		summ /= sz;
		return summ - X[i];
	};

	for (int i = 1; i <= n; i)
	{
		ll l = 0, r = min(i-1ll, n - i);
		while (r - l > 3) {
			int m1 = l + (r - l) / 3;
			int m2 = r - (r - l) / 3;
			f(i, m1) < f(i, m2) ? l = m1 : r = m2;
		}

		int res = l;
		for (int j = l+1; j <= r; j++) {
			if (f(i, j) > f(i, res)) { res = j; }
		}

		if (f(i, res) > val) {
			val = f(i, res);
			ind = i;
			sz = 2*i+1;
		}
	}
	
	vi res;
	res.push_back(X[ind]);
	if (sz%2 == 0) res.push_back(X[ind+1]);
	for (int i = 0; i < i/2; i++)
	{
		res.push_back(X[n-i]);
		res.push_back(X[ind-i-1]);
	}

	sortx(res);
	cout << res.size() << '\n';
	for (auto a : res) cout << a << ' ';
	cout << '\n';
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
#include "bits/stdc++.h"
#define ll int
#define vi vector<ll>
#define pl pair<ll, ll>
#define vp vector<pl>
#define vii vector<vi>
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
using namespace std;
#define ln "\n"

const int MODE = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;

	vi A(n), B(n);
	for (int i = 0; i < n-1; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];


	auto run = [&](ll val) {
		vi dp(n, INF), g(n);
		deque<ll> dq;
		dp[0] = 0;
		dq.push_back(0);
		for (int i = 1; i < n; i++)
		{
			ll bestcost = dp[i-1] + A[i-1];
			ll bestf = g[i-1];
			while (!dq.empty() && dq.front()<i-k) dq.pop_front();
			if (!dq.empty()) {
				int j = dq.front();
				ll c = dp[j] + B[j] + B[i] + val;
				if (c  < bestcost) {
					be
				}
			}
		}
		
	}
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
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
const ll INF = 1e16;

void solve(int tc) {
	ll n, k;
	cin >> n >> k;

	vi X(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i]; X[i]--;
	}
	
	vii adj(k, vi(k));
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			char c; cin >> c;
			adj[i][j] = (c=='1');
		}
	}


	vi sol(n, INF);
	ll ti = 50;	
	while (ti--) {
		vi dp(k, INF), Z(k, -1);
		dp[X[0]] = 0; Z[X[0]]=0, sol[0] = 0;
		
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (adj[j][X[i]]) {
					sol[i] = min(sol[i], dp[j]+i);
				}
			}
			Z[X[i]] = i;

			dp[X[i]] = min(dp[X[i]], sol[i]-i);
			
			for (int j = 0; j < k; j++)
			{
				if (Z[j] == -1 || !adj[X[i]][j]) continue;
				sol[Z[j]] = min(sol[Z[j]], sol[i]+i-Z[j]);
				dp[j] = min(dp[j], sol[Z[j]]-Z[j]);
			}
		}
	}

	if (sol[n-1] == INF) cout << "-1\n";
	else cout << sol[n-1] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    // freopen("gravity.in", "r", stdin);
    // freopen("gravity.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}
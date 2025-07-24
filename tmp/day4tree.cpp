
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

const int MODE = 1e9 + 7;

using namespace std;

const ll INF = 1e16;

void dfs(vii &adj, map<ll, vi> &mp, vi &X, ll n, ll p) {
	X[n] ^= X[p];
	mp[X[n]].push_back(n);
	for (auto neg : adj[n]) if (neg != p) {
		dfs(adj, mp, X, neg, n);
	}
}

void solve(int tc) {
    ll n, q;
    cin >> n >> q;

	vi X(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> X[i];
	}
	
	vii adj(n+1);
	for (int i = 0; i < n-1; i++)
	{
		ll u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	map<ll, vi> mp;
	dfs(adj, mp, X, 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cout << i << ' ' << X[i] << "|\n";
	}
	

	for (auto &[u, v] : mp) sortx(v);

	while (q--)
	{
		ll u, v;
		cin >> u >> v;
		vi &Z = mp[X[v]];

		ll res = -1;
		for (int i = 0; i < Z.size(); i++)
		{
			if (Z[i] != u && Z[i] != v) {
				res = Z[i];
				break;
			}
		}
		cout << res << '\n';
	}
	
}

int main()  
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // INIT();
    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

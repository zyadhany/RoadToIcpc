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
#define NO {cout << "No\n"; return;}
#define MUN {cout << "-1\n"; return;}
using namespace std;
 
const int MODE = 998244353;

const int MXN = 1e5;
vi adj[MXN];
ll P[MXN]{}, vis[MXN]{};

bool dfs(ll u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	for (auto neg : adj[u]) {
		if (!P[neg]) {
			P[neg] = u, P[u] = neg;
			return 1;
		}
		if (dfs(P[neg])) {
			P[neg] = u, P[u] = neg;
			return 1;
		}
	}
	return 0;
}

void solve(int tc) {
    ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		ll u, v; cin >> u >> v;
		adj[u].push_back(v+n);
	}

	for (int i = 1; i <= n; i++)
	{
		if(!P[i]) {
			fill(vis, vis+n+1, 0);
			dfs(i);
		}
	}

	vp res;
	for (int i = 1; i <= n; i++)
	{
		if (P[i]) res.push_back({i, P[i]-n});
	}
	
	cout << res.size() << '\n';
	for (auto p : res) cout << p.first << ' ' << p.second << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

	// freopen("yinyang.in", "r", stdin);
    // freopen("yinyang.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

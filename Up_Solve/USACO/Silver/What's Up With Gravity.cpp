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
	ll n, m;

	cin >> n >> m;

	pl st, en;
	vcc X(n, vc(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> X[i][j];
			if (X[i][j] == 'C') st = {i, j};
			if (X[i][j] == 'D') en = {i, j};			
		}
	}

	vector<vii> vis(n, vii(m, vi(2)));
	vector<vii> dp(n, vii(m, vi(2, INF))); 
	deque<pair<pl, ll>> q;
	q.push_back({st, 0});
	dp[st.first][st.second][0] = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front().first;
		auto md = q.front().second;
		q.pop_front();
		if (vis[x][y][md]) continue;
	
		vis[x][y][md] = 1;
		ll nx, ny, nm, nw;
		
		if (!md) {
			if (x == n-1 ) continue;
			if (X[x+1][y] != '#') {
				nx = x+1, ny = y, nm = md, nw = dp[x][y][md];
				if (dp[nx][ny][nm] > nw) {
					dp[nx][ny][nm] = nw;
					q.push_front({{nx, ny}, nm});
				}
				continue;
			}
		} else {
			if (x == 0) continue;
			if (X[x-1][y] != '#') {
				nx = x-1, ny = y, nm = md, nw = dp[x][y][md];
				if (dp[nx][ny][nm] > nw) {
					dp[nx][ny][nm] = nw;
					q.push_front({{nx, ny}, nm});
				}
				continue;
			}
		}

		nx = x, ny = y, nm = (md^1), nw = dp[x][y][md] + 1;
		if (dp[nx][ny][nm] > nw) {
			dp[nx][ny][nm] = nw;
			q.push_back({{nx, ny}, nm});
		}

		if (y) {
			nx = x, ny = y-1, nm = md, nw = dp[x][y][md];
			if (X[nx][ny] != '#' && dp[nx][ny][nm] > nw) {
				dp[nx][ny][nm] = nw;
				q.push_front({{nx, ny}, nm});
			}
		}

		if (y != m-1) {
			nx = x, ny = y+1, nm = md, nw = dp[x][y][md];
			if (X[nx][ny] != '#' && dp[nx][ny][nm] > nw) {
				dp[nx][ny][nm] = nw;
				q.push_front({{nx, ny}, nm});
			}
		}
	}
	
	ll res = min(dp[en.first][en.second][0], dp[en.first][en.second][1]);
	if (res == INF) cout << "-1\n";
	else cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    

    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size ; i++) solve(i);
    return 0;
}

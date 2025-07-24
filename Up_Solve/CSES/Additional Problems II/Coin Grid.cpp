// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx,avx2")
// #pragma GCC optimize("unroll-loops")

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

struct Dinic {     // flow template
	using F = ll;  // flow type
	struct Edge {
		int to;
		F flo, cap;
	};
	int N;
	vector<Edge> eds;
	vector<vi> adj;
	void init(int _N) {
		N = _N;
		adj.resize(N), cur.resize(N);
	}
	/// void reset() { trav(e,eds) e.flo = 0; }
	void ae(int u, int v, F cap, F rcap = 0) {
		assert(min(cap, rcap) >= 0);
		adj[u].push_back(eds.size());
		eds.push_back({v, 0, cap});
		adj[v].push_back(eds.size());
		eds.push_back({u, 0, rcap});
	}
	vi lev;
	vector<vi::iterator> cur;
	bool bfs(int s, int t) {  // level = shortest distance from source
		lev = vi(N, -1);
		for (int i = 0; i < N; i++)
		{
			cur[i] = begin(adj[i]);
		}
		queue<int> q({s});
		lev[s] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto e : adj[u]) {
				const Edge &E = eds[e];
				int v = E.to;
				if (lev[v] < 0 && E.flo < E.cap) q.push(v), lev[v] = lev[u] + 1;
			}
		}
		return lev[t] >= 0;
	}
	F dfs(int v, int t, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge &E = eds[*cur[v]];
			if (lev[E.to] != lev[v] + 1 || E.flo == E.cap) continue;
			F df = dfs(E.to, t, min(flo, E.cap - E.flo));
			if (df) {
				E.flo += df;
				eds[*cur[v] ^ 1].flo -= df;
				return df;
			}  // saturated >=1 one edge
		}
		return 0;
	}
	F maxFlow(int s, int t) {
		F tot = 0;
		while (bfs(s, t))
			while (F df = dfs(s, t, numeric_limits<F>::max())) tot += df;
		return tot;
	}
};

vi minvertexcover(ll n, ll m, vp edges) {
	Dinic D;
	D.init(n + m + 2);
	for (int i = 1; i <= n; i++)
	{
		D.ae(0, i, 1); // from src to i with cap=1
	}
	for (int i = 1; i <= m; i++)
	{
		D.ae(n+i, n+m+1, 1); // from i+n to think with cap = 1
	}
	
	for (auto [a, b] : edges) {
		D.ae(a, b, MODE);
	}

	vi res;
	D.maxFlow(0, n + m + 1);
	D.bfs(0, 2 * n + 1);
	for (int i = 1; i <= n; i++) if (D.lev[i] < 0) res.push_back(i); // edge from src to i is cut
	for (int i = 1; i <= m; i++) if (D.lev[i + n] >= 0) res.push_back(i + n); // edge from i+n to think is cut
	return res;
}

void solve(int tc) {
	ll n;

	cin >> n;

	vp E;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == 'o') {
				E.push_back({i + 1, j + 1 + n});
			}
		}
	}
	vi res = minvertexcover(n, n, E);
	cout << res.size() << '\n';
	for (auto x : res) {
		if (x <= n) cout << "1 " << x << '\n';
		else cout << "2 " << x - n << '\n';
	}
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("strings.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

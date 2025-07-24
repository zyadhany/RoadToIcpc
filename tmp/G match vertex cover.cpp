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

// In Barbartide graph you have n vertex on left and m in right and edges connect them.
ll minvertexcover(ll n, ll m, vp edges) {
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

	return D.maxFlow(0, n + m + 1);
}

struct HopcroftKarp {
  static const int inf = 1e9;
  int n;
  vector<int> l, r, d;
  vector<vector<int>> g;
  HopcroftKarp(int _n, int _m) {
    n = _n;
    int p = _n + _m + 1;
    g.resize(p);
    l.resize(p, 0);
    r.resize(p, 0);
    d.resize(p, 0);
  }
  void add_edge(int u, int v) {
    g[u].push_back(v + n); //right id is increased by n, so is l[u]
  }
  bool bfs() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
      if (!l[u]) d[u] = 0, q.push(u);
      else d[u] = inf;
    }
    d[0] = inf;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (d[r[v]] == inf) {
          d[r[v]] = d[u] + 1;
          q.push(r[v]);
        }
      }
    }
    return d[0] != inf;
  }
  bool dfs(int u) {
    if (!u) return true;
    for (auto v : g[u]) {
      if(d[r[v]] == d[u] + 1 && dfs(r[v])) {
        l[u] = v;
        r[v] = u;
        return true;
      }
    }
    d[u] = inf;
    return false;
  }
  int maximum_matching() {
    int ans = 0;
    while (bfs()) {
      for(int u = 1; u <= n; u++) if (!l[u] && dfs(u)) ans++;
    }
    return ans;
  }
};


void solve(int tc) {
	ll n, m;
	cin >> n >> m;

	vector<string> X(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
	}
	ll t; cin >> t;
	string s; cin >> s;

	ll cur = 1;
	vii id(n, vi(m,-1));
	vii adj(n*m);
	for (int i = 0; i < n; i++)
	{
		ll at = 0;
		for (int j = 0; j < m; j++)
		{
			if (X[i][j] == s[at]) {
				at++;
				if (at == s.size()) {
					for (int k = 0; k < s.size(); k++)
						id[i][j-k] = cur;					
					cur++;
					at = 0;
				}
			} else at = (X[i][j] == s[0]);
		}
	}

	vp E;
	ll sz1 = cur-1;
	for (int j = 0; j < m; j++)
	{
		ll at = 0;
		for (int i = 0; i < n; i++)
		{
			if (X[i][j] == s[at]) {
				at++;
				if (at == s.size()) {
					for (int k = 0; k < s.size(); k++) {
						if (id[i-k][j] == -1) continue;
						E.push_back({id[i-k][j], cur});                        
					}
					at = 0;
					cur++;
				}
			} else at = (X[i][j] == s[0]);
		}
	}
	HopcroftKarp HK(sz1, cur - sz1 - 1);
	cout << sz1 << ' ' << cur - sz1 - 1 << '\n';
	for (auto [a, b] : E) {
		HK.add_edge(a, b);
	}
	
	// ll res = minvertexcover(sz1, cur - sz1-1, E);
	ll res = HK.maximum_matching();
	cout << cur - res - 1 << '\n';	
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("grid.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

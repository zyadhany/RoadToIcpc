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

struct TwoSatSolver {
	int n_vars;
	int n_vertices;
	vector<vector<int>> adj, adj_t;
	vector<bool> used;
	vector<int> order, comp;
	vector<bool> assignment;

	TwoSatSolver(int _n_vars) : n_vars(_n_vars), n_vertices(2 * n_vars), adj(n_vertices), adj_t(n_vertices), used(n_vertices), order(), comp(n_vertices, -1), assignment(n_vars) {
		order.reserve(n_vertices);
	}
	void dfs1(int v) {
		used[v] = true;
		for (int u : adj[v]) {
			if (!used[u])
				dfs1(u);
		}
		order.push_back(v);
	}

	void dfs2(int v, int cl) {
		comp[v] = cl;
		for (int u : adj_t[v]) {
			if (comp[u] == -1)
				dfs2(u, cl);
		}
	}

	bool solve_2SAT() {
		order.clear();
		used.assign(n_vertices, false);
		for (int i = 0; i < n_vertices; ++i) {
			if (!used[i])
				dfs1(i);
		}

		comp.assign(n_vertices, -1);
		for (int i = 0, j = 0; i < n_vertices; ++i) {
			int v = order[n_vertices - i - 1];
			if (comp[v] == -1)
				dfs2(v, j++);
		}

		assignment.assign(n_vars, false);
		for (int i = 0; i < n_vertices; i += 2) {
			if (comp[i] == comp[i + 1])
				return false;
			assignment[i / 2] = comp[i] > comp[i + 1];
		}
		return true;
	}

	void add_disjunction(int a, bool na, int b, bool nb) {
		// na and nb signify whether a and b are to be negated 
		a = 2 * a ^ na;
		b = 2 * b ^ nb;
		int neg_a = a ^ 1;
		int neg_b = b ^ 1;
		adj[neg_a].push_back(b);
		adj[neg_b].push_back(a);
		adj_t[b].push_back(neg_a);
		adj_t[a].push_back(neg_b);
	}
};

void solve(int tc) {
	ll n, m;

	cin >> n >> m;

	vi X(n);
	for (int i = 0; i < n; i++) cin >> X[i];
	
	vii Y(n);
	for (int i = 0; i < m; i++)
	{
		ll k; cin >> k;
		for (int j = 0; j < k; j++)
		{
			ll a; cin >> a; a--;
			Y[a].push_back(i);
		}
	}
	
	
	TwoSatSolver sat(m*2+10);
	for (int i = 0; i < n; i++)
	{
		if (X[i]) {
			// i^n+j = 0 
			sat.add_disjunction(Y[i][0], true, Y[i][1], false);
			sat.add_disjunction(Y[i][0], false, Y[i][1], true);
		} else {
			// i^n+j = 1 			
			sat.add_disjunction(Y[i][0], false, Y[i][1], false);
			sat.add_disjunction(Y[i][0], true, Y[i][1], true);
		}
	}
	
	if (sat.solve_2SAT()) YES;
	NO;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int size = 1;
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	// cin >> size;
	for (int i = 1; i <= size; i++)
		solve(i);
}

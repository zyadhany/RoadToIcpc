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

	struct Dinic {
	// from x to y with residual capacity
	struct edge {
		ll x, y, w;
	};

	vector<vector<ll>> gr;
	vector<edge> edges;
	vector<ll> level;
	vector<ll> edge_sz;

	ll n, source, sink, ec = 0;
	Dinic(ll n, ll source, ll sink) {
		this->n = n;
		this->source = source;
		this->sink = sink;
		gr.resize(n);
		edge_sz.resize(n);
	}

	void add_edge(ll x, ll y, ll w) {				// All I need to do is add edges in here
		edges.push_back({x, y, w});						// X ---> Y, of weight W
		gr[x].push_back(ec++);
		edges.push_back({y, x, 0});
		gr[y].push_back(ec++);
	}

	bool level_graph() {
		level.clear(); level.resize(n, -1);

		queue<ll> Q;
		Q.push(source);
		level[source] = 0;

		while (!Q.empty()) {
			ll cur = Q.front();
			Q.pop();

			for (auto xx : gr[cur]) {
				ll to = edges[xx].y;
				ll w = edges[xx].w;

				if (w && level[to] == -1) {
					level[to] = level[cur] + 1;
					Q.push(to);
				}

			}
		}

		return level[sink] != -1;
	}



	ll augment(ll cur, ll flow) {
		if (cur == sink) {
			return flow;
		}

		for (ll &i = edge_sz[cur]; i >= 0; i--) {
			ll edge_index = gr[cur][i];
			ll w = edges[edge_index].w;
			ll y = edges[edge_index].y;

			if (w && level[y] == level[cur] + 1) {
				ll bottleneck_flow = augment(y, min(w, flow));

				if (bottleneck_flow) {
					// forward edge according to current augmented path
					edges[edge_index].w -= bottleneck_flow;
					// backward edge
					edges[edge_index ^ 1].w += bottleneck_flow;

					return bottleneck_flow;
				}

			}
		}
		return 0;
	}

	ll max_flow() {
		ll total_flow = 0;

		while (level_graph()) {
			// find augmenting paths and update in residual network
			for (ll i = 0; i < n; i++) edge_sz[i] = gr[i].size() - 1;
			while (ll flow = augment(source, 1e18)) {
				total_flow += flow;
			}
		}
		return total_flow;
	}

	bool func(ll curr, vi&path)
	{
		path.push_back(curr);
		if (curr == sink)
			return true;

		for (ll &i = edge_sz[curr]; i >= 0; i--)
		{
			ll edge_index = gr[curr][i];
			if (edge_index & 1)             //consider only even index edges for finding actual paths as the index + 1 are back_edges(directed graph)
				continue;
			if (edges[edge_index].w == 0)
			{
				func(edges[edge_index].y, path);
				i--;
				return true;
			}
		}
		return false;
	}

	vii get_paths() {
		vii ans;
		for (ll i = 0; i < n; i++) edge_sz[i] = gr[i].size() - 1;
		vi path;
		while (func(source, path))
		{
			ans.push_back(path);
			path.clear();
		}
		return ans;
	}

};


void solve(int tc) {
    ll n, m;
	cin >> n >> m;

	Dinic di(n+1, 1, n);
	for (int i = 0; i < m; i++)
	{
		ll u, v; cin >> u >> v;
		di.add_edge(u, v, 1);
	}
	
	di.max_flow();
	auto res = di.get_paths();
	cout << res.size() << '\n';
	for (auto &Z : res) {
		cout << Z.size() << '\n';
		for (auto a : Z) cout << a << ' ';
		cout << '\n';
	}
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

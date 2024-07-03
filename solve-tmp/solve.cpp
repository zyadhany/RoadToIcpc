#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>

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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}

const int MODE = 998244353;

using namespace std;


class Graph {
public:
    int size;
    vi vis;
    vector<vector<pl>> adj;

    void addEdge(int u, pl v) {
        adj[u].push_back(v);
    }

	vi dijkstra(ll v) {
		vi Z(size + 1, INT64_MAX);

		priority_queue<pl, vp, greater<pl>> L;
		L.push({0, v});
		Z[v] = 0;

		while (!L.empty())
		{
			auto k = L.top();
			L.pop();
			if (k.first > Z[k.second]) continue;

			for (auto neg : adj[k.second]) {
				ll cost = neg.second + k.first;
				if (Z[neg.first] <= cost) continue;
				Z[neg.first] = cost;
				L.push({cost, neg.first});
			}
		}

		return (Z);
	}

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

void getRan(vii &Y, vii &dist, ll n, ll l, ll r, ll val) {
    if (n == -1) {
        Y.push_back({l, r, val});
        return;
    }

    ll a, b;
    a = dist[n][1];
    b = dist[n][2];
    if (l >= a && r <= b) return;
    if (r > b) getRan(Y, dist, n - 1, max(b + 1, l), r, val);
    if (l < a) getRan(Y, dist, n - 1, l, min(a - 1, r), val);
}

void solve(int tc) {
    ll n, m, k, t;
    cin >> n >> m >> k >> t;

    vi X(n + 1);
    vii EX(k, vi(3));
    vi res(t + 10);
    vi abb(t + 10);
    Graph gr(n);
    

    for (int i = 1; i <= n; i++)
        cin >> X[i];
    
    for (int i = 0; i < k; i++)
        for (int j = 0; j < 3; j++)
            cin >> EX[i][j];

    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        gr.addEdge(u, {v, w});
        gr.addEdge(v, {u, w});        
    }
        
    vii Z(k);
    for (int i = 0; i < k; i++)
        Z[i] = gr.dijkstra(EX[i][0]);

    for (int i = 1; i <= n; i++)
    {
        vii dist(k, vi(3));
        for (int j = 0; j < k; j++)
        {
            dist[j] = EX[j];
            dist[j][0] = Z[j][i] * X[i];
        }
        sortx(dist);
        vii cor;
        for (int j = 0; j < k; j++)
            getRan(cor, dist, j - 1, dist[j][1], dist[j][2], dist[j][0]);
        
        for (auto &M : cor) {
            res[M[0]] += M[2];
            res[M[1] + 1] -= M[2];
            abb[M[0]] += 1;
            abb[M[1] + 1] -= 1;
        }
    }

    for (int i = 1; i <= t; i++)
        res[i] += res[i - 1], abb[i] += abb[i - 1];

    for (int i = 1; i <= t; i++)
        if (abb[i]) cout << res[i] << '\n';    
        else cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;
    //freopen("mex.in", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}

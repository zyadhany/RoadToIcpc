#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
 
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
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
 
const int MODE = 1e9 + 7;
 
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


void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    Graph gr(n);

    for (int i = 0; i < m; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        gr.addEdge(l, {r, k});
    }
    
    auto X = gr.dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << X[i] << ' ';
    cout << '\n';
}
 
int main()
{
		ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
		int size = 1;
 
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
 
		//cin >> size;
		for (int i = 1; i <= size; i++)
				solve(i);
}
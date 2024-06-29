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

	ll dijkstra() {
		vii Z(size + 1, vi(2, INT64_MAX));

		priority_queue<pair<ll, pl>, vector<pair<ll, pl>>, greater<pair<ll, pl>>> L;
		L.push({0, {1, 0}});
		Z[1][0] = 0;

		while (!L.empty())
		{
			auto k = L.top().first;
			auto pos = L.top().second;

			L.pop();
			if (k > Z[pos.first][pos.second]) continue;

			for (auto neg : adj[pos.first]) {
				ll cost1 = neg.second + k;
				ll cost2 = neg.second / 2 + k;

				if (pos.second) {
					if (Z[neg.first][1] > cost1) {
						Z[neg.first][1] = cost1;
						L.push({cost1, {neg.first, 1}});
					}
				}else
				{
					if (Z[neg.first][0] > cost1) {
						Z[neg.first][0] = cost1;
						L.push({cost1, {neg.first, 0}});
					}
					if (Z[neg.first][1] > cost2) {
						Z[neg.first][1] = cost2;
						L.push({cost2, {neg.first, 1}});
					}
				}
			}
		}

		return (Z[size][1]);
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
        gr.addEdge(l, {r, k});
    }
	
	cout << gr.dijkstra() << '\n';
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

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

#define INF 1e16

class Graph {
public:
	struct edge {
		int u, v, w;
	};
    
	int size;
	vector<edge> E;
	
    void addEdge(int u, int v, int w) {
        edge ed = {u, v, w};
		E.push_back(ed);
    }

	ll BellmanFord(int src) {
		vi Z(size + 1, INF);
		Z[src] = 0;

		// itrate n - 1 to get shortest path.
		for (int i = 1; i <= size - 1; i++)
		{
			for (int j = 0; j < E.size(); j++)
			{
				ll u = E[j].u, v = E[j].v, w = E[j].w;
				if (Z[u] + w < Z[v] && Z[u] != INF) Z[v] = Z[u] + w;
			}
		}
		
		// itrate last time to ensure negrive syclic
		for (int i = 1; i <= size; i++) {
			for (int j = 0; j < E.size(); j++)
			{
				ll u = E[j].u, v = E[j].v, w = E[j].w;
				if (Z[u] + w < Z[v] && Z[u] != INF) Z[v] = -INF;
			}
		}
	
		if (Z[size] == -INF) return (-1); 
		return -Z[size];
	}

    Graph(ll n) {
        size = n;
    }
};


void solve(int tc) {
    ll n, m, q;

    cin >> n >> m;

    Graph gr(n);

    for (int i = 0; i < m; i++)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        gr.addEdge(l, r, -k);
    }
	
	cout << gr.BellmanFord(1) << '\n';
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

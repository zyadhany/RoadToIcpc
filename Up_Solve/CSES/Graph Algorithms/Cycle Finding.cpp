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
#define YES {cout << "Alice\n"; return;}
#define NO {cout << "Bob\n"; return;}
#define MUN {cout << "-1\n"; return;}

const int MODE = 1e9 + 7;

using namespace std;

const ll INF = 1e16;

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

    // find the negative cycle
	vi BelmenNegativeCycle() {
        vi Z(size + 1, INF);
        vi P(size + 1, -1);
        
        ll ls = -1;
        for (int i = 1; i <= size; i++)
		{
            ls = -1;
			for (int j = 0; j < E.size(); j++)
			{
				ll u = E[j].u, v = E[j].v, w = E[j].w;
				if (Z[u] + w < Z[v]) {
                    Z[v] = Z[u] + w;
                    P[v] = u;
                    ls = v;
                }
			}
		}

        vi res;
        if (ls == -1) return {};
        for (int i = 0; i < size-1; i++) ls = P[ls];        
        for (int x = ls;; x = P[x]) {
			res.push_back(x);
			if (x == ls && res.size() > 1) break;
		}
        reverse(all(res));
		return res;
	}

    Graph(ll n) {
        size = n;
    }
};

void solve(int tc) {
    ll n, m;
    cin >> n >> m;
    Graph gr(n);

    for (int i = 0; i < m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;
        gr.addEdge(u, v, w);
    }
    auto d = gr.BelmenNegativeCycle();

    if (d.empty()) cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto a : d) cout << a << ' ';
        cout << '\n';
    }
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

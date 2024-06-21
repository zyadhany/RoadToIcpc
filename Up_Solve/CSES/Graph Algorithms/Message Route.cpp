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
    vii adj;

    vi BFSgetRoad(int s, int e)
    {
        queue<int> que;
        vi prev(size + 1, -1);
        vi res;
        que.push(s);
        vis[s] = 1;

        while (!que.empty())
        {
            int m = que.front();
            que.pop();
            
            for (auto a : adj[m]) {
                if (!vis[a]) {
                    vis[a] = 1;
                    que.push(a);
                    prev[a] = m;
                }
            }
        }

        if (prev[e] != -1) res.push_back(e);
        while (prev[e] != -1)
        {
            res.push_back(prev[e]);
            e = prev[e];
        }

        reverse(all(res));
        return (res);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
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
        ll a, b;
        cin >> a >> b;
        gr.addEdge(a, b);
        gr.addEdge(b, a);
    }
    
    auto X =gr.BFSgetRoad(1, n);
    if (X.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << X.size() << '\n';
    for (int i = 0; i < X.size(); i++)
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

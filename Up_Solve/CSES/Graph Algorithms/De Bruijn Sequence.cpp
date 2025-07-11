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

class Graph {
public:
    int size, EIN, EOUT;
	vi indegree; 
	vii adj;

	bool isConnected()
	{
		ll n, summ, src, in;
		vi visited(size + 1);
		stack<int> stack;
		
		n = summ = 0, src = in = -1;

		for (int i = 0; i < adj.size(); i++) {
			if (!adj[i].empty() || indegree[i]) n++, src = i;
			int re = adj[i].size() - indegree[i];
			if (max(re, 0) % 2)	in = i;
		}
		if (in != -1) src = in;
		if (src != -1) stack.push(src);
		while (!stack.empty())
		{
			int m = stack.top();
			stack.pop();
			if (visited[m]) continue;
			visited[m] = 1, summ++;
			for (auto a : adj[m])
				if (!visited[a]) stack.push(a);
		}	
		return (summ == n);
	}
	
	/* The function returns one of the following values
	0 --> If graph is not Eulerian
	1 --> If graph has an Euler path (Semi-Eulerian)
	2 --> If graph has an Euler Circuit (Eulerian)  */
	int isEulerian()
	{
		if (!isConnected()) return 0;
		int l = 0, r = 0;
		for (int i = 0; i <= size; i++) {
			int a = adj[i].size() - indegree[i];
			if (!a) continue;
			if (abs(a) >= 2) return (0);
			if (a == 1) EIN = i, r++;
			if (a == -1) EOUT = i, l++;
		}
		if (l >= 2 || r >= 2 || (l ^ r)) return (0);
		return (l)? 1 : 2;
	}

	vi EulerPath(ll l) {
		vi X;

		stack<ll> st;
		st.push(l);
		vector<deque<ll>> Y(size + 1);

		for (int i = 0; i <= size; i++)
			for (int j = 0; j < adj[i].size(); j++)
				Y[i].push_back(adj[i][j]);
		while (!st.empty())
		{
			ll m = st.top();
			bool isit = 1;

			if (!Y[m].empty()) {
				st.push(Y[m].front());
				Y[m].pop_front();
				isit = 0;
			}

			if (isit) {
				X.push_back(m);
				st.pop();
			}
		}
		
		reverse(all(X));
		return (X);
	}

    void addEdge(int u, int v) {
		adj[u].push_back(v);
		indegree[v]++;
	}
	
    Graph(ll n) {
		EIN = EOUT = -1;
		size = n;
        adj.resize(n + 1);
        indegree.resize(n + 1);
    }
};


void solve(int tc) {
	ll n;

	cin >> n;
	if (n == 1) {
		cout << "01\n";
		return;
	}
	n--;
	Graph gr(1<<n);
	for (int i = 0; i < (1<<n); i++)
	{
		ll re = ((i & ((1<<(n-1))-1)) << 1);
		gr.addEdge(i, re);
		gr.addEdge(i, re|1);		
	}
	auto Z = gr.EulerPath(0);
	for (int i = 0; i < n-1; i++) cout << "0";
	for (auto a : Z) cout << (a&1);
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

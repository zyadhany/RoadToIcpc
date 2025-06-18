/*
eulerian circuit: that path start and end at the same vertex and visits every edge exactly once.
eulerian path: that path may start and end at different vertices and visits every edge exactly once.

in an undirected graph:
- an eulerian circuit exists if and only if every vertex has even degree and the graph is connected.
- an eulerian path if it's eulerian circuit or if it has exactly two vertices with odd degree and the graph is connected.

in directed graph:
- an eulerian circuit exists if and only if every vertex has equal in-degree and out-degree and the graph is strongly connected.
- an eulerian path exists if it has exactly one vertex with (out-degree - in-degree) = 1, exactly one vertex with (in-degree - out-degree) = 1, and all other vertices have equal indegree and out-degree.

*/
class Graph {
public:
    int size;
	vp Edge;
	vii adj;
	bool isConnected()
	{
		ll summ = 0, n = 0, src = -1;
		vi visited(size + 1);
		stack<int> stack;
		
		for (int i = 0; i < adj.size(); i++)
			if (!adj[i].empty()) n++, src = i;
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
		int odd = 0;
		for (int i = 0; i <= size; i++)
			odd += (adj[i].size() & 1); 
		if (odd > 2) return 0;
		return (odd)? 1 : 2;
	}

	vi EulerPath(ll src) {
		vi X;

		stack<ll> st;
		st.push(src);
		vector<deque<pl>> Y(size + 1);
		vi visted(Edge.size());

		for (int i = 0; i < Edge.size(); i++)
		{
			int u = Edge[i].first, v = Edge[i].second;
			Y[u].push_back({v, i});
			Y[v].push_back({u, i});			
		}

		while (!st.empty())
		{
			ll m = st.top();
			bool isit = 1;

			while (!Y[m].empty()) {
				pl at = Y[m].front();
				Y[m].pop_front();
				if (visted[at.second]) continue;
				visted[at.second] = 1;
				st.push(at.first);
				isit = 0;
				break;
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
        adj[v].push_back(u);
		Edge.push_back({u, v});
	}

    Graph(ll n) {
        size = n;
        adj.resize(n + 1);
    }
};

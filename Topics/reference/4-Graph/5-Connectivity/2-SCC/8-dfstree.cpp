/*
    dfs tree convert graph to tree so it's easier to process, here is some oppservation:
    1- dfs tree has span edges and back edges, back edges are edges that connect a node to one of its ancestors in the dfs tree.
    2- span edges is bridge edges, if there is no back edges that go trough it.
    3- each back edge form simple a cycle with span edges that path through, (there is other simple cycles). 

    4-if it's directed graph, we can loop through all nodes and make vis = {1, 2}: 1 is proccesed, 2 is still in the stack (cycle). keep going with same technique as previous.
*/

struct Graph {
	vpp adj;
	int timer = 0;
	vi up, in;
	vii scc;
	stack<ll> st;

	void dfs(ll n, ll p=0, ll id=-1) {
		in[n] = up[n] = ++timer;
		
		st.push(n);
		for (auto [neg, idx] : adj[n]) if (idx != id) {
			if (!up[neg]) {
				dfs(neg, n, idx);
				up[n] = min(up[n], up[neg]);
			} else up[n] = min(up[n], in[neg]);
		} 
		
		if (up[n] == in[n]) {
			scc.push_back({});
			while (st.top() != n) scc.back().push_back(st.top()), st.pop();
			scc.back().push_back(st.top()), st.pop();
		}
	}

	Graph(ll n, vpp &adj) : adj(adj), up(n+1), in(n+1) {
		for (int i = 1; i <= n; i++)
			if (!up[i]) dfs(i);
	}
};

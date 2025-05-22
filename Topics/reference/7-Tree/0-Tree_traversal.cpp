// travell all node from root to leaf.
// at first node: dfs(1, 0).
void dfs(int n, int p) {
    for (auto neg : adj[n]) {
        if (neg != p) dfs(neg, n);
    }
}

// euler tour of tree.
// each element from [Indeg[n], Outdeg[n]] is a subtree of node n
void dfs(vii &adj, vi &Indeg, vi &Outdeg, int n, int p) {
    Indeg[n] = Timer++;
    for (auto neg : adj[n])
        if (neg != p) dfs(adj, Indeg, Outdeg, neg, n);
    Outdeg[n] = Timer - 1;
}

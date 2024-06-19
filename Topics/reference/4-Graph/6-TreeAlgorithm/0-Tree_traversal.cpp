// travell all node from root to leaf.
// at first node: dfs(1, 0).
void dfs(int n, int p) {
    for (auto neg : adj[n]) {
        if (neg != p) dfs(neg, n);
    }
}

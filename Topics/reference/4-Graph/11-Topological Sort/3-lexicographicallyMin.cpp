/**
 * We can use pq instead of queue to get lexicographically smallest topological sort
 */
vi TopologicalSort() {
    vi X, vis(n + 1);
    vi indeg(n + 1);
    
    for (int i = 1; i <= n; i++)
        for (auto neg : adj[i]) indeg[neg]++;
    
    priority_queue<ll, vi, greater<>> q;
    for (int i = 1; i <= n; i++) if (!indeg[i]) q.push(i);

    while (!q.empty())
    {
        ll tp = q.top();
        q.pop();
        X.push_back(tp);
        for (auto neg : adj[tp]) {
            indeg[neg]--;
            if (!indeg[neg]) q.push(neg);
        }
    }

    if (X.size() != n) return vi();
    return (X);
}

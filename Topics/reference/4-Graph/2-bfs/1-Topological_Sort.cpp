
vi TopologicalSort() {
    vi X, Z(size + 1);
    queue<ll> que;

    for (int i = 1; i <= size; i++)
        for (auto neg : adj[i]) Z[neg]++;
    for (int i = 1; i <= size; i++)
        if (!Z[i]) que.push(i);

    while (!que.empty())
    {   
        int m = que.front();
        que.pop();
        X.push_back(m);
        for (auto neg : adj[m]) {
            Z[neg]--;
            if (!Z[neg]) que.push(neg);
        }
    }

    return (X);
}

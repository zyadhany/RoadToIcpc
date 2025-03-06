
/*
    Count indegree of each node and push nodes with indegree 0 into queue.
    Then, pop the front of the queue and push it into the answer vector.
    For each node that is connected to the popped node, decrease its indegree by 1.
    If the indegree of the connected node becomes 0, push it into the queue.
    Repeat until the queue is empty.
*/
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

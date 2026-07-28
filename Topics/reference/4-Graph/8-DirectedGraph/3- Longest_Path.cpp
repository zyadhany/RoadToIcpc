// Longest Path in a Directed Acyclic Graph (DAG)
// O(V.K + E) Where V is the number of vertices, E is the number of edges, and K is the number of longest paths to find.
ll kth_longest_path_dag(int n, ll k, const vector<vector<pair<ll, ll>>>& adj) {
    vector<int> in_degree(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto& edge : adj[u]) {
            in_degree[edge.first]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto& edge : adj[u]) {
            int v = edge.first;
            if (--in_degree[v] == 0) q.push(v);
        }
    }

    vector<vector<ll>> dp(n);
    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        priority_queue<array<ll, 3>> pq;

        for (int j = 0; j < (int)adj[u].size(); j++) {
            int v = adj[u][j].first;
            ll w = adj[u][j].second;
            if (!dp[v].empty()) {
                pq.push({w + dp[v][0], j, 0});
            }
        }
        pq.push({0LL, -1, 0});

        while (!pq.empty() && (ll)dp[u].size() < k) {
            auto top = pq.top();
            pq.pop();
            ll val = top[0];
            int j = top[1];
            int idx = top[2];

            dp[u].push_back(val);

            if (j != -1 && idx + 1 < (int)dp[adj[u][j].first].size()) {
                int v = adj[u][j].first;
                ll w = adj[u][j].second;
                pq.push({w + dp[v][idx + 1], j, idx + 1});
            }
        }
    }

    vector<ll> all_paths;
    for (int u = 0; u < n; u++) {
        for (ll val : dp[u]) {
            all_paths.push_back(val);
        }
    }

    sort(all_paths.rbegin(), all_paths.rend());
    if (k - 1 < (ll)all_paths.size()) return all_paths[k - 1];
    return -1;
}
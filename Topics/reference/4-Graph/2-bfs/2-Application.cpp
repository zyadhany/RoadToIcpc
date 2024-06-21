class Graph {
public:
    int size;
    vi vis;
    vii adj;
 
    // find shortest road between s, e.
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

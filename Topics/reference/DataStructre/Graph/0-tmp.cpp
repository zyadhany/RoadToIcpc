class Graph {
public:
    vi visited;
    vii adj;

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void DFS(int s)
    {
        stack<int> stack;

        stack.push(s);

        while (!stack.empty())
        {
            int m = stack.top();
            stack.pop();

            visited[m] = 1;
            
            for (auto a : adj[m]) {
                if (!visited[a]) {
                    stack.push(a);
                }
            }
        }
    }

    Graph(ll n) {
        visited.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

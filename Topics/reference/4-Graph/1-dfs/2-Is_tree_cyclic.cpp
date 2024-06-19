/**
 * for undirected graph
*/

class Graph {
public:
    int size;
    vi vis;
    vii adj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool isCyclicUtil(vector<bool> &visited, int v)
    {
        int m, p;
        stack<pair<int, int>> st;
        st.push({v, -1});

        while (!st.empty())
        {
            m = st.top().first;
            p = st.top().second;
            visited[m] = 1;
            st.pop();

            for (auto a : adj[m]) {
                if (a == p) continue;
                if (visited[a]) return (true);
                st.push({a, m}); 
            }
        }
        
        return (false);
    }
    
    bool isTree()
    {
        vector<bool> visited(size + 1, 0);
        if (isCyclicUtil(visited, 1)) return false; 
        for (int u = 1; u <= size; u++)
            if (!visited[u]) return false;
        return true;
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};


// Cyclic for directed graph

bool isCyclicUtil(vector<bool> &visited, vector<bool> &recStack, int n, int p)
{
    if (visited[n]) return false;
    visited[n] = recStack[n] = true;
    for (auto neg : adj[n]) {
        if (neg == p) continue;
        if (recStack[neg]) return (true);
        if (isCyclicUtil(visited, recStack, neg, n)) return true;
    }
    return (recStack[n] = false);
}

bool isCyclic()
{
    vector<bool> visited(size + 1), recStack(size + 1);
    for (int i = 1; i <= size; i++)
        if (!visited[i]) if(isCyclicUtil(visited, recStack, i, -1))
            return true;
    return false;
}

/**
 * Kosaraju’s algorithm: it about 2 dfs search.
 * 1: get order of node of it's outdegree.
 * 2: reverse order and all edge then start dfs
      and each node to reach is connected component.
 */
class Graph {
public:
    int size;
    vi vis;
    vii adj, radj;

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    void dfs(vii &adjlist, vi &visited, vi &X, ll n) {
        if (visited[n]) return;
        visited[n] = 1;
        for (auto neg : adjlist[n]) dfs(adjlist, visited, X, neg);
        X.push_back(n);
    }

    vii stronglyConnectedComponents () {
        vii res;
        vi nodeOrder, visited(size + 1);
        for (int i = 1; i <= size; i++) dfs(adj, visited, nodeOrder, i);
        
        visited.assign(size + 1, 0);
        for (int i = nodeOrder.size() - 1; i >= 0; i--)
        {
            int ind = nodeOrder[i];
            if (visited[ind]) continue;
            vi Y;
            dfs(radj, visited, Y, ind);
            res.push_back(Y);
        }
        
        return (res);
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
        radj.resize(n + 1);
    }
};

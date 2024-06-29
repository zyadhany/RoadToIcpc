/**
 * we make traverse array as we have
  indegree and size and value of edge
 * to get value of subtree we take 
  we make marge of lange of it's size
 * we can make query of update using segment tree.
 */

/**
 * we can make path query if we storepath from root to node
 * each node store summ of path from root to it
 * if increase value of node by 5 we increase all values
 * of it subtree by 5.
 */
class Graph {
public:
    int size;
    vi vis;
    vii adj;

    vi Travese, Indeg, SubSize, Val;

    ll dfs(int n, int p) {
        ll summ = 1;
        Indeg[n] = Travese.size();
        Travese.push_back(n);
        SubSize.push_back(0);
        for (auto neg : adj[n])
            if (neg != p) summ += dfs(neg, n);
        return (SubSize[Indeg[n]] = summ);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    Graph(ll n) {
        size = n;
        Val
        Indeg.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

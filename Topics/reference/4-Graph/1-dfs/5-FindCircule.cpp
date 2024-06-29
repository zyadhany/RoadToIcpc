class Graph {
public:
    int size;
    vi vis, colorArr;
    vii adj;
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
 
    vi dfs(vi &Y, ll n, ll p) {
        if (vis[n] == -1) {
            vi X;
            X.push_back(n);
            while (Y.back() != n)
            {
                X.push_back(Y.back());
                Y.pop_back();
            }
            X.push_back(n);
            return (X);
        }
        if (vis[n]) return vi();
        vis[n] = -1;
        Y.push_back(n);
        for (auto neg : adj[n]) {
            if (neg != p) {
                vi X = dfs(Y, neg, n); 
                if (!X.empty()) return (X);
            }
        } 
        Y.pop_back();
        vis[n] = 1;
        return vi();
    }

    vi findCircule() {
        vi X, Y;
        for (int i = 1; i <= size; i++) {
            X = dfs(Y, i, 0);
            if (!X.empty()) return (X);
        }
        return (X);
    }
    
    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        colorArr.assign(size + 1, -1);
        adj.resize(n + 1);
    }
};

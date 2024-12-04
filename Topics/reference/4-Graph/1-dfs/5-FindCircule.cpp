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


// get longest cycle in graph
int longestCycleLength = -1;

// Helper function to perform DFS
void dfs(int node, const vector<vector<int>> &adj, vector<int> &visited, vector<int> &recStack, vector<int> &entryTime, int currentTime) {
    visited[node] = 1;        // Mark as visiting
    recStack[node] = currentTime; // Track entry time
    entryTime[node] = currentTime;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, recStack, entryTime, currentTime + 1);
        } else if (recStack[neighbor] != -1) { // Found a back edge
            longestCycleLength = max(longestCycleLength, currentTime - recStack[neighbor] + 1);
        }
    }

    recStack[node] = -1; // Mark as no longer in the stack
}

// Function to find the longest cycle in a directed graph
int findLongestCycle(int n, const vector<vector<int>> &adj) {
    vector<int> visited(n, 0);
    vector<int> recStack(n, -1); // Tracks entry times for nodes in the recursion stack
    vector<int> entryTime(n, -1);
    longestCycleLength = -1;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, recStack, entryTime, 0);
        }
    }

    return longestCycleLength;
}

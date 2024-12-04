// Global variables
vector<int> disc, low;
vector<bool> visited;
vector<pair<int, int>> bridges;
int timeCounter;

// Helper function to perform DFS and find bridges
void dfs(int u, int parent, const vector<vector<int>> &adj) {
    visited[u] = true;
    disc[u] = low[u] = timeCounter++;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            // Explore the neighbor
            dfs(v, u, adj);
            // Update the low-link value
            low[u] = min(low[u], low[v]);

            // Bridge condition
            if (low[v] > disc[u]) {
                bridges.emplace_back(u, v);
            }
        } else if (v != parent) {
            // Update low value for back edge
            low[u] = min(low[u], disc[v]);
        }
    }
}

// Function to find all bridges in the graph
vector<pair<int, int>> findBridges(int n, const vector<vector<int>> &adj) {
    // Reinitialize global variables
    disc.assign(n, -1);
    low.assign(n, -1);
    visited.assign(n, false);
    bridges.clear();
    timeCounter = 0;

    // Run DFS for every component
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, adj);
        }
    }
    return bridges;
}


/*
Tarjan's Algorithm is incredibly versatile and can be adapted to solve several other graph-related problems efficiently. Here's what else you can do with it:

---

### 1. **Find Articulation Points (Cut Vertices):**
   - **Definition**: An articulation point in a graph is a vertex that, if removed along with its incident edges, increases the number of connected components in the graph.
   - **Modification**:
     - Instead of checking for bridge conditions on edges, check for articulation point conditions on vertices.
     - A node \( u \) is an articulation point if:
       - It is the root of the DFS tree and has at least two children.
       - Or, \( \text{low}[v] \geq \text{disc}[u] \) for a child \( v \) of \( u \), and \( u \) is not the root.

---

### 2. **Find Strongly Connected Components (SCCs):**
   - **Definition**: An SCC is a maximal subgraph where every vertex is reachable from every other vertex in the subgraph.
   - **Modification**:
     - Use Tarjan's Algorithm for SCCs to track a **stack** during DFS. When an SCC is identified, all vertices in the SCC are popped from the stack.
     - This is used in **directed graphs** and has applications in dependency analysis, circuit design, etc.

---

### 3. **Test Biconnected Components:**
   - **Definition**: A biconnected component (BCC) is a maximal subgraph where the removal of any single vertex does not disconnect the component.
   - **Modification**:
     - Use the `low` and `disc` arrays to identify BCCs.
     - BCCs can be used to understand graph robustness and connectivity properties.

---

### 4. **Find Critical Connections in Networks:**
   - **Definition**: A critical connection is an edge that, if removed, increases the number of connected components.
   - **Relation to Bridges**:
     - Bridges in the graph are critical connections. Applications include finding weak links in computer networks, power grids, etc.

---

### 5. **Detect Cycle in Undirected Graphs:**
   - **Modification**:
     - During DFS, if a back edge exists (i.e., an edge connecting a vertex to one of its ancestors that is not its parent), it indicates a cycle.

---

### 6. **Topological Properties in Directed Graphs:**
   - Use a variant of Tarjan’s algorithm to analyze **reachability** in directed acyclic graphs (DAGs), which is useful in job scheduling, dependency resolution, and more.

---

### 7. **Bridge Tree Construction**:
   - **Definition**: A bridge tree is a compressed representation of a graph where all vertices in the same connected component (without any bridge) are treated as a single node.
   - **Use Case**:
     - This is useful in dynamic graph problems or to optimize queries related to graph connectivity.

---

### 8. **Applications in Competitive Programming:**
   - **Dynamic Graph Connectivity**: Find bridges to determine if removing an edge disconnects the graph.
   - **Network Analysis**: Analyze weak points in networks, such as roads, pipelines, or communication links.
   - **Problem Examples**:
     - **Critical Routers**: Identify nodes or edges that would disrupt communication in a network.
     - **Telecom Networks**: Find vulnerabilities in large communication systems.

---

### Summary Table:

| **Problem**                     | **Graph Type**       | **Key Condition**                             |
|----------------------------------|----------------------|-----------------------------------------------|
| **Bridges**                     | Any                  | \( \text{low}[v] > \text{disc}[u] \)           |
| **Articulation Points**         | Any                  | Root with \(\geq 2\) children, or \( \text{low}[v] \geq \text{disc}[u] \) |
| **Strongly Connected Components** | Directed            | Use a stack to identify SCCs                  |
| **Biconnected Components**      | Any                  | Partition graph based on articulation points |
| **Critical Connections**        | Any                  | Same as bridges                               |

Tarjan's Algorithm is foundational for solving these problems due to its elegance and efficiency in **O(V + E)** time complexity.
*/
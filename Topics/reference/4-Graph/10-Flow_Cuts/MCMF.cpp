#include <bits/stdc++.h>
using namespace std;

/*
 * Minimum Cost Maximum Flow (MCMF):
 * - Finds the maximum flow in a flow network while minimizing the total cost.
 * - Each edge has a capacity (max flow it can carry) and a cost (per unit flow).
 * - Combines concepts of max-flow (augmenting paths) and shortest path (minimum cost).
 * - Uses Shortest Path Faster Algorithm (SPFA) to find augmenting paths with the least cost.
 */


// Structure to represent an edge in the graph
struct Edge {
    int to, rev;               // Destination node and index of reverse edge in adjacency list
    long long cap, cost, flow; // Capacity, cost, and current flow of the edge
    Edge(int to, int rev, long long cap, long long cost)
        : to(to), rev(rev), cap(cap), cost(cost), flow(0) {}
};

const long long INF = LLONG_MAX; // Infinity for initialization
vector<vector<Edge>> graph;      // Adjacency list to store the graph
vector<long long> dist;          // Distance array for shortest path calculations
vector<int> parentNode;          // Stores parent node in the path
vector<int> parentEdge;          // Stores the edge index used to reach a node

// Initialize the graph with n nodes
void initGraph(int n) {
    graph.assign(n, vector<Edge>()); // Clear and resize the graph
    dist.assign(n, INF);            // Reset distance array
    parentNode.assign(n, -1);       // Reset parent node array
    parentEdge.assign(n, -1);       // Reset parent edge array
}

// Add an edge to the graph
void addEdge(int u, int v, long long cap, long long cost) {
    graph[u].emplace_back(v, graph[v].size(), cap, cost); // Forward edge
    graph[v].emplace_back(u, graph[u].size() - 1, 0, -cost); // Reverse edge
}

// SPFA (Shortest Path Faster Algorithm) to find shortest path from source to sink
bool spfa(int source, int sink, int n) {
    queue<int> q;                    // Queue for BFS
    vector<bool> inQueue(n, false);  // Keeps track of nodes in the queue

    dist.assign(n, INF);             // Reset distances
    parentNode.assign(n, -1);        // Reset parent nodes
    parentEdge.assign(n, -1);        // Reset parent edges

    dist[source] = 0;                // Distance to source is 0
    q.push(source);                  // Start from the source
    inQueue[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        // Relax edges
        for (int i = 0; i < graph[u].size(); i++) {
            Edge &e = graph[u][i];
            if (e.flow < e.cap && dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost; // Update distance
                parentNode[e.to] = u;         // Update parent node
                parentEdge[e.to] = i;         // Update parent edge

                // Add node to queue if not already in it
                if (!inQueue[e.to]) {
                    q.push(e.to);
                    inQueue[e.to] = true;
                }
            }
        }
    }

    // Return true if there is a path to the sink
    return dist[sink] != INF;
}

// Function to calculate Maximum Flow and Minimum Cost
pair<long long, long long> MCMF(int source, int sink, int n) {
    long long maxFlow = 0, minCost = 0; // Initialize flow and cost

    while (spfa(source, sink, n)) { // While a path exists
        // Find the maximum flow we can push through this path
        long long pathFlow = INF;
        for (int v = sink; v != source; v = parentNode[v]) {
            int u = parentNode[v];
            int edgeIdx = parentEdge[v];
            pathFlow = min(pathFlow, graph[u][edgeIdx].cap - graph[u][edgeIdx].flow);
        }

        // Augment the flow along the path and calculate the cost
        for (int v = sink; v != source; v = parentNode[v]) {
            int u = parentNode[v];
            int edgeIdx = parentEdge[v];

            graph[u][edgeIdx].flow += pathFlow;            // Update forward edge flow
            graph[v][graph[u][edgeIdx].rev].flow -= pathFlow; // Update reverse edge flow
            minCost += pathFlow * graph[u][edgeIdx].cost;  // Add cost for the flow
        }

        maxFlow += pathFlow; // Add to the total flow
    }

    return {maxFlow, minCost}; // Return maximum flow and minimum cost
}

int main() {
    int nodes = 5; // Number of nodes in the graph
    initGraph(nodes);

    int source = 0, sink = 4; // Define source and sink nodes

    // Add edges: addEdge(u, v, capacity, cost)
    addEdge(0, 1, 5, 2);
    addEdge(1, 2, 3, 3);
    addEdge(2, 4, 4, 1);
    addEdge(0, 3, 2, 4);
    addEdge(3, 4, 3, 2);

    // Find Maximum Flow and Minimum Cost
    auto [maxFlow, minCost] = MCMF(source, sink, nodes);
    cout << "Maximum Flow: " << maxFlow << endl;
    cout << "Minimum Cost: " << minCost << endl;

    return 0;
}

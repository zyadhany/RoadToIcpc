/**
 * We can use topological sort in dp problems in DAG(Directed Acyclic Graph).
 * in topological sort, we know which node should be processed first.
 */

// example usetopological sort in dp to get the longest path in a DAG

// Compute the dist array in topological order
vector<int> parent(city_num, -1);
vector<int> dist(city_num, INT32_MIN);
dist[0] = 1;
for (int i = 0; i < top_sort.size(); i++) {
    int b = top_sort[i];
    for (int prev : back_edge[b]) {
        if (dist[prev] + 1 > dist[b]) {
            dist[b] = dist[prev] + 1;
            parent[b] = prev;
        }
    }
}

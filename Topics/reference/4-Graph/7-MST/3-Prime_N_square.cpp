// Time Complexity: O(N^2)

/**
 * Prim's Algorithm for dense graph to build the MST by scanning
 * @return the edge lengths in the MST
 */
vector<ll> prim(int N) {
	vector<ll> dist(N, MOD);
	vector<bool> visited(N, false);

	for (int i = 0; i < N; i++) {
		// find the nearest node to the current MST
		int min_dist_node = -1;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && (min_dist_node < 0 || dist[j] < dist[min_dist_node])) {
				min_dist_node = j;
			}
		}

		// add this node to the MST
		visited[min_dist_node] = true;

		// update the distances between the MST and other unconnected nodes
		for (int j = 0; j < N; j++) {
			if (!visited[j]) {
				dist[j] = min(
				    dist[j], calc_length(min(min_dist_node, j), max(min_dist_node, j)));
			}
		}
	}
	return dist;
}

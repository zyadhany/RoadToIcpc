/**
 * get shortest path for all pairs i, j
 * works in directed / undirected / postive / negtive adges.
 * doesn't work in negtive loop edge. 
 * it contains negative cycle if dist[i][i] < 0
 * Time O(n^3)
 * Space O(n^2)
*/
void floydWarshall(vii &dist)
{
    for (int k = 1; k < dist.size(); k++)
        for (int i = 1; i < dist.size(); i++)
            for (int j = 1; j < dist.size(); j++) 
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
}

// if there is negative edge, it better to implement this way
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
        }
    }
}

// to build from Graph object.
vii floydBuild(){
    vii dist(size + 1, vi(size + 1, INT32_MAX));
    for (int i = 1; i <= size; i++) {
        dist[i][i] = 0;
        for (auto neg : adj[i])
            dist[i][neg.first] = min(dist[i][neg.first], neg.second);
    }
    floydWarshall(dist);
    return (dist);
}



// When using real weights in the Floyd-Warshall algorithm, floating-point errors can accumulate exponentially. The error may double in each iteration (δ, 2δ, 4δ, ...). To mitigate this, an epsilon (EPS = δ) is introduced in comparisons:
if (d[i][k] + d[k][j] < d[i][j] - EPS)
    d[i][j] = d[i][k] + d[k][j];

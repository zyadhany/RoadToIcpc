/**
 * get shortest path for all pairs i, j
 * works in directed / undirected / postive / negtive adges.
 * doesn't work in negtive loop edge. 
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

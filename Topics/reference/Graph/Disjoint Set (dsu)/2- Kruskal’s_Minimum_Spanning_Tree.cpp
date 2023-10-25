/**
 * -Sort all the edges in non-decreasing order of their weight. 
 * 
 * -Pick the smallest edge.
 * Check if it forms a cycle with the spanning tree formed so far.
 * If the cycle is not formed, include this edge. Else, discard it. 
 * 
 * -Repeat step#2 until there are (V-1) edges in the spanning tree.
*/

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    int a, b, summ = 0;
    vector<vector<int>> X;

    //take all edges in array.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            X.push_back(adj[i][j]);
            reverse(X.back().begin(), X.back().end());
            X.back().push_back(i);
        }
    }

    sort(X.begin(), X.end());

    DSU ds;
    ds.build(V);

    for (int i = 0; i < X.size(); i++)
    {
        a = ds.get(X[i][1]);
        b = ds.get(X[i][2]);

        if (a != b)
        {
            ds.add(a, b);
            summ += X[i][0];
        }
    }

    return (summ);
}
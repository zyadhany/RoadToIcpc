/**
 * Bipartite Graph: to make to set of grap U, V.
 * element of a set not connected with each other.
 * you can only connect u to v from set to onther not same set.
 * 
 * we can use dfs/bfs and color nodes 1,0.
 * every 2 connected nodes be with differenet colors.
 * you can't achive that so it's not Bipartite.
 * Time O(n + m).
*/

class Graph {
public:
    int size;
    vi vis, colorArr;
    vii adj;
 
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool isBipartite(int src)
    {   
        int m;
        stack<int> st;
        st.push(src);
        
        if (colorArr[src] != -1) return(true);
        colorArr[src] = 0;

        while (!st.empty())
        {
            m = st.top();
            st.pop(); 
    
            for (auto neg : adj[m])
            {
                if (colorArr[neg] == colorArr[m]) return (false);
                if (colorArr[neg] == -1)
                {
                    colorArr[neg] = (1 ^ colorArr[m]);
                    st.push(neg);
                }
            }
        }

        return (true);
    }
    
    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        colorArr.assign(size + 1, -1);
        adj.resize(n + 1);
    }
};

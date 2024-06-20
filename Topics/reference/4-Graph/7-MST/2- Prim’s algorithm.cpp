class Graph {
public:
    int size;
    vi vis;
    vector<vector<pl>> adj;

    void addEdge(int u, pl v) {
        adj[u].push_back(v);
    }

    vii PrimespanningTree()
    {           
        priority_queue<vi, vector<vi>, greater<vi>> pq;
        vector<bool> visited(size + 1, false);
        vii Edg;
        
        pq.push({0, 0, 0});
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p[0];
            int u = p[2];
            
            if(visited[u]) continue;
            Edg.push_back(p);
            visited[u] = true; 
            
            for(auto neg : adj[u]){
                if (visited[neg.first]) continue;
                pq.push({neg.second, u, neg.first});  
            }
        }
        
        return Edg;
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        adj.resize(n + 1);
    }
};

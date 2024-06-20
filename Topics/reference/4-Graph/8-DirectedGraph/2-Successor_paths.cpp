// successor graphs. the outdegree of each node is 1

class Graph {
public:
    typedef ll item;
    
    int size, MXPOW;
    vector<pair<ll, item>> FX;
    vector<vector<pair<ll, item>>> adj, SPT;

    item SPTMarge(item &a, item &b){
        return min(a, b);
    }

    void BuildSparse(){
        for (int i = 1; i <= size; i++)
            SPT[i][1] = FX[i];
        
        for (int j = 2; j <= MXPOW; j++)
            for (int i = 1; i <= size; i++) {
                SPT[i][j].first = SPT[i + (1 << (j - 1))][j - 1].first;
                SPT[i][j].second = SPTMarge(SPT[i][j - 1].second, 
                        SPT[i + (1 << (j - 1))][j - 1].second);
            }
    }

    pair<ll, item> getKth(ll u, ll k){
        item res = INT32_MAX;
        for (int i = 0; i < SPT[u].size(); i++)
            if ((1 << i) & k) {
                res = SPTMarge(res, SPT[u][i].second);
                u = SPT[u][i].first;
            }
        return {u, res};
    }

    void addEdge(int u, int v, item w) {
        adj[u].push_back({v, w});
        FX[u] = {v, w};
    }

    Graph(ll n) {
        size = n;
        MXPOW = 1e9;
        FX.resize(n + 1);
        adj.resize(n + 1);
        SPT.resize(n + 1, vector<pair<ll, item>>(ceil(log2(MXPOW + 1)) + 1));
    }
};

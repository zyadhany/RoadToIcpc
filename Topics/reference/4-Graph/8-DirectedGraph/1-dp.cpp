/**
 * Counting the number of paths: from 1:k
 * 
 * another approch: for each x count number from 1 to x.
 * c(x) = c(a1) + c(a2) + c(a3): a1,2,3 is it's parants.
 * we can use the toplogical sort order to calculate that.
 */
ll countPath(vi &Z, ll n, ll k){
    if (n == k) return (0);
    ll &ans = Z[n];
    if (~ans) return (ans);
    ans = 0;

    for (auto neg : adj[n]) {
        ans += countPath(Z, neg, k);
    }
    
    return (ans);
}


/**
 * Count number of shortest path:
 * We can use Dijkstra with dp to montain that.
 */
vp ShortestPathAndCount(ll v) {
    vp Z(size + 1, {INT32_MAX, 0});

    priority_queue<pl, vp, greater<pl>> L;
    L.push({0, v});
    Z[v] = {0, 1};

    while (!L.empty())
    {
        auto k = L.top();
        L.pop();
        if (k.first >= Z[k.second].first) continue;
        
        for (auto neg : adj[k.second]) {
            ll cost = neg.second + k.first;
            if (Z[neg.first].first < cost) continue;
            else if (Z[neg.first].first == cost) {
                Z[neg.first].second += Z[k.second].second;
                continue;
            }
            Z[neg.first] = {cost, Z[k.second].second};
            L.push({cost, neg.first});
        }
    }

    return (Z);
}


/**
 * Longest Path From n to all others node.
 * definde vector(size + 1, INT32_MIN).
 * if val = -1 : it can't reach.
 */
class Graph 
{
public:
    int size;
    vi vis, val;
    vector<vp> adj;
    vector<vp> adjr;
    ll sol = 0;

    ll dfs(vi &X, ll dist, ll n, vector<vp> &add) 
    {
    	if (n == dist) X[n] = 0;
        if (X[n] != INT32_MIN) return X[n];
        X[n] = -1;
        for (auto neg : add[n]) 
        {
            dfs(X, dist, neg.second, add);
        	if(X[neg.second]!=-1)
            X[n] = max(X[n], neg.first + X[neg.second]);
        }
        return X[n];
    }

    void addEdge(int u, int v, ll k) 
    {
        adj[u].push_back({k, v});
        adjr[v].push_back({k, u});
    }

    Graph(ll n) 
    {
        size = n;
        vis.assign(n + 1, 0);   
        val.assign(n + 1, 0);
        adj.resize(n + 1);
        adjr.resize(n + 1);
    }
};

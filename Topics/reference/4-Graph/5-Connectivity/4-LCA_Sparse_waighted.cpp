
class Graph {
public:
    typedef ll item;
    
    int size;
    vi vis, lvl;
    vector<vector<pair<ll, item>>> adj, SPT;

    item SPTMarge(item &a, item &b){
        return max(a, b);
    }

    void BuildSparse(ll node, ll parent, ll w){
        lvl[node] = lvl[parent] + 1;
        SPT[node][0] = {parent, w};
        for (int i = 1; i < SPT[node].size(); i++){
            int tmp = SPT[node][i - 1].first;
            SPT[node][i].first = SPT[tmp][i - 1].first;
            SPT[node][i].second = SPTMarge(SPT[node][i - 1].second, SPT[tmp][i - 1].second);
        }
        for (auto neg : adj[node])
            if (neg.first != parent) BuildSparse(neg.first, node, neg.second);
    }

    pair<ll, item> getKth(ll u, ll k){
        item res = 0;
        for (int i = 0; i < SPT[u].size(); i++)
            if ((1 << i) & k) {
                res = SPTMarge(res, SPT[u][i].second);
                u = SPT[u][i].first;
            }
        return {u, res};
    }

    ll LCA(ll u, ll v) {
        if (lvl[u] > lvl[v]) swap(u, v);
        v = getKth(v, lvl[v] - lvl[u]).first;
        if (u == v) return (u);
        for (int i = SPT[u].size() - 1; i >= 0; i--)
        {
            if (SPT[u][i].first != SPT[v][i].first){
                u = SPT[u][i].first, v = SPT[v][i].first;
            }
        }
        return (SPT[u][0].first);
    }

    ll dist(ll u, ll v) {
        ll p = LCA(u , v);
        return (lvl[u] + lvl[v] - 2 * lvl[p]);
    }

    void addEdge(int u, int v, item w) {
        adj[u].push_back({v, w});
    }

    Graph(ll n) {
        size = n;
        vis.assign(n + 1, 0);
        lvl.assign(n + 1, 0);
        adj.resize(n + 1);
        SPT.resize(n + 1, vector<pair<ll, item>>(ceil(log2(n + 1)) + 1));
    }
};

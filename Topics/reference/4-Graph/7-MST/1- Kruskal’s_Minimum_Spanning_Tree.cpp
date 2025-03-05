/**
 * -Sort all the edges in non-decreasing order of their weight. 
 * 
 * -Pick the smallest edge.
 * Check if it forms a cycle with the spanning tree formed so far.
 * If the cycle is not formed, include this edge. Else, discard it. 
 * 
 * -Repeat step#2 until there are (V-1) edges in the spanning tree.
*/

struct edge {
    ll u, v, w;
    edge(){}
    edge(ll u, ll v, ll w) : u(u), v(v), w(w) {}
    bool operator<(edge &e) {
        return w < e.w;
    }
};

// return edge list of MST, if MST doesn't exist return empty list
vector<edge> MST_Kruskal(vector<edge> E, ll n) {
    vector<edge> TOK;
    sortx(E);

    for (auto e : E) {
        if (get(e.u) != get(e.v)) {
            add(e.u, e.v);
            TOK.push_back(e);
        }
    }

    if (TOK.size() != n-1) return {};
    return TOK;
}

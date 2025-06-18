/*
    dfs tree convert graph to tree so it's easier to process, here is some oppservation:
    1- dfs tree has span edges and back edges, back edges are edges that connect a node to one of its ancestors in the dfs tree.
    2- span edges is bridge edges, if there is no back edges that go trough it.
    3- each back edge form simple a cycle with span edges that path through, (there is other simple cycles). 

    4-if it's directed graph, we can loop through all nodes and make vis = {1, 2}: 1 is proccesed, 2 is still in the stack (cycle). keep going with same technique as previous.
*/

struct Graph {
    vi lvl, prf, arth;
    vii gradj, adj, backedge;
    vp bridges;
    vii ConnectedComp;

    ll dfstree(ll n=1, ll p=0) {
        lvl[n] = lvl[p] + 1;
        for (auto neg : gradj[n]) if (neg != p) {
            if (lvl[neg] > lvl[n]) continue;
            if (lvl[neg]) {
                if (lvl[neg] < lvl[n]) {
                    prf[n]++, prf[neg]--;
                    backedge[n].push_back(neg);
                }
            } else {
                adj[n].push_back(neg);
                prf[n] += dfstree(neg, n);
            }
        }
        
        if (!prf[n] && p != 0) {
            bridges.push_back({n, p});
            arth[n] = 1;
        }
        return prf[n];
    }

    void dfsconnected(ll n=1, ll p=0, ll at=0) {
        if (arth[n] || !p) {
            at = ConnectedComp.size();
            ConnectedComp.push_back({});
        }
        ConnectedComp[at].push_back(n);

        for (auto neg : adj[n]) if (neg != p) {
            dfsconnected(neg, n, at);
        }
    }

    Graph(ll n, vii &gradj): gradj(gradj), adj(n+1), lvl(n+1)
    , backedge(n+1), prf(n+1), arth(n+1) {
        ConnectedComp.resize(1);
    }
};

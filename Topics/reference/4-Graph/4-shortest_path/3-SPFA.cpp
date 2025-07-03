/**
The SPFA algorithm (”Shortest Path Faster Algorithm”) [20] is a variant of the
Bellman–Ford algorithm, that is often more efficient than the original algorithm.
The SPFA algorithm does not go through all the edges on each round, but instead,
it chooses the edges to be examined in a more intelligent way.
The algorithm maintains a queue of nodes that might be used for reducing
the distances. First, the algorithm adds the starting node x to the queue. Then,
the algorithm always processes the first node in the queue, and when an edge
a → b reduces a distance, node b is added to the queue.
The efficiency of the SPFA algorithm depends on the structure of the graph:
the algorithm is often efficient, but its worst case time complexity is still O(nm)
and it is possible to create inputs that make the algorithm as slow as the original
Bellman–Ford algorithm.
*/

// Negtive Cyclyc Can lead to TimeLimit.

#define INF 1e16

class Graph {
public:
    int size;
    vector<vector<pl>> adj;

    void addEdge(int u, ll v, ll w) {
        adj[u].push_back({v, w});
    }

    bool spfa(int s, vi &dist) {  /// Shortest Path Faster Algorithm
        vi cnt(size+1);
        vi inq(size+1);
        for(int i=0; i<size; i++) {
            dist[i] = INF;
            cnt[i] = 0; inq[i] = 0;
        }
        queue<int> q;

        dist[s] = 0;
        q.push(s); inq[s] = 1;
        while (!q.empty()) {
            int v = q.front();
            q.pop(); inq[v] = 0;

            for(auto e : adj[v]) {
                int u = e.first, w = e.second;
                if(dist[v] + w < dist[u]) {
                    dist[u] = dist[v] + w;
                    if(dist[u] < 0 ) return false; /// optimization for TLE.
                    if(!inq[u]) {
                        q.push(u); inq[u] = 1;
                        cnt[u]++;
                        if(cnt[u]>size) return false;
                    }
                }
            }
        }

        return true;
    }

    Graph(ll n) {
        size = n;
        adj.resize(n + 1);
    }
};

// cp algo
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
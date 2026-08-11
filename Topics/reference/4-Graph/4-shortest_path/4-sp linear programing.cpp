/*
We can use spfa to solve some linear programming problems.
for array A we need some condtions in term of A[j] - A[i] <= w
for that we add edge from i to j with weight w.

if there is negative cycle in the graph, the there is no solution.
otherwise we use spfa from the source node to find the value of array. it gives us the max value
*/

/*
    you need to construct and array with given constraints.
    1. summ(l,r) >= v
    2. summ(l,r) <= v
    3. summ(l,r) == v
    all value array strictly in that range [1, 1e9]

    we can solve it by build prefix sum and make constraints.
    1. P[r] - P[l-1] >= v
    2. P[r] - P[l-1] <= v
    3. P[r] - P[l-1] == v
    P[i] - P[i-1] >= 1
    P[i] - P[i-1] <= 1e9
*/
const ll INF = 1e16;
const int MAXV = 1e6+10;
vp adj[MAXV];
ll useNode[MAXV];
ll dist[MAXV], cnt[MAXV], inq[MAXV];

bool spfa(ll n, int s) {  /// Shortest Path Faster Algorithm
    for(int i=0; i<n; i++) {
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
                    if(cnt[u]>n) return false;
                }
            }
        }
    }

    return true;
}

void solve(int tc) {
    ll n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        // r - l >= 1
        // l - r <= -1
        adj[i].push_back({i-1, -1});
        // r - l <= 1e9
        adj[i-1].push_back({i, 1e9});
    }
    
    for(int i=0;i<q;i++){
        int op,l,r,v;
        cin>>op>>l>>r>>v;
        l--;

        if(op==1){
            // r - l >= v
            // l - r <= -v
            adj[r].push_back({l, -v});
        }
        else if(op==2){
            // r - l <= v
            adj[l].push_back({r, v});
        }
        else{
            // r-l == v 
            adj[r].push_back({l, -v});
            adj[l].push_back({r, v});            
        }
    }
    
    if (!spfa(n+1, 0)) {
        cout << "-1\n";
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] - dist[i-1] << ' ';
    }
    cout << '\n';
}


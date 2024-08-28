
// to go from st to end

ll N = 1e6+10, n, m;
vi dis(N, 0);
vector<vector<pair<ll,ll>>> g(N);
ll dijkstra(ll source, ll end) // we add end node to stop the loop when we reach it
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>q;
    q.emplace(0, source);
    for (int i = 1; i <= n; ++i)
        dis[i] = INT64_MAX;
    dis[source] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        ll node = q.top().S;
        q.pop();
        if (dis[node] < cost)
            continue;
        if (node == end) // we add this condition to stop the loop when we reach the end node
            break;
        for(auto neg : g[node]){
            ll ncost = neg.S + cost;
            if (ncost < dis[neg.F]){
                dis[neg.F] = ncost;
                q.emplace(dis[neg.F], neg.F);
            }
        }
    }
    return dis[end];
}
void solve(ll test) {

    ll st,end;
    cin>>n>>m>>st>>end;
    for (int i = 0; i < m; ++i) {
        ll u,v,w;cin>>u>>v>>w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    ll ans = dijkstra(st, end);
    if (ans == INT64_MAX)   // if we can't reach the end node
        cout<<"NONE\n";
    else
        cout<<ans<<"\n";

}



// find pass to go from st to end

ll N = 1e6+10, n, m;
vi dis(N, 0);
vector<vector<pair<ll,ll>>> g(N);
vi pas(N, 0);
ll dijkstra(ll source, ll end)
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>q;
    q.emplace(0, source);
    for (int i = 1; i <= n; ++i)
        dis[i] = INT64_MAX;
    dis[source] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        ll node = q.top().S;
        q.pop();
        if (dis[node] < cost)
            continue;
        if (node == end)
            break;
        for(auto neg : g[node]){
            ll ncost = neg.S + cost;
            if (ncost < dis[neg.F]){
                dis[neg.F] = ncost;
                pas[neg.F] = node;
                q.emplace(dis[neg.F], neg.F);
            }
        }
    }
    return dis[end];
}
void solve(ll test) {

    ll st,end;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        ll u,v,w;cin>>u>>v>>w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    pas[1] = -1;
    ll ans = dijkstra(1, n);
    if (ans == INT64_MAX)
    {
        cout<<-1;
        return;
    }
    vi walk;
    ll mv = n;
    while(mv != -1)
    {
        walk.push_back(mv);
        mv = pas[mv];
    }
    reverse(walk.begin(), walk.end());
    cout(walk);
}









// to move on grid to go from st to end

ll dx[] = {2 ,2,-2,-2,-1,1,-1,1};
ll dy[] = {-1,1 ,-1,1,2,2,-2,-2};

ll N = 1e6+10;
//vi dis(N, 0);
map<pair<ll,ll>,ll>dis;
vector<vector<pair<ll,ll>>> g(N);
ll dijkstra(ll n, ll m, ll nn, ll mm) // the start node is n,m and the end node is nn,mm
{

    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<>>q;
    q.push({0, {n,m}});

    for (int i = 0; i <= 7; ++i)
        for (int j = 0; j <= 7; ++j)
            dis[{i,j}] = INT64_MAX;
    dis[{n,m}] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        pair<ll,ll> node = {q.top().S.F, q.top().S.S};
        q.pop();
        if (dis[node] < cost)
            continue;
        if (node.F == nn && node.S == mm)
            break;
        for(ll h = 0;h<8;h++){
            ll nx = node.F+dx[h];
            ll ny = node.S+dy[h];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            {
                ll ncost = (node.F*(nx) + node.S*(ny)) + cost;
                if (ncost < dis[{nx, ny}]){
                    dis[{nx, ny}] = ncost;
                    q.push({ncost, {nx, ny}});
                }
            }
        }
    }
    return dis[{nn, mm}];
}


void solve(ll test) {

    ll st,end;
    ll nn,mm;
    ll n, m;
    while(cin>>n>>m>>nn>>mm)
    {
        ll ans = dijkstra(n,m,nn,mm);
        if (ans == INT64_MAX)
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
    }
}










// the same as above but without map

ll dx[] = {2 ,2,-2,-2,-1,1,-1,1};
ll dy[] = {-1,1 ,-1,1,2,2,-2,-2};

// to go from st to end

ll N = 1e6+10;
vector<vector<ll>> dis(10, vector<ll>(10, INT64_MAX));
vector<vector<pair<ll,ll>>> g(N);
ll dijkstra(ll n, ll m, ll nn, ll mm) // the start node is n,m and the end node is nn,mm
{

    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<>>q;
    q.push({0, {n,m}});
    for (int i = 0; i <= 8; ++i) {
        for (int j = 0; j <= 8; ++j) {
            dis[i][j] = INT64_MAX;
        }
    }
    dis[n][m] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        pair<ll,ll> node = {q.top().S.F, q.top().S.S};
        q.pop();
        if (dis[node.F][node.S] < cost)
            continue;
        if (node.F == nn && node.S == mm)
            break;
        for(ll h = 0;h<8;h++){
            ll nx = node.F+dx[h];
            ll ny = node.S+dy[h];
            if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8)
            {
                ll ncost = (node.F*(nx) + node.S*(ny)) + cost;
                if (ncost < dis[nx][ny]){
                    dis[nx][ny] = ncost;
                    q.push({ncost, {nx, ny}});
                }
            }
        }
    }
    return dis[nn][mm];
}


void solve(ll test) {

    ll st,end;
    ll nn,mm;
    ll n, m;
    while(cin>>n>>m>>nn>>mm)
    {
        ll ans = dijkstra(n,m,nn,mm);
        if (ans == INT64_MAX)
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
    }
}




// find the sortest path to go from st to end if we make any edge cost = 0

ll N = 1e3+10, n, m;
vii dis(N, vi(N));   // dis[i][j] is the shortest path from i to j
vector<vector<pair<ll,ll>>> g(N);
void dijkstra(ll source)  // we find the shortest path from source to all nodes
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>q;
    q.emplace(0, source);
    for (int i = 1; i <= n; ++i)
        dis[source][i] = INT64_MAX;
    dis[source][source] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        ll node = q.top().S;
        q.pop();
        if (dis[source][node] < cost)
            continue;
        for(auto neg : g[node]){
            ll ncost = neg.S + cost;
            if (ncost < dis[source][neg.F]){
                dis[source][neg.F] = ncost;
                q.emplace(dis[source][neg.F], neg.F);
            }
        }
    }
}
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>q;
    q.emplace(0, source);
    for (int i = 1; i <= n; ++i)
        dis[source][i] = INT64_MAX;
    dis[source][source] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        ll node = q.top().S;
        q.pop();
        if (dis[source][node] < cost)
            continue;
        for(auto neg : g[node]){
            ll ncost = neg.S + cost;
            if (ncost < dis[source][neg.F]){
                dis[source][neg.F] = ncost;
                q.emplace(dis[source][neg.F], neg.F);
            }
        }
    }
}

void solve(ll test) {

    ll st,end, k;
    cin>>n>>m>>k;
    vector<pair<ll,ll>> edges;
    for (int i = 0; i < m; ++i) {
        ll u,v,w;cin>>u>>v>>w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges.emplace_back(u, v);
    }
    vector<pair<ll,ll>> total;  // the nodes that we want to find the shortest path between them
    for (int i = 0; i < k; ++i) {
        cin>>st>>end;
        total.emplace_back(st, end); 
    }
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
    }
    ll ans = INT64_MAX;
    for (int i = 0; i < m; ++i) {  // we try all edges to make the cost of this edge = 0
        ll u = edges[i].F, v = edges[i].S;
        ll cost = 0;
        for (int j = 0; j < k; ++j) {
            ll mn = dis[total[j].F][total[j].S];  // the shortest path from total[j].F to total[j].S
            mn = min(dis[total[j].F][u] + dis[v][total[j].S], mn);  // we make the cost of edge u,v = 0
            mn = min(dis[total[j].S][u] + dis[v][total[j].F], mn);  // we make the cost of edge u,v = 0 but in the other direction
            cost += mn;
        }
        ans = min(ans, cost);
    }
    cout<<ans;
}




// if i have some nodes i can remove find the max nodes to be removed
ll N = 1e5+10, n, m;
vector<ll> dis(N);
vector<ll>result(N);  // to save if it from the addition or the original nodes (addition = 1 original = 0)
ll cnt = 0;
vector<vector<pair<ll,pair<ll,ll>>>> g(N);
void dijkstra(ll source)
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>q;
    q.emplace(0, source);
    for (ll i = 1; i <= n; ++i)
        dis[i] = INT64_MAX;
    dis[source] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        ll node = q.top().S;
        q.pop();
        if (dis[node] < cost)
            continue;
        for(auto neg : g[node]){
            ll ncost = neg.S.F + cost;
            if (ncost < dis[neg.F]){
                dis[neg.F] = ncost;
                q.emplace(dis[neg.F], neg.F);
                result[neg.F] = neg.S.S; // to save we reached it with the original or addition route
            }
            else if (ncost == dis[neg.F] && neg.S.S == 0)  // if we can reach it with original node so we dont need the addition route
            {
                result[neg.F] = 0;
            }
        }
    }
}
void solve(ll test) {

    ll k;
    cin>>n>>m>>k;
    for (ll i = 0; i < m; ++i) {
        ll u,v,w;cin>>u>>v>>w;
        g[u].push_back({v, {w, 0}}); // original
        g[v].push_back({u, {w, 0}});
    }
    vector<pair<ll,ll>>ro;
    for (ll i = 0; i < k; ++i) {
        ll a,b;cin>>a>>b;
        g[1].push_back({a, {b,1}});  // addition
        g[a].push_back({1, {b, 1}});
    }
    dijkstra(1);
    for (ll i = 1; i <= n; ++i) {
        k -= result[i];  // we remove the unnececary routes
    }
    cout<<k;

}








// binary search on the answer
// we need the min value of wisdom to reach the end node with cost less than k


ll N = 1e6+10, n, m;
vi dis(N, 0);
vector<vector<pair<ll,pair<ll,ll>>>> g(N);
ll dijkstra(ll mid) // we add end node to stop the loop when we reach it
{
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>>q;
    q.push({0, 1});
    for (int i = 1; i <= n; ++i)
        dis[i] = INT64_MAX;
    dis[1] = 0;
    while(!q.empty())
    {
        ll cost = q.top().F;
        ll node = q.top().S;
        q.pop();
        if (dis[node] < cost)
            continue;
        if (node == n) // we add this condition to stop the loop when we reach the end node
            break;
        for(auto neg : g[node]){
            ll ncost = neg.S.F + cost;
            ll nwisdom = neg.S.S;
            if (nwisdom>mid) // if the wisdom is greater than mid we can't go through this edge
                continue;
            if (ncost < dis[neg.F]){
                dis[neg.F] = ncost;
                q.push({dis[neg.F], neg.F});
            }
        }
    }
    return dis[n];
}
void solve(ll test) {

    for (int i = 0; i < N; ++i) {
        g[i].clear();
    }
    ll k;
    cin>>n>>m>>k;
    for (int i = 0; i < m; ++i) {
        ll u,v,c,w;cin>>u>>v>>c>>w;
        g[u].push_back({v, {c, w}}); // we pass the cost and the wisdom
        g[v].push_back({u, {c, w}});
    }
    ll st = 1, end = 1e9, ans = -1;
    while(st<=end)  // test all the values from 1 to 1e9 for min value of wisdom
    {
        ll mid = (st+end)/2;
        ll val = dijkstra(mid);
        if (val<k)
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            st = mid+1;
        }
    }
    cout<<ans<<"\n";

}





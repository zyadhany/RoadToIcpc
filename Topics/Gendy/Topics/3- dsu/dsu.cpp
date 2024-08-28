ll N = 1e6+10, components;
vi par(N, 0), sz(N, 1);
ll find(ll node)
{
    if (par[node] == node)
        return node;
    else
        return par[node] = find(par[node]);
}

void join(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (sz[v]>sz[u])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    components--;
}


void solve(ll test) {

    ll n;cin>>n;
    components = n;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}









// To connect all component with less weights

ll N = 1e6+10, components;
vi par(N, 0), sz(N, 1);
ll find(ll node)
{
    if (par[node] == node)
        return node;
    else
        return par[node] = find(par[node]);
}

bool join(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return 0;
    if (sz[v]>sz[u])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    components--;
    return 1;
}

struct edge{
    ll u, v, w;
};

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

ll kruskal(vector<edge>edges)
{
    sort(all(edges), cmp);
    ll t = 0;
    for(auto it:edges)
    {
        if (join(it.u, it.v))
            t += it.w;
    }
    return t;
}


void solve(ll test) {

    ll n;cin>>n;
    components = n;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 0;
    }
    vector<edge>v;
    for (int i = 1; i <= n; ++i) {
        ll k;cin>>k;
        for (int j = 0; j < k; ++j) {
            ll a,b;cin>>a>>b;
            v.push_back({i, a, b});
        }
    }
    ll ans = kruskal(v);
    cout<<ans<<"\n";
}








// move node from component to another component

ll N = 1e6+10, components;
vi par(N, 0), sz(N, 1), s(N, 0);
ll find(ll node)
{
    if (par[node] == node)
        return node;
    else
        return par[node] = find(par[node]);
}

bool join(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (sz[v]>sz[u])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    s[u] += s[v];
    components--;
    return true;
}

bool move(ll u, ll v)
{
    ll is = find(u);
    v = find(v);
    if (is == v)
        return false;
    sz[is]--;
    sz[v]++;
    s[is] -= u;
    s[v] += u;
    par[u] = v;
    return true;
}


void solve(ll test) {


    ll n, k;
    while(cin>>n>>k)
    {
        components = n;
        for (int i = 1; i <= n; ++i) {
            par[i] = n+i;
            par[n+i] = n+i;
            sz[n+i] = 1;
            s[n+i] = i;
        }
        for (int i = 0; i < k; ++i) {
            ll a;cin>>a;
            if (a==1)
            {
                ll p,q;cin>>p>>q;
                join(p,q);
            }
            else if (a==2)
            {
                ll p,q;cin>>p>>q;
                move(p, q);
            }
            else
            {
                ll p;cin>>p;
                ll is = find(p);
                cout<<sz[is]<<' '<<s[is]<<"\n";
            }
        }
    }
}


// print the joined components

ll N = 1e6+10, components;
vi par(N, 0), sz(N, 1);
vii node(1e6, vi());

bool join(ll u, ll v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (node[v].size()>node[u].size())
        swap(u, v);
    par[v] = u;
    for (int j = 0; j < node[v].size(); ++j) {
        node[u].push_back(node[v][j]);
    }
    node[v].clear();
    components--;
    return true;
}
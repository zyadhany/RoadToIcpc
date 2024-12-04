// Goes all the way to the end, then comes back

vii node(1e6+10,vi());
vector<bool> vis(1e6+10,false);
void dfs(ll n)
{
    vis[n] = true;
    for(ll i:node[n])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}

void solve(int tc) {

    ll n;cin>>n;
    for (ll i = 1; i <= n; ++i) {
        ll x,y;cin>>x>>y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
}


//detect cycle

vii node(1e6+10,vi());
vector<ll> vis(1e6+10,-1);
bool g = true;
void dfs(ll n,bool clr)
{
    //cout<<n<<endl;
    vis[n] = clr;
    for(ll i:node[n])
    {
        if(vis[n] == vis[i])
        {
            g = false;
        }
        else if (vis[i]==-1)
        {
            dfs(i,!clr);
        }
    }
}


//remove by order topological sort

vii node(1e6+10,vi());
vector<ll> vis(1e6+10,0);
bool g = true;
vi ans;
void dfs(ll n)
{
    //cout<<n<<endl;
    vis[n] = 1;
    for(ll i:node[n])
    {
        if(vis[i] == 1)
        {
            g = false;
        }
        else if (!vis[i])
        {
            dfs(i);
        }
    }
    ans.push_back(n);
    vis[n] = 2;
}

void solve(ll test) {

    if (!g) // it can be impossible if its not tree
    {
        cout<<"IMPOSSIBLE\n";
    }
}


// bibrate

// to divide the elemnt to 2 and
// to check if any edge if connected to one from another side
// the cycles should be even if odd i have to remove one edge


vector<bool>vis;
vector<vector<ll>>adj;
vector<bool>col;

bool isBipartite(int node)
{
   vis[node]=1;
    for (int i = 0; i <adj[node].size() ; ++i) {
        int ch=adj[node][i];
        if (!vis[ch]) {
            col[ch] = !col[node];
            if (!isBipartite(ch)) {
                return false;
            }
        }
        else if (col[node]==col[ch])
            return false;
    }
    return true;
}

ll n, e;
cin >> n >> e;
adj.assign(n+2,vector<ll>());
col.assign(n+2,false);
vis.assign(n+2,false);
ll u, v;
while (e--) {
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}
col[1] = 0;
bool f=1;
for (int i = 1; i <=n ; ++i) {
    f= isBipartite(i);
    if (!f)break;
}
if (f) {
    cout<<"is\n";
} else {
    cout<<"isn't\n";
}
    
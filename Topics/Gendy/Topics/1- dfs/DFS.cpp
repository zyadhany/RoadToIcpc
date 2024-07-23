//بيمشي للاخر خالص بعدين يرجع

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


//remove by order

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
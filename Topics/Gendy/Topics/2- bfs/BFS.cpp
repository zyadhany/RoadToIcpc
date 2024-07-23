// بيمشي بالترتيب بالليفل

// bfs and check cycle

vii node(1e6+10,vi());
vector<bool> vis(1e6+10,false);
queue<ll>q;
bool g = true;
vi par(1e6+10);
void bfs()
{
    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        vis[cur] = true;
        for(ll i:node[cur])
        {
            if (!vis[i])
            {
                par[i] = cur;
                q.push(i);
            }
            else if (i != par[cur])
            {
                g = false;
            }
        }
    }
}

void solve(int tc) {

    ll n,m;cin>>n>>m;
    for (ll i = 1; i <= m; ++i) {
        ll x,y;cin>>x>>y;
        node[x].push_back(y);
        node[y].push_back(x);
    }
    q.push(1);
    par[1] = 1;
    bfs();
    bool ch = true;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
        {
            ch = false;
            break;
        }
    }
    if (!ch || !g)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES";
    }
}



// shortest way to find value a*2 || a-1 -> b


vii node(1e6+10,vi());
ll dx[] = {-2, -2 ,-1, -1, 2, 2, 1, 1}; // the all possible ways
ll dy[] = {-1, 1  ,-2,  2,-1, 1,-2, 2}; // y

void solve(int tc) {


    ll a,b;cin>>a>>b;
    vi vis(1e6, 0);
    queue<ll>q;
    vi dis(1e6, 0);
    q.emplace(a);
    dis[a] = 0;
    vis[a] = 1;

    while(!q.empty())
    {
        ll xt = q.front();
        vis[xt] = 1;
        //cout<<xt<<' '<<yt<<" here\n";
        q.pop();
        ll xo = xt*2;
        ll yo = xt-1;
        //cout<<xo<<' '<<yo<<endl;
        if (xo>0&&xo<1e5&&!vis[xo])
        {
            vis[xo] = 1;
            dis[xo] = dis[xt]+1;
            q.push(xo);
        }
        if (yo>0&&yo<1e5&&!vis[yo])
        {
            vis[yo] = 1;
            dis[yo] = dis[xt]+1;
            q.push(yo);
        }
    }
    cout<<dis[b];
}


// move by levels

    queue<pair<pair<ll,ll>,ll>>q;
    q.push({x,0});
    vis[x] = 1;
    ll ans = -1;
    while(!q.empty())
    {
        ll x = q.front().F;
        ll lvl = q.front().S;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            ll xx = x+dx[i];
            if (condition)
            {
                q.push({xx, lvl+1});
                vis[xx] = 1;
            }
        }
    }
    cout<<ans;
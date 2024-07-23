int n,m,st,en;
class Dijkstra
{
public:
	ll size=0,st=0;
	prq<pair<int,int>> pq;
	vector<vector<pair<ll,ll>>> g;
	vector<ll> d,par;
	Dijkstra(ll n,ll start)
	{
		size=n; st=start;
		g.resize(n+1);
		FOR(i,1,n+1)g[i].clear();
		d.resize(n+1);
		par.resize(n+1);
		fill(all(d),1e18);
		d[st]=0;
		par[st]=st;
		pq.push({0,st});
	}
	void AddEdge(ll u,ll v,ll c)
	{
		g[u].pb({v,c});
     		g[v].pb({u,c});
	}
	void dijkstra()
	{
		while(!pq.empty())
		{
			ll cost=-pq.top().fi;
			int node=pq.top().se;
			pq.pop();
			if(cost>d[node])con;
			for(auto a:g[node])
			{
				ll newcost=d[node]+a.se;
				if(d[a.fi]>newcost)par[a.fi]=node,
				d[a.fi]=newcost,pq.push({-newcost,a.fi});
			}
		}
	}
};
void ITcharDo()
{
     cin>>n>>m; st=1,en=n;
     Dijkstra dij(n,st);
     while(m--)
     {
     	int u,v,c; cin>>u>>v>>c;
     	dij.AddEdge(u,v,c);
     }
     dij.dijkstra();
     if(dij.d[en]==1e18){cout<<"-1\n"; return ;}
     vector<ll> sol; sol.pb(en);
     while(dij.par[en]!=en)
     {
     	sol.pb(dij.par[en]);
     	en=dij.par[en];
     }
     reverse(all(sol)); cout(sol,sz(sol));
}
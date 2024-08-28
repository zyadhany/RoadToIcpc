class DSU_MST
{
public:
	ll size=0;
	vector<ll> SZ,pr;
	vector<pair<ll,pair<ll,ll>>> g;
	DSU_MST(ll n)
	{
		size=n;
		SZ.resize(n+1);
		pr.resize(n+1);
		fill(all(SZ),1);
    		iota(all(pr),0);
	}
	void AddEdge(ll u,ll v,ll x)
	{
		g.pb({x,{u,v}});
	}
	//sort(all(g));
	ll find(ll node)
	{
		if(node==pr[node])return node;
		return pr[node]=find(pr[node]);
	}
	bool join(ll u,ll v)
	{
		u=find(u); v=find(v);
		if(u==v)return 0;
		if(SZ[v]>SZ[u])swap(u,v);
		pr[v]=u;
		SZ[u]+=SZ[v];
		return 1;
	}
};
void ITcharDo()
{
     ll n,m,sol=0; cin>>n>>m;
     DSU_MST dsu(n);
     FOR(i,0,m)
     {
     	ll u,v,x; cin>>u>>v>>x;
     	dsu.AddEdge(u,v,x);
     }
     sort(all(dsu.g));
     FOR(i,0,m)
     	if(dsu.join(dsu.g[i].se.fi,dsu.g[i].se.se))
     		sol+=dsu.g[i].fi;
     cout<<sol<<el;
}
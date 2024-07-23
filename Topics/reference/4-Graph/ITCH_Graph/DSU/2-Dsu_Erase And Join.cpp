code 

erase and join

ll n,m,x;
ll ex[N],add[N];
class DSU
{
public:
	ll size=0;
	vector<ll> SZ,pr;
	DSU(ll n)
	{
		size=n;
		SZ.resize(n+1);
		pr.resize(n+1);
		fill(all(SZ),1);
    		iota(all(pr),0);
	}
	ll find(ll node)
	{
		if(node==pr[node])return node;
		return pr[node]=find(pr[node]);
	}
	void join(ll u,ll v)
	{
		u=find(u); v=find(v);
		if(u==v)return ;
		if(SZ[v]>SZ[u])swap(u,v);
		pr[v]=u;
		SZ[u]+=SZ[v];
	}
};
void ITcharDo()
{
     ll u,v; cin>>n>>x>>m;
     DSU dsu(n);
     set<pair<ll,ll>> st;
     FOR(i,0,x) 
     cin>>u>>v,st.insert({min(u,v),max(u,v)});
     vector<pair<ll,pair<ll,ll>>> v2;
     FOR(i,0,m)
     {
     	string s; cin>>s>>u>>v;
     	if(s=="ask")v2.pb({2,{u,v}});
     	else v2.pb({1,{u,v}}),st.erase({min(u,v),max(u,v)});
     }
     
     for(auto a:st)dsu.join(a.fi,a.se);
     vector<string> sol;
     for(int i=m-1; i>=0; i--)
     {
     	if(v2[i].fi==1)dsu.join(v2[i].se.fi,v2[i].se.se);
     	else sol.pb((dsu.find(v2[i].se.fi)==dsu.find(v2[i].se.se))?YS:NO);
     }
     reverse(all(sol)); cout(sol,sz(sol));
}
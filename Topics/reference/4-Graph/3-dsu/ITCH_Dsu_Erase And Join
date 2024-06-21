code 

erase and join

l n,m,x;
ll SZ[N],pr[N],ex[N],add[N];
vector<ll> g[N];
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
void ITcharDo()
{
	 ll u,v;
     cin>>n>>x>>m;
     fill(SZ,SZ+n+1,1);
     iota(pr,pr+n+1,0);
     set<pair<ll,ll>> st;
     FOR(i,0,x) cin>>u>>v,st.insert({min(u,v),max(u,v)});
     vector<pair<ll,pair<ll,ll>>> v2;
     FOR(i,0,m)
     {
     	string s; cin>>s>>u>>v;
     	if(s=="ask")v2.pb({2,{u,v}});
     	else v2.pb({1,{u,v}}),st.erase({min(u,v),max(u,v)});
     }
     
     for(auto a:st)join(a.fi,a.se);
     vector<string> sol;
     for(int i=m-1; i>=0; i--)
     {
     	if(v2[i].fi==1)join(v2[i].se.fi,v2[i].se.se);
     	else sol.pb((find(v2[i].se.fi)==find(v2[i].se.se))?YS:NO);
     }
     reverse(all(sol)); cout(sol,sz(sol));
}

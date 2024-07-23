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
code 

عايز اول ايدج مش biparite

ll SZ[N],pr[N],Siz[N];
pair<ll,ll> find(ll node)
{
	if(node==pr[node])return {node,0};
	auto y=find(pr[node]);
    pr[node]=y.fi;
    SZ[node]=(y.se+SZ[node])%2;
    return {pr[node],SZ[node]};
}
bool join(ll u,ll v)
{
	auto fx=find(u);
    auto fy=find(v);
    if(fx.fi==fy.fi)return fx.se!=fy.se;
    if(Siz[fx.fi]>Siz[fy.fi])swap(fx,fy);
    pr[fx.fi]=fy.fi;
    SZ[fx.fi]=(1+fx.se+fy.se)%2;
    
    Siz[fy.fi]+=Siz[fx.fi];
    return 1;
}
void ITcharDo()
{
     ll n,m; cin>>n>>m;
     fill(Siz,Siz+n+1,1);
     iota(pr,pr+n+1,0);
     ll count=0;
     FOR(i,0,m)
     {
     	ll flag,u,v; cin>>u>>v;
     	
        if(!join(u,v)){cout<<i+1<<el; return ;}
     }
     cout<<-1<<el;
}

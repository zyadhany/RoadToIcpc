code
الجراف ثناىيا ولا لا

ll SZ[N],pr[N],Siz[N];
pair<ll,ll> find(ll node)
{
    if(node==pr[node])return {node,0};
    auto y=find(pr[node]);
    pr[node]=y.fi;
    SZ[node]=(y.se+SZ[node])%2;
    return {pr[node],SZ[node]};
}
void join(ll u,ll v)
{ 
    auto fx=find(u);
    auto fy=find(v);
    if(Siz[fx.fi]>Siz[fy.fi])swap(fx,fy);
    pr[fx.fi]=fy.fi;
    SZ[fx.fi]=(1+fx.se+fy.se)%2;
    
    Siz[fy.fi]+=Siz[fx.fi];
}
void ITcharDo()
{
     ll n,m; cin>>n>>m;
     fill(Siz,Siz+n+1,1);
     iota(pr,pr+n+1,0);
     ll count=0;
     FOR(i,0,m)
     {
     	ll flag,u,v; cin>>flag>>u>>v;
     	u=(u+count)%n;
        v=(v+count)%n;
        if(!flag) join(u,v);
        else 
        {
            if(find(u)==find(v)) count++,cout<<YS;
            else cout<<NO;
        }
     }
}

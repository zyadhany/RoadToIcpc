int find(int node)
{
  if(par[node]==node)return node;
  return par[node]=find(par[node]);
}
int  join(int u,int v)
{
   u=find(u);
   v=find(v);
   if(u==v)return 0;
    if(sz[u] < sz[v])
        swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
    return 1;
}
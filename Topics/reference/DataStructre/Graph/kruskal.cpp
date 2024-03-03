#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,par[N],sz[N];
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
struct edge{
  int u,v,w;
};
bool comp(edge x, edge y)
{
  return x.w<y.w;
}
int kruskal(vector<edge> edges)
{
  sort(edges.begin(),edges.end(),comp);
  int total=0;
  for(auto i : edges)
  {
         if(join(i.u,i.v))total+=i.w;
  }
  return total;
}
int main()
{
 int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {
    par[i]=i;
    sz[i]=1;
   }
  vector<edge>v(m);
  for(int i=0;i<m;i++)
     cin>>v[i].u>>v[i].v>>v[i].w;
     cout<<kruskal(v);
}
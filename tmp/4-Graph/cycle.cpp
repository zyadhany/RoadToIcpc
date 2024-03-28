#include"bits/stdc++.h"
using namespace std;
#define ln '\n'
#define ll long long
const int N=2e5+5;
vector<vector<int>>g;
int from=-1,to=-1,vis[N],per[N];
void dfs(int node,int p){
    vis[node]=1;
    per[node]=p;
    for(auto neg:g[node]){
        if(neg!=p){
        if(from==-1&&vis[neg]){
            from=node;
            to=neg;
            return;
        }
        else if(!vis[neg])
            dfs(neg,node);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    g=vector<vector<int>>(n+1);
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        per[i]=-1;
        vis[i]=0;
    }
    from=-1;
    dfs(1,-1);
    vector<int>cy;
    while(from!=to){
        cy.push_back(from);
        from=per[from];
    }
    cy.push_back(to);
   for(int i=0;i<cy.size();i++)cout<<cy[i]<<" ";
   return 0;
}
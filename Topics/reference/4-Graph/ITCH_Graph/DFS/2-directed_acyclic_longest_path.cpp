class Graph 
{
	public:
	    int size;
	    vector<vector<pair<ll,ll>>> adj;
	    vector<vector<pair<ll,ll>>> adjr;
	    Graph(ll n) 
	    {
	        size=n;
	        adj.resize(n + 1);
       	        adjr.resize(n + 1);
	    }
	    void addEdge(int u,int v,ll k) 
	    {
	    	adj[u].pb({v,k});
       		adjr[v].pb({u,k});
	    }
	    ll dfs(vector<ll> &sol,ll dist,ll n,
	    vector<vector<pair<ll,ll>>> &g) 
	    {
	    	if(n==dist)sol[n]=0;
	        if(sol[n]!=-1e18)return sol[n];
	        sol[n]=-1;
	        for(auto a:g[n]) 
	        {
	            dfs(sol,dist,a.fi,g);
	        	if(sol[a.fi]!=-1)
	            sol[n]=max(sol[n],a.se+sol[a.fi]);
	        }
	        return sol[n];
	    }
};
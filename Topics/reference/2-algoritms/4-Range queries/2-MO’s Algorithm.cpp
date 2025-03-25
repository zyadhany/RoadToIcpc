int block;
 
// Structure to represent a query range
struct Query
{
    int L, R, ind;
};
 
// Function used to sort all queries so that all queries 
// of the same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(Query &x, Query &y)
{
    if (x.L/block != y.L/block)
       return x.L/block < y.L/block;
    if ((x.L/block) & 1) return x.R > y.R;
    return x.R < y.R;
}

void MoAdd(ll &summ, ll val) {
    summ += val;
}

void MoRemove(ll &summ, ll val) {
    summ -= val;    
}

vi MoQueryResult(vector<Query> Q, vi &X)
{
    ll n, m;
 
    n = X.size(), m = Q.size();
    block = (int)sqrt(n);
    vi res(m);
 
    sort(Q.begin(), Q.end(), compare);
 
    ll currL = 0, currR = 0;
    ll currSum = 0;
 
    for (int i = 0; i < m; i++)
    {
        ll L = Q[i].L, R = Q[i].R, ind = Q[i].ind;
 
        while (currL > L) MoAdd(currSum, X[--currL]);
        while (currR <= R) MoAdd(currSum, X[currR++]);
        while (currL < L) MoRemove(currSum, X[currL++]);
        while (currR > R+1) MoRemove(currSum, X[--currR]);
 
        res[ind] = currSum;
    }
 
    return (res);
}

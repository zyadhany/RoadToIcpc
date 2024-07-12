/**
 * Baby-Step Giant-Step:
 * get value of x for a^x = b (mod m)
 * https://www.mat.uniroma2.it/~geatti/HCMC2023/Lecture4.pdf
 */
ll BSGS(ll a,ll b,ll m)
{
    a%=m;
    b%=m;
    if(b==1)return 0;
    unordered_map<ll,ll>ma;
    ll n=sqrt(2*m)+1;
    ll e=1;
    for(int i=0;i<n;i++)
    {
        if(ma.count(b*e%m)==0)ma[b*e%m]=i;
        e=e*a%m;
    }
    ll t=1;
    for(int i=1;i<=n+1;i++)
    {
        t=t*e%m;
        if(ma.count(t))return i*n-ma[t];
    }
    return -1;
}

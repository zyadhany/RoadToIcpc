pair<vi, vi> LCP(vector<int> &suff, string &s) {
    ll n = s.size();
    vi ind(n), lcp(n-1); // -1 for $ char
    for (int i = 0; i < n; i++) ind[suff[i]] = i;
    
    int ls = 0;
    for (int i = 0; i < n-1; i++)
    {
        int prv = suff[ind[i]-1];
        while (s[i+ls]==s[prv+ls])ls++;
        lcp[ind[i]-1] = ls, ls = max(0, ls-1);
    }
    
    return {lcp, ind};
}

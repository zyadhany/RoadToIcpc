// Longest common prefix of a string and substring starting at i
vi Z_function(string &s) {
    int n = s.size();
    vi Z(n);

    ll l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r) Z[i] = min(r-i, Z[i-l]);
        while (i+Z[i]<n && s[i+Z[i]] == s[Z[i]]) Z[i]++;
        if (i + Z[i] > r) l = i, r = i+Z[i];        
    }

    return Z;
}

// for each substring starting and i in s find it's LCP(longest-common-prefix) with pattern p.
vi patternSearch(string &s, string p) {
    int n = s.size(), m = p.size();
    p += "#" + s;
    vi res(n);
    auto Z = Z_function(p);
    for (int i = 0; i < n; i++)
    {
        res[i] = Z[i+m+1];
    }
    
    return res;
}

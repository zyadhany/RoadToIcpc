ll LongestCommonSubseq(string &s, string &t) {
	vii X(s.size() + 1, vi(t.size() + 1));
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= t.size(); j++)
		{
			X[i][j] = max(X[i][j - 1], X[i - 1][j]);
			X[i][j] = max(X[i][j], X[i - 1][j - 1] + (s[i - 1] == t[j - 1]));
		}
	return (X[s.size()][t.size()]);
}

// get longest increasing subsequince if segment(l, r).
// each value start at postion and end else where.
ll LISQSegment(vi &X) {
    ll n, res;

    n = X.size();
    unordered_map<int, int> ST, EN;
    ST.reserve(n); EN.reserve(n);
    set<ll> st;
    vi dp(n + 10, INT32_MAX);

    for (int i = 0; i < n; i++)
    {
        if (!ST.count(X[i])) ST[X[i]] = i;
        EN[X[i]] = i;
        st.insert(X[i]);
    }
    
    dp[0] = -1, res = 0;
    for (auto a : st) {
        ll st = ST[a], en = EN[a];
        ll l, r, at;
        
        l = 0, r = res + 1;
        while (l < r)
        {
            at = (l + r) / 2;
            if (dp[at] < en) l = at + 1;
            else r = at;
        }
        
        if (dp[l - 1] <= st) {
            dp[l] = en;
            res = max(res, l);
        }
    }

    return (res);
}

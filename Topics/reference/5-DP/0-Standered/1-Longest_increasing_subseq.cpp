ll Longest_Increasing_SubSeq(vi &X) {
    vi Z;
    for (int i = 0; i < X.size(); i++) {
        ll re = upper_bound(Z.begin(), Z.end(), X[i]) - Z.begin();
        if (re == Z.size())Z.push_back(X[i]);
        else Z[re] = X[i];
    }
    return Z.size();
}

vp Longest_Increasing_SubSeq(vi &X) {
    vp res;
    vp Z(1, {INT32_MIN, -1});
    vi prev(X.size());

    for (int i = 0; i < X.size(); i++) {
        pl k = {X[i], 0};
        ll re = lower_bound(Z.begin(), Z.end(), k) - Z.begin();
        prev[i] = Z[re - 1].second;
        if (re == Z.size()) Z.push_back({X[i], i});
        else Z[re] = {X[i], i};
    }

    int at = Z.back().second;

    while (at != -1)
    {
        res.push_back({X[at], at});
        at = prev[at];
    }
    
    reverse(all(res));
    return res;
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

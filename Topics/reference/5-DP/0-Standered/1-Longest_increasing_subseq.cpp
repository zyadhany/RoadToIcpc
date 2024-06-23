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

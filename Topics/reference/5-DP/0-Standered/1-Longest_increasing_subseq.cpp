ll Longest_Increasing_SubSeq(vi &X) {
    vi Z;
    for (int i = 0; i < X.size(); i++) {
        ll re = upper_bound(Z.begin(), Z.end(), X[i]) - Z.begin();
        if (re == Z.size())Z.push_back(X[i]);
        else Z[re] = X[i];
    }
    return Z.size();
}
vi DataCompress(vi &X) {
    ll at = 0;
    mi Y;
    vi Z(X), M(X.size());
    sortx(Z);
    for (int i = 0; i < Z.size(); i++)
        if (!Y.count(Z[i])) Y[Z[i]] = Y.size();
    for (int i = 0; i < X.size(); i++)
        M[i] = Y[X[i]];
    return (M);
}

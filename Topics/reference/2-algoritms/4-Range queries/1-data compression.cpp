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

// ----------
sort(begin(coords), end(coords));
	coords.erase(unique(begin(coords), end(coords)), end(coords));
	const auto id = [&](int x) -> int {
		return lower_bound(begin(coords), end(coords), x) - begin(coords);
	};
// Graham Scan
ll CrossPrduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}

vi ConvexHull(vp &X) {
    int piv = min_element(X.begin(), X.end()) - X.begin();
    vi HL{piv}, can;
    for (int i = 0; i < X.size(); i++) if (X[i] != X[piv]) can.push_back(i);
    sort(can.begin(), can.end(), [&](int a, int b) {
        pl x = {X[a].first - X[piv].first, X[a].second - X[piv].second};
        pl y = {X[b].first - X[piv].first, X[b].second - X[piv].second};
        ll cp = CrossPrduct(x, y);
        if (cp == 0) return x.first * x.first + x.second * x.second < y.first * y.first + y.second * y.second;
        return cp > 0;
    });

    for (auto i : can) {
        while (HL.size() >= 2) {
            int a = HL[HL.size() - 1], b = HL[HL.size() - 2];
            if (CrossPrduct({X[a].first - X[b].first, X[a].second - X[b].second}, {X[i].first - X[b].first, X[i].second - X[b].second}) > 0) break;
            HL.pop_back();
        }
        HL.push_back(i);
    }
    return HL;
}

// Monotone Chain
vp ConvexHull(vp X) {
    sortx(X);
    X.erase(unique(all(X)), X.end());
    int n = X.size();

    vp HL;

    if (n < 3) return X;

    // Lower hull
    for (int i = 0; i < n; i++) {
        while (HL.size() >= 2) {
            pl a = HL[HL.size() - 1], b = HL[HL.size() - 2];
            if (CrossPrduct({a.first - b.first, a.second - b.second}, {X[i].first - b.first, X[i].second - b.second}) > 0) break;
            HL.pop_back();
        }
        HL.push_back(X[i]);
    }

    int t = HL.size();
    // Upper hull
    for (int i = n - 2; i >= 0; i--) {
        while (HL.size() > t) {
            pl a = HL[HL.size() - 1], b = HL[HL.size() - 2];
            if (CrossPrduct({a.first - b.first, a.second - b.second}, {X[i].first - b.first, X[i].second - b.second}) > 0) break;
            HL.pop_back();
        }
        HL.push_back(X[i]);
    }
    
    HL.pop_back();

    return HL;
}

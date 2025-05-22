vector<int> suffixarray(string &s) {
    s += '$';
    int n = s.size();
    vector<int> suff(n), P(n);
    vector<pair<int, int>> V(n);
    for (int i = 0; i < n; i++) suff[i]=i, V[i] = {s[i], s[i]};
    
    auto comp = [&](int i, int j) {
        if (V[i].first != V[j].first) return V[i].first < V[j].first;
        return V[i].second < V[j].second;
    };
    sort(all(suff), comp);
    
    vector<int> tmp(n), frq(n), C(n);
    for (int k = 1; k < n; k*=2)
    {
        C[0] = frq[0] = P[suff[0]] = 0;
        for (int i = 1; i < n; i++) P[suff[i]] = P[suff[i-1]] + (V[suff[i]] != V[suff[i-1]]), frq[i] = 0;
        for (int i = 0; i < n; i++) V[i] = {P[i], P[(i+k)%n]}, suff[i] = (suff[i] - k + n) % n, frq[P[i]]++;
        for (int i = 1; i < n; i++) C[i] = C[i-1] + frq[i-1];
        for (int i = 0; i < n; i++) tmp[C[V[suff[i]].first]] = suff[i], C[V[suff[i]].first]++;
        swap(suff, tmp);
    }

    return suff;
}

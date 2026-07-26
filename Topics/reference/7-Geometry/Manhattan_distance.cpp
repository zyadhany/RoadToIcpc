// return max Manhattan distance and the two points that achieve it

// using bitmask we can try all 4 combinations of signs for the two coordinates and maxmize the sum
vi manh(vp &X, vi &vis) {
    vp mask(4, {-INF, -1});
    ll sol = -INF;
    ll u = -1, v = -1;

    for (int i = 0; i < X.size(); i++)
    {
        if (vis[i]) continue;
        for (int j = 0; j < 4; j++)
        {
            ll a = (j & 1 ? X[i].first : -X[i].first) + 
                   (j & 2 ? X[i].second : -X[i].second);            
            ll re = mask[3 ^ j].first + a;
            if (re > sol) {
                sol = re;
                u = i;
                v = mask[3 ^ j].second;
            }
        }
        for (int j = 0; j < 4; j++)
        {
            ll a = (j & 1 ? X[i].first : -X[i].first) + 
                   (j & 2 ? X[i].second : -X[i].second);   
            mask[j] = max(mask[j], {a, i});   
        }        
    }

    return {sol, u, v};
}

/*
    you can transform the points (x, y) to (u, v) = (x + y, x - y)
    then the Manhattan distance between two points max(max(u) - min(u), max(v) - min(v)).
*/
vi manh(vp &X) {
    int u1 = 0, u2 = 0, v1 = 0, v2 = 0;
    for (int i = 0; i < X.size(); i++) {
        ll u = X[i].first + X[i].second;
        ll v = X[i].first - X[i].second;

        if (u < X[u1].first + X[u1].second) u1 = i;
        if (u > X[u2].first + X[u2].second) u2 = i;
        if (v < X[v1].first - X[v1].second) v1 = i;
        if (v > X[v2].first - X[v2].second) v2 = i;
    }

    ll du = (X[u2].first + X[u2].second) - (X[u1].first + X[u1].second);
    ll dv = (X[v2].first - X[v2].second) - (X[v1].first - X[v1].second);

    if (du > dv) return {du, u1, u2};
    return {dv, v1, v2};
}
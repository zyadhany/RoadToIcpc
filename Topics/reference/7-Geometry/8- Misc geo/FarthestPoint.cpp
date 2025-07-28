struct P {
    ll x, y, z;
};

// given n point in 3D space, for each point, find the point that is farthest from it
// convert it in manhattan distance for each point it can be one of the 8 possible combinations
// +++, ++-, +-+, -++, +--, -+-, --+, and ---
vi FarthestPoint(const vector<P>& points, int n) {
    vi result(n);
    vector<vp> Z(8);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            ll summ = 0;
            for (int h = 0; h < 3; h++) {
                if (j & (1 << h)) summ -= (h == 0 ? points[i].x : (h == 1 ? points[i].y : points[i].z));
                else summ += (h == 0 ? points[i].x : (h == 1 ? points[i].y : points[i].z));
            }
            Z[j].push_back({summ, -i});
        }
    }

    for (int i = 0; i < 8; i++) {
        sort(Z[i].rbegin(), Z[i].rend());
    }

    for (int i = 0; i < n; i++) {
        pl mx = {-1, -1};
        for (int j = 0; j < 8; j++) {
            ll summ = 0;
            for (int h = 0; h < 3; h++) {
                if (j & (1 << h)) summ -= (h == 0 ? points[i].x : (h == 1 ? points[i].y : points[i].z));
                else summ += (h == 0 ? points[i].x : (h == 1 ? points[i].y : points[i].z));
            }
            ll nv, nd;
            for (auto [v, d] : Z[7 ^ j]) if (d != -i) {
                nv = v;
                nd = d;
                break;
            }
            summ += nv;
            mx = max(mx, {summ, nd});
        }
        result[i] = 1 - mx.second;
    }
    return result;
}

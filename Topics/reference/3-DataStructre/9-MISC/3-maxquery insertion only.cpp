struct maxquery {
    mi mp;
    // find greatest value at index i <= x
    ll query(ll x) {
        auto it = mp.upper_bound(x);
        if (it == mp.begin()) return 0;
        it--;
        return it->second;
    }
    // insert valye v at index x
    void insert(ll x, ll v) {
        if (query(x) >= v) return;
        auto it = mp.insert({x, v}).first;
        it->second = v;
        while (next(it) != mp.end() && v >= next(it)->second) mp.erase(next(it));
    }
};

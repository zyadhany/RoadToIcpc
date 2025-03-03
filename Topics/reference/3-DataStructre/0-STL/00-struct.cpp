struct edge {
    ll u, v, w;
    edge (ll u, ll v, ll w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator<(const edge& e) {
        return w < e.w;
    }
};

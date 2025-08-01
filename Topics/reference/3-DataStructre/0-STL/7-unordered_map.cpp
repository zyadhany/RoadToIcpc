struct hsh {
    size_t operator()(const pl &p) const {
        return p.first * 239 + p.second;
    }
}; 
unordered_map<pl, ll, hsh> M;

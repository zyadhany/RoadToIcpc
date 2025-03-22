struct hsh {
    size_t operator()(const p   l &p) const {
        return p.first * 239 + p.second;
    }
}; 
unordered_map<pl, ll, hsh> M;
// array: sort(arr, arr + n);
// vector: sort(vec.begin(), vec.end());
// vector reverse: sort(vec.rbegin(), vec.rend());

// sort struct
struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

// Compare Function
//sort(v.begin(), v.end(), comp);
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

sort(E.begin(), E.end(), [&](edg &a, edg &b) {
    return a.a * b.b > a.b * b.a;
});

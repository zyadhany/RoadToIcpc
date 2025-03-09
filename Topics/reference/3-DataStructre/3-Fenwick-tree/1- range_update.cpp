// Range Update and Range Query using Two Fenwick Trees (BIT)
// Supports range increment and range sum queries efficiently.

void add(vector<long long>& b, int idx, long long x) {
    for (; idx <= N; idx += idx & -idx)
        b[idx] += x;
}

long long sum(const vector<long long>& b, int idx) {
    long long total = 0;
    for (; idx > 0; idx -= idx & -idx)
        total += b[idx];
    return total;
}

void range_add(int l, int r, long long x) {
    add(B1, l, x);
    add(B1, r + 1, -x);
    add(B2, l, x * (l - 1));
    add(B2, r + 1, -x * r);
}

long long prefix_sum(int idx) {
    return sum(B1, idx) * idx - sum(B2, idx);
}

long long range_sum(int l, int r) {
    return prefix_sum(r) - prefix_sum(l - 1);
}

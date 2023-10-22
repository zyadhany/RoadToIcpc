int get(int k) {
    return get(0, 0, size - 1, k);
}

int get(int m, int lx, int rx, int k) {
    if (lx == rx)
        return (lx);

    int mid = (lx + rx) / 2, s1, s2;
    s1 = tree[m * 2 + 1];
    s2 = tree[m * 2 + 2];

    if (s1 >= k)
        return (get(m * 2 + 1, lx, mid, k));
    return (get(m * 2 + 2, mid + 1, rx, k - s1));
}

/*I can use it to get first element greater than or equal k*/
int get(int m, int lx, int rx, int k) {
    if (tree[m] < k) return (-1);
    if (lx == rx)
        return (lx);

    int mid = (lx + rx) / 2, s1, s2;
    s1 = tree[m * 2 + 1];
    s2 = tree[m * 2 + 2];

    if (s1 >= k)
        return (get(m * 2 + 1, lx, mid, k));
    return (get(m * 2 + 2, mid + 1, rx, k));
}
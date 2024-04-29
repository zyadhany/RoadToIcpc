class SegmentTree
{
public:

    ll getrange(int l, int r, ll k) {
        return (getrange(0, 0, size - 1, l, r, k));
    }

    void build(vi& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());
        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;
    vector<long long> lazy;

    ll getitemval(item& a, ll k) {
        ll l;
        l = lower_bound(all(a.arr), k) - a.arr.begin();
        return (a.pref[l]);
    }

    item merge(item& a, item& b) {
        item res = a;
        for (int i = 0; i < b.arr.size(); i++)
            res.arr.push_back(b.arr[i]);
        sortx(res.arr);

        res.pref.assign(res.arr.size() + 1, 0);

        for (int i = 1; i <= res.arr.size(); i++)
            res.pref[i] = res.pref[i - 1] + res.arr[i - 1];

        return (res);
    }


    ll getrange(int m, int lx, int rx, int l, int r, ll k) {
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (getitemval(tree[m], k));

        int mid = (lx + rx) / 2;
        ll s1, s2, res;

        s1 = getrange(m * 2 + 1, lx, mid, l, r, k);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r, k);

        return (s1 + s2);
    }

    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size())
                tree[m].arr.push_back(X[lx]), tree[m].pref.push_back(X[lx]);
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }
};

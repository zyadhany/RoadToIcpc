struct item
{
    ll val, mx, l, r;
    item(){
        val = mx = l = r = 0;
    }

    item(ll n){
        val = mx = l = r = max(n, 0ll);
        val = n;
    }
};

class SegmentTree
{
public:

    void set(int index, int value) {
        set(0, 0, size - 1, index, value);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(vector<ll>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, item());

        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;

    item merge(item a, item b) {
        item res;
        res.l = max(a.l, a.val + b.l);
        res.r = max(b.r, b.val + a.r);
        res.val = a.val + b.val;

        res.mx = max(res.l, res.r);
        res.mx = max(res.mx, a.r + b.l);
        res.mx = max(res.mx, max(a.mx, b.mx));

        return (res);
    }


    void set(int m, int lx, int rx, int pos, int val) {
        if (pos < lx || rx < pos) return;
        if (lx == rx && lx == pos)
        {
            tree[m] = val;
            return;
        }

        int mid = (lx + rx) / 2;
        item s1, s2;

        set(m * 2 + 1, lx, mid, pos, val);
        set(m * 2 + 2, mid + 1, rx, pos, val);
        s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];

        tree[m] = merge(s1, s2);
    }

    item getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return (0);
        if (l <= lx && rx <= r) return (tree[m]);

        int mid = (lx + rx) / 2;
        item s1, s2;

        s1 = getrange(m * 2 + 1, lx, mid, l, r);
        s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);

        return merge(s1, s2);
    }

    void build(vector<ll>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = item(X[lx]);
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

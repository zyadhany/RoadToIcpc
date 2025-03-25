
const long long INF = 1e18;
struct item
{
    multiset<ll> st;

    item() {
    }
};

class SegmentTree
{
public:

    ll getrange(int l, int r, ll k) {
        return (getrange(0, 0, size - 1, l, r, k));
    }

    void set(int ind, ll val) {
        set(0, 0, size - 1, ind, val);
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

    ll getitemval(item& a, ll k) {
        auto it = a.st.lower_bound(k);
        if (it == a.st.end()) return (INF);
        return (*it);
    }

    item merge(item& a, item& b) {
        item res = a;
        b.st.insert(all(b.st));
        return (res);
    }

    void set(int m, int lx, int rx, int ind, ll val) {
        if (lx <= ind && ind <= rx) {
            // wrong you need erase old value
            tree[m].st.erase(tree[m].st.find(val));
            tree[m].st.insert(val);
        }
        if (lx == rx) return;
        if (ind <= (lx + rx) / 2)
            set(m * 2 + 1, lx, (lx + rx) / 2, ind, val);
        else
            set(m * 2 + 2, (lx + rx) / 2 + 1, rx, ind, val);
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
                tree[m].st.insert(X[lx]);
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

/**
 * usage:-
 * creat tree element.
 * SegmentTree sg;
 * 
 * Functions you can use:
 * @set: set index to value.
 * @get: get element at K_th position.
 * @geteange: get summ of given range.
 * @build: build tree with given vector.
 * 
 * make sure to look at item typedef.
 * you can change merge function to change it's oppration.
*/

typedef long long item;

class SegmentTree
{
public:

    void set(int index, int value) {
        set(0, 0, size - 1, index, value);
    }

    item get(int k) {
        return get(k, 0, 0, size - 1);
    }

    item getrange(int l, int r) {
        return (getrange(0, 0, size - 1, l, r));
    }

    void build(int n) {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, item());
    }

    void build(vector<item>& X) {
        size = 1;
        while (size < X.size())
            size *= 2;
        tree.assign(size * 2, 0);

        build(X, 0, 0, size - 1);
    }

private:
    int size;
    vector<item> tree;

    item merge(item a, item b) {
        return (a + b);
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

    item get(int k, int m, int lx, int rx) {
        if (lx == rx)
            return (lx);
        
        int mid = (lx + rx) / 2;
        item s1, s2;
        s1 = tree[m * 2 + 1];
        s2 = tree[m * 2 + 2];

        if (s1 >= k)
            return (get(k, m * 2 + 1, lx, mid));
        return (get(k - s1, m * 2 + 2, mid + 1, rx));
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

    void build(vector<item>& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = X[lx];
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

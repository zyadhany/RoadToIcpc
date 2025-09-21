/*
0. l r x -> for i in [l,r], a[i] = min(a[i], x)
1. l r x -> for i in [l,r], a[i] = max(a[i], x)
2. l r x -> for i in [l,r], a[i] = a[i] + x
3. l r -> sum from l to r
*/
const ll INF = 1e16;
struct item
{
    ll summ, lazy;
    ll mx, smx, cmx;
    ll mn, smn, cmn;
    item(){
        lazy = summ = 0;
        mx = smx = -INF; cmx = 0;
        mn = smn = INF; cmn = 0;        
    }
    item(ll x) {
        lazy = 0;
        summ = mn = mx = x;
        smx = -INF; cmx = 1;
        smn = INF; cmn = 1;
    }
};
struct SegmentTree
{
    int size;
    vector<item> tree;
    SegmentTree(){};
    
    item merge(item &a, item &b) {
        item res;
        if (a.mx == b.mx) {
            res.mx = a.mx;
            res.cmx = a.cmx + b.cmx;
            res.smx = max(a.smx, b.smx);
        } else if (a.mx > b.mx) {
            res.mx = a.mx;
            res.cmx = a.cmx;
            res.smx = max(a.smx, b.mx);
        } else {
            res.mx = b.mx;
            res.cmx = b.cmx;
            res.smx = max(b.smx, a.mx);
        }

        if (a.mn == b.mn) {
            res.mn = a.mn;
            res.cmn = a.cmn + b.cmn;
            res.smn = min(a.smn, b.smn);
        } else if (a.mn < b.mn) {
            res.mn = a.mn;
            res.cmn = a.cmn;
            res.smn = min(a.smn, b.mn);
        } else {
            res.mn = b.mn;
            res.cmn = b.cmn;
            res.smn = min(b.smn, a.mn);
        }

        res.summ = a.summ + b.summ;
        return (res);
    }

    void pushsumm(int m, ll lx, ll rx, ll v) {
        if (!v) return;
        tree[m].summ += (rx-lx+1) * v;
        tree[m].mx += v;
        if (tree[m].smx != -INF) tree[m].smx += v;
        tree[m].mn += v;
        if (tree[m].smn != INF) tree[m].smn += v;
        if (rx!=lx) {
            tree[m].lazy += v;
        }
    }

    void pushmax(int m, ll v, bool leaf = false) {
        if (v >= tree[m].mx) return;
        tree[m].summ -= tree[m].cmx * (tree[m].mx-v);
        tree[m].mx = v;
        if (leaf) tree[m].mn = tree[m].mx;
        else if (v <= tree[m].mn) tree[m].mn = v;
        else if (v < tree[m].smn) tree[m].smn = v;
    }

    void pushmin(int m, ll v, bool leaf = false) {
        if (v <= tree[m].mn) return;
        tree[m].summ -= tree[m].cmn * (tree[m].mn-v);
        tree[m].mn = v;
        if (leaf) tree[m].mx = tree[m].mn;
        else if (v >= tree[m].mx) tree[m].mx = v;
        else if (v > tree[m].smx) tree[m].smx = v;
    }

    void pushdown(int m, int lx, int rx) {
        if (lx == rx) return;

        ll mid = (lx+rx)/2;
        pushsumm(m*2+1, lx, mid, tree[m].lazy);
        pushsumm(m*2+2, mid+1, rx, tree[m].lazy);
        tree[m].lazy = 0;

        pushmax(m*2+1, tree[m].mx, lx==mid);
        pushmax(m*2+2, tree[m].mx, mid+1==rx);

        pushmin(m*2+1, tree[m].mn, lx==mid);
        pushmin(m*2+2, tree[m].mn, mid+1==rx);
    }

    void set(int ind, ll value) {set(0, 0, size - 1, ind, value);}
    void set(int m, int lx, int rx, int ind, ll val) {
        if (rx < ind || ind < lx) return; // break condtion
        if (lx == rx) // tag condtion
        {
            tree[m] = item(val);
            return;
        }
        pushdown(m, lx, rx);
        int mid = (lx + rx) / 2;
        set(m * 2 + 1, lx, mid, ind, val);
        set(m * 2 + 2, mid + 1, rx, ind, val);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }

    void setmin(int l, int r, ll value) {setmin(0, 0, size - 1, l, r, value);}
    void setmin(int m, int lx, int rx, int l, int r, ll val) {
        if (rx < l || r < lx || tree[m].mx <= val) return; // break condtion
        if (l <= lx && rx <= r && tree[m].smx < val) // tag condtion
        {
            pushmax(m, val);
            return;
        }
        pushdown(m, lx, rx);
        int mid = (lx + rx) / 2;
        setmin(m * 2 + 1, lx, mid, l, r, val);
        setmin(m * 2 + 2, mid + 1, rx, l, r, val);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }

    void setmax(int l, int r, ll value) {setmax(0, 0, size - 1, l, r, value);}
    void setmax(int m, int lx, int rx, int l, int r, ll val) {
        if (rx < l || r < lx || tree[m].mn >= val) return; // break condtion
        if (l <= lx && rx <= r && tree[m].smn > val) // tag condtion
        {
            pushmin(m, val);
            return;
        }
        pushdown(m, lx, rx);
        int mid = (lx + rx) / 2;
        setmax(m * 2 + 1, lx, mid, l, r, val);
        setmax(m * 2 + 2, mid + 1, rx, l, r, val);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }

    void addrange(int l, int r, ll value) {addrange(0, 0, size - 1, l, r, value);}
    void addrange(int m, int lx, int rx, int l, int r, ll val) {
        if (rx < l || r < lx) return; // break condtion
        if (l <= lx && rx <= r) // tag condtion
        {
            pushsumm(m, lx, rx, val);
            return;
        }
        pushdown(m, lx, rx);
        int mid = (lx + rx) / 2;
        addrange(m * 2 + 1, lx, mid, l, r, val);
        addrange(m * 2 + 2, mid + 1, rx, l, r, val);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }

    item getrange(int l, int r) { return (getrange(0, 0, size - 1, l, r));}
    item getrange(int m, int lx, int rx, int l, int r) {
        if (rx < l || r < lx) return item();
        if (l <= lx && rx <= r) return (tree[m]);
        pushdown(m, lx, rx);
        int mid = (lx + rx) / 2;
        item s1 = getrange(m * 2 + 1, lx, mid, l, r);
        item s2 = getrange(m * 2 + 2, mid + 1, rx, l, r);
        return merge(s1, s2);
    }

    void build(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(size * 2, item());
    }
    void build(vi& X) {
        size = 1;
        while (size < X.size()) size *= 2;
        tree.assign(size * 2, item());
        build(X, 0, 0, size - 1);
    }
    void build(vi& X, int m, int lx, int rx) {
        if (lx == rx) {
            if (lx < X.size()) tree[m] = item(X[lx]);
            return;
        }
        int mid = (lx + rx) / 2;
        build(X, m * 2 + 1, lx, mid);
        build(X, m * 2 + 2, mid + 1, rx);
        tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
    }
};

void solve() {
    ll n, q; cin >> n >> q;

    vi X(n);
    for (int i = 0; i < n; i++) cin >> X[i];    
    SegmentTree sg;
    sg.build(X);

    while (q--)
    {
        ll ty, l, r; cin >> ty >> l >> r;
        r--;
        if (ty == 0) {
            ll x; cin >> x;
            sg.setmin(l, r, x);
        } else if (ty == 1) {
            ll x; cin >> x;
            sg.setmax(l, r, x);
        } else if (ty == 2) {
            ll x; cin >> x;
            sg.addrange(l, r, x);
        } else {
            cout << sg.getrange(l, r).summ << '\n';            
        }
    }    
}

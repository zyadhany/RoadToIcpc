const int N = 1e6 + 9;

typedef ll item;
const item neutral = 0;
struct PST {
#define lc tree[cur].l
#define rc tree[cur].r
    struct node {
        int l = 0, r = 0;
        ll lazy = 0;
        item val = neutral;
    } tree[20 * N];
    int T = 0;
    
    item marge(item a, item b) {
        return a + b;
    }
    ll push(int pre, ll b, ll e, ll v=neutral) {
        int cur = ++T;
        tree[cur] = tree[pre];
        tree[cur].lazy += v;
        if (tree[cur].lazy != neutral) {
            tree[cur].val += (e - b + 1) * tree[cur].lazy;
            if (b != e) {
                lc = ++T;
                rc = ++T;
                tree[lc] = tree[tree[pre].l];
                tree[rc] = tree[tree[pre].r];
                tree[lc].lazy += tree[cur].lazy;
                tree[rc].lazy += tree[cur].lazy;
            }
        }
        tree[cur].lazy = neutral;
        return cur;
    }
    int build(int b, int e, vi &X) {
        int cur = ++T;
        if(b == e) {
            if (b < X.size()) tree[cur].val = item(X[b]);
            else tree[cur].val = neutral;
            return cur;
        }
        int mid = b + e >> 1;
        lc = build(b, mid, X);
        rc = build(mid + 1, e, X);
        tree[cur].val = marge(tree[lc].val, tree[rc].val);
        return cur;
    }
    int upd(int pre, int b, int e, ll l, ll r, item v) {
        int cur = push(pre, b, e);
        if (b > r || e < l) return cur;
        if (b >= l && e <= r) {
            cur = push(cur, b, e, v);
            return cur;
        }
        int mid = b + e >> 1;
        lc = upd(lc, b, mid, l, r, v);
        rc = upd(rc, mid + 1, e, l, r, v);
        tree[cur].val = marge(tree[lc].val, tree[rc].val);
        return cur;
    }

    ll query(int cur, int b, int e, int l, int r) {
        int stt = T;
        cur = push(cur, b, e);
        if (e < l || b > r) return neutral;
        if (b >= l && e <= r) return tree[cur].val;
        int mid = b + e >> 1;
        item res =  marge(query(lc, b, mid, l,r), query(rc, mid+1, e, l,r));
        T = stt;
        return res;
    }
};

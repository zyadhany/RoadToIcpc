const int N = 4e5 + 9;

typedef ll item;
const item neutral = 0;
struct PST {
#define lc tree[cur].l
#define rc tree[cur].r
  struct node {
    int l = 0, r = 0;
    item val = neutral;
  } tree[20 * N];
  
  item marge(item a, item b) {
    return a + b;
  }
  int T = 0;
  int build(int b, int e, vi &X) {
    int cur = ++T;
    if(b == e) {
        if (b < X.size()) tree[cur].val = X[b];
        else tree[cur].val = neutral;
        return cur;
    }
    int mid = b + e >> 1;
    lc = build(b, mid, X);
    rc = build(mid + 1, e, X);
    tree[cur].val = marge(tree[lc].val, tree[rc].val);
    return cur;
  }
  int upd(int pre, int b, int e, int i, item v) {
    int cur = ++T;
    tree[cur] = tree[pre];
    if(b == e) {
      tree[cur].val = v;
      return cur;
    }
    int mid = b + e >> 1;
    if(i <= mid) {
      rc = tree[pre].r;
      lc = upd(tree[pre].l, b, mid, i, v);
    } else {
      lc = tree[pre].l;
      rc = upd(tree[pre].r, mid + 1, e, i, v);
    }
    tree[cur].val = marge(tree[lc].val, tree[rc].val);
    return cur;
  }

  ll query(int pre, int b, int e, int l, int r) {
    if (e < l || b > r) return neutral;
    if (b >= l && e <= r) return tree[pre].val;
    int mid = b + e >> 1;
    return marge(query(tree[pre].l, b, mid, l,r), query(tree[pre].r, mid+1, e, l,r));
  }
};



int query(int pre, int cur, int b, int e, int k) {
  if(b == e) return b;
  int cnt = t[lc].val - t[t[pre].l].val;
  int mid = b + e >> 1;
  if(cnt >= k) return query(t[pre].l, lc, b, mid, k);
  else return query(t[pre].r, rc, mid + 1, e, k - cnt);
}
//the code returns k-th number in a range l to r if the range were sorted
int V[N], root[N], a[N];
int32_t main() {
  map<int, int>mp;
  int n, q;
  cin >> n >> q;
  for(int i = 1; i <= n; i++) cin >> a[i], mp[a[i]];
  int c = 0;
  for(auto x : mp) mp[x.first] = ++c, V[c] = x.first;
  root[0] = t.build(1, n);
  for(int i = 1; i <= n; i++) {
    root[i] = t.upd(root[i - 1], 1, n, mp[a[i]], 1);
  }
  while(q--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << V[t.query(root[l - 1], root[r], 1, n, k)] << '\n';
  }
  return 0;
}
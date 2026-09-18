const int N = 5e5 + 9;


typedef pl item;
const item neutral = {N+10, 0};

struct node {
  node *l = nullptr, *r = nullptr;
  item val = neutral;
};
struct PST {
  
  item marge(item a, item b) {
    return min(a, b);
  }

  node* build(int b, int e) {
    node* cur = new node();
    if(b == e) {
        cur->val = {N+10, e};
        return cur;
    }
    int mid = b + e >> 1;
    cur->l = build(b, mid);
    cur->r = build(mid + 1, e);
    cur->val = marge(cur->l->val, cur->r->val);
    return cur;
  }
  
  node* upd(node* pre, int b, int e, int i, ll v) {
    node* cur = new node(*pre);
    if(b == e) {
        cur->val = {v, e};
        return cur;
    }
    int mid = b + e >> 1;
    if(i <= mid) {
      cur->l = upd(pre->l, b, mid, i, v);
    } else {
      cur->r = upd(pre->r, mid + 1, e, i, v);
    }
    cur->val = marge(cur->l->val, cur->r->val);
    return cur;
  }

  item query(node* pre, int b, int e, int l, int r) {
    if (!pre || e < l || b > r) return neutral;
    if (b >= l && e <= r) return pre->val;
    int mid = b + e >> 1;
    return marge(query(pre->l, b, mid, l, r), query(pre->r, mid + 1, e, l, r));
  }
};

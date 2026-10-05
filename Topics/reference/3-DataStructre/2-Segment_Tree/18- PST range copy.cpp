const int N = 5e5 + 9;


typedef ll item;
const item neutral = 0;

struct node {
    node *l = nullptr, *r = nullptr;
    item val = neutral;

};

struct PST {
  item marge(node *a, node *b) {
    item ret = neutral;
    if (a) ret += a->val;
    if (b) ret += b->val;
    return ret;
  }

  node* build(int b, int e) {
    node* cur = new node();
    if(b == e) {
        cur->val = 1;
        return cur;
    }
    int mid = b + e >> 1;
    cur->l = build(b, mid);
    cur->r = build(mid + 1, e);
    cur->val = marge(cur->l, cur->r);
    return cur;
  }
  
  node* upd(node* pre, int b, int e, int i, ll v) {
    node* cur = new node(*pre);
    if(b == e) {
        cur->val += v;
        return cur;
    }
    int mid = b + e >> 1;
    if(i <= mid) {
      cur->l = upd(pre->l, b, mid, i, v);
    } else {
      cur->r = upd(pre->r, mid + 1, e, i, v);
    }
    cur->val = marge(cur->l, cur->r);
    return cur;
  }

  node* copy(node* pre, node *next, int b, int e, int l, int r) {
    if (!pre || e < l || b > r) return next;
    if (b >= l && e <= r) {
        return pre;
    }
    node *cur;
    if (next) cur = new node(*next);
    else cur = new node();
    
    int mid = b + e >> 1;
    cur->l = copy(pre->l, cur->l, b, mid, l, r);
    cur->r = copy(pre->r, cur->r, mid+1, e, l, r);
    cur->val = marge(cur->l, cur->r);
    return cur;
  }

  item query(node* pre, int b, int e, int l, int r) {
    if (!pre || e < l || b > r) return neutral;
    if (b >= l && e <= r) return pre->val;
    int mid = b + e >> 1;
    return (query(pre->l, b, mid, l, r) + query(pre->r, mid + 1, e, l, r));
  }
};
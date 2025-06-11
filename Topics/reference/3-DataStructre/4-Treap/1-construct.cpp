mt19937 rnd((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    bool rev;
    pitem l, r;
	item(int value) : prior(rnd()), value(value), cnt(1), rev(false), l(NULL), r(NULL) {}
};

int count (pitem it) {
    return it ? it->cnt : 0;
}

void recalc (pitem it) {
    if (it)
        it->cnt = count(it->l) + count(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    recalc (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + count(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + count(t->l)),  l = t;
    recalc (t);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

int kth (pitem t, int k) {
	push(t);
	int cur_key = count(t->l);
	if (k < cur_key)
		return kth(t->l, k);
	else if (k > cur_key)
		return kth(t->r, k - cur_key - 1);
	else
		return t->value;
}

int order_of_key (pitem t, int value) {
	if (!t)
		return 0;
	push(t);
	if (value <= t->value)
		return order_of_key(t->l, value);
	else
		return count(t->l) + 1 + order_of_key(t->r, value);
}

void insert (pitem & t, int value) {
	pitem it = new item(value);
	pitem l, r;
	split(t, l, r, order_of_key(t, value));
	merge(t, l, it);
	merge(t, t, r);
}

void erase(pitem & t, int value) {
	pitem l, r, tm;
	split(t, l, r, order_of_key(t, value));
	split(r, tm, r, 1);
	delete tm;	
	merge(t, l, r);
}

void heapify (pitem t) {
    if (!t) return;
    pitem max = t;
    if (t->l != NULL && t->l->prior > max->prior)
        max = t->l;
    if (t->r != NULL && t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap (t->prior, max->prior);
        heapify (max);
    }
}

// build X.begin()
pitem build (vi::iterator X, int n) {
    // Construct a treap on values {a[0], a[1], ..., a[n - 1]}
    if (n == 0) return NULL;
    int mid = n / 2;
    pitem t = new item (X[mid]);
    t->l = build (X, mid);
    t->r = build (X + mid + 1, n - mid - 1);
    heapify (t);
    recalc(t);
    return t;
}

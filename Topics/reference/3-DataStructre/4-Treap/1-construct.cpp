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

void apply_lazy(pitem it, bool rev) {
    if (!it) return;
    if (rev) swap (it->l, it->r);
    it->rev ^= rev;
}

void push (pitem it) {
    if (!it) return;
    if (it->rev) {
        apply_lazy(it->l, true);
        apply_lazy(it->r, true);
        it->rev = false;
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
    apply_lazy(t2, 1);
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

ll query (pitem t, int l, int r) {
    pitem t1, t2, t3; t1 = t2 = t3 = nullptr;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    // ll ret = getsum(t2);
    merge (t, t1, t2);
    merge (t, t, t3);
    return ret;
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

void falt_treap(pitem it, vi &X) {
    if (!it) return;
    falt_treap(it->l, X);
    X.push_back(it->value);
    falt_treap(it->r, X);
}



void splitbyvalue(pitem t, pitem & l, pitem & r, int value) {
    if (!t) {
        l = r = nullptr;
        return;
    }
    push(t);
    if (t->value <= value) {
        splitbyvalue(t->r, t->r, r, value);
        l = t;
    } else {
        splitbyvalue(t->l, l, t->l, value);
        r = t;
    }
    recalc(t);
}
// unite 2 treap in O(M*log(N/M)) where M,N size of 2 treaps
pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    push(l);
    pitem lt, rt;
    splitbyvalue (r, lt, rt, l->value);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    recalc(l);
    return l;
}

/*
    to get pointer for parent

void recalc (pitem it) {
    if (it) {
        if (it->l) it->l->p = it;
        if (it->r) it->r->p = it;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    ....
    t->p = nullptr;
    recalc (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    .....
    t->p = nullptr;
    recalc (t);
}

pitem getroot(pitem it) {
    if (!it) return nullptr;
    while (it->p) {
        it = it->p;
    }
    return it;
}
*/
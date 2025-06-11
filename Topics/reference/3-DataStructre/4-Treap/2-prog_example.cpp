/*
    given array and 5 type of queries:
    0 i x: insert x at index i
    1 i: erase element at index i
    2 l r: reverse elements from index l to r
    3 l r a b: for i from l to r-1, set a[i] = (a[i] * a + b) % MODE
    4 l r: print sum of elements from index l to r-1
    all queries are 0-indexed
*/

const int MODE = 998244353;

mt19937 rnd((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef struct item * pitem;
struct item {
    int prior, cnt;
	ll summ, value;
	pl prob;
    bool rev;
    pitem l, r;
	item(int value) : prior(rnd()), value(value), cnt(1), rev(false), l(NULL), r(NULL), prob({1, 0}) {
		summ = value;
	} 
};

int count (pitem it) {
    return it ? it->cnt : 0;
}

int getsumm (pitem it) {
    return it ? it->summ : 0;
}

void push (pitem it) {
    if (it) {
		if (it->rev) {
			it->rev = false;
			swap (it->l, it->r);
			if (it->l)  it->l->rev ^= true;
			if (it->r)  it->r->rev ^= true;
		}
		if (it->prob != pl(1, 0)) {
			it->value = (it->value * it->prob.first + it->prob.second) % MODE;
			it->summ = (it->summ * it->prob.first + it->prob.second * count(it)) % MODE;
			if (it->l)  {
				it->l->prob.first *= it->prob.first;
				it->l->prob.first %= MODE;
				it->l->prob.second = (it->l->prob.second * it->prob.first + it->prob.second) % MODE;
			}
			if (it->r)  {
				it->r->prob.first *= it->prob.first;
				it->r->prob.first %= MODE;
				it->r->prob.second = (it->r->prob.second * it->prob.first + it->prob.second) % MODE;
			}
			it->prob = pl(1, 0);
		}
    }
}

void recalc (pitem it) {
    if (it) {
		push(it->l); push(it->r);
        it->cnt = count(it->l) + count(it->r) + 1;
		it->summ = (it->value + getsumm(it->l) + getsumm(it->r)) % MODE;
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

void add (pitem t, int l, int r, ll a, ll b) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
	t2->prob = pl(a, b);
    merge (t, t1, t2);
    merge (t, t, t3);
}

ll query (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    ll v = getsumm(t2);
    merge (t, t1, t2);
    merge (t, t, t3);
	return v;
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

void insert (pitem & t, int value, int ind) {
	pitem it = new item(value);
	pitem l, r;
	split(t, l, r, ind);
	merge(t, l, it);
	merge(t, t, r);
}

void erase(pitem & t, int ind) {
	pitem l, r, tm;
	split(t, l, r, ind);
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

void solve(int tc) {
	ll n, q;
	cin >> n >> q;

	vi X(n);
	for (int i = 0; i < n; i++)
	{
		cin >> X[i];
	}
	
	auto t = build(X.begin(), n);

	while (q--)
	{
		ll ty; cin >> ty;
		if (ty == 0) {
			ll i, x; cin >> i >> x;
			insert(t, x, i);
		} else if (ty == 1) {
			ll i; cin >> i;
			erase(t, i);
		} else if (ty == 2) {
			ll l, r; cin >> l >> r;
			reverse(t, l, r-1);
		} else if (ty == 3) {
			ll l, r, a, b;
			cin >> l >> r >> a >> b;
			add(t, l, r-1, a, b);
		} else {
			ll l, r; cin >> l >> r;
			cout << query(t, l, r-1) << '\n';
		}
	}
}

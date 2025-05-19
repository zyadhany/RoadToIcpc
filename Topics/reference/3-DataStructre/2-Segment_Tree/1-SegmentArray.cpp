
typedef pl item;

int sgsz;
const int MXSG = 5e6;
item tree[MXSG];
ll lazy[MXSG];

item merge(item &a, item &b) {
	item res = a;
	if (a.first == b.first) res.second += b.second;
	else if (a.first > b.first) res = b;
	return (res);
}

void checkLazy(int m, int lx, int rx) {
	if (!lazy[m]) return;
	tree[m].first += lazy[m];
	if (lx != rx) {
		lazy[2 * m + 1] += lazy[m];
		lazy[2 * m + 2] += lazy[m];
	}
	lazy[m] = 0;
}

void update(ll l, ll r, ll val, int m=0, int lx=0, int rx=sgsz-1) {
	checkLazy(m, lx, rx);
	if (rx < l || r < lx) return;
	if (l <= lx && rx <= r)
	{
		lazy[m] = val;
		checkLazy(m, lx, rx);
		return;
	}
	int mid = (lx + rx) / 2;
	update(l, r, val, m * 2 + 1, lx, mid);
	update(l, r, val, m * 2 + 2, mid + 1, rx);
	tree[m] = merge(tree[m * 2 + 1], tree[m * 2 + 2]);
}

item getrange(int l, int r, int m=0, int lx=0, int rx=sgsz-1) {
	checkLazy(m, lx, rx);
	if (rx < l || r < lx) return {INT32_MAX, 0};
	if (l <= lx && rx <= r) return (tree[m]);
	int mid = (lx + rx) / 2;
	item s1, s2;
	s1 = getrange(l, r, m * 2 + 1, lx, mid);
	s2 = getrange(l, r, m * 2 + 2, mid + 1, rx);
	return merge(s1, s2);
}

void build(int m=0, int lx=0, int rx=sgsz-1) {
	if (lx == rx) {
		tree[m] = {0, 1};
		return;
	}
	int mid = (lx + rx) / 2;
	item s1, s2;
	build(m * 2 + 1, lx, mid);
	build(m * 2 + 2, mid + 1, rx);
	s1 = tree[m * 2 + 1], s2 = tree[m * 2 + 2];
	tree[m] = merge(s1, s2);
}
 
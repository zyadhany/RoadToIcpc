
class SparseSegtree {
  private:
  typedef ll item;
	struct Node {
		item val = 0;
		ll lazy = 0;
		int left = -1;
		int right = -1;
	};
	vector<Node> tree;
	const int n;
	int timer = 0;

	item comb(item a, item b) { return a + b; }

	void apply(ll cur, ll len, ll laz) {
		if (!laz) return;
        tree[cur].lazy += laz;
        tree[cur].val += len * laz;
	}

	void push_down(int cur, int l, int r) {
		if (tree[cur].left == -1) {
			tree[cur].left = ++timer;
			tree.push_back(Node());
		}
		if (tree[cur].right == -1) {
			tree[cur].right = ++timer;
			tree.push_back(Node());
		}
		int m = (l + r) / 2;
		apply(tree[cur].left, m - l + 1, tree[cur].lazy);
		apply(tree[cur].right, r - m, tree[cur].lazy);
		tree[cur].lazy = 0;
	}

	void range_set(int cur, int l, int r, int ql, int qr, ll val) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
			apply(cur, r - l + 1, val);
		} else {
			push_down(cur, l, r);
			int m = (l + r) / 2;
			range_set(tree[cur].left, l, m, ql, qr, val);
			range_set(tree[cur].right, m + 1, r, ql, qr, val);
			tree[cur].val =
			    comb(tree[tree[cur].left].val, tree[tree[cur].right].val);
		}
	}

	item range_sum(int cur, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) { return item(); }
		if (ql <= l && r <= qr) { return tree[cur].val; }
		push_down(cur, l, r);
		int m = (l + r) / 2;
		return comb(range_sum(tree[cur].left, l, m, ql, qr),
		            range_sum(tree[cur].right, m + 1, r, ql, qr));
	}

    // last index such summ from 0 -> ind > k, upper pound
    ll get(int cur, int l, int r, ll k) {
        if (l == r) return l;
        push_down(cur, l, r);
        int m = (l + r) / 2;
        push_down(tree[cur].left, l, m);
        push_down(tree[cur].right, m+1, r);
        if (tree[tree[cur].left].val <= k) return get(tree[cur].right, m+1, r, k - tree[tree[cur].left].val);
        return get(tree[cur].left, l, m, k);
    }

  public:
	SparseSegtree(int n, int q = 0) : n(n) {
		if (q > 0) { tree.reserve(2 * q * (int)log2(n)); }
		tree.push_back(Node());
	}

	void range_set(int ql, int qr, ll val) { range_set(0, 0, n - 1, ql, qr, val); }

	item range_sum(int ql, int qr) { return range_sum(0, 0, n - 1, ql, qr); }

    ll get(ll k) {return get(0, 0, n-1, k);}
};

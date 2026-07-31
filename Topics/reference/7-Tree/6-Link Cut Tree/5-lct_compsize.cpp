// work with 1-indexed nodes
struct LCT {
	struct Node {
		int p = 0, ch[2] = {0, 0};
		int sz = 1, vir = 0;
		bool rev = false;
	};

	vector<Node> t;

	LCT(int n = 0) {
        t.resize(n + 1);
        t[0].sz = 0;
	}

	bool is_root(int x) {
		return !t[x].p || (t[t[x].p].ch[0] != x && t[t[x].p].ch[1] != x);
	}

	void push(int x) {
		if (t[x].rev) {
			swap(t[x].ch[0], t[x].ch[1]);
			if (t[x].ch[0]) t[t[x].ch[0]].rev ^= 1;
			if (t[x].ch[1]) t[t[x].ch[1]].rev ^= 1;
			t[x].rev = false;
		}
	}

	void pull(int x) {
		t[x].sz = 1 + t[x].vir + t[t[x].ch[0]].sz + t[t[x].ch[1]].sz;
	}

	void rotate(int x) {
		int y = t[x].p, z = t[y].p;
		int k = (t[y].ch[1] == x);
		if (!is_root(y)) t[z].ch[t[z].ch[1] == y] = x;
		t[x].p = z;
		t[y].ch[k] = t[x].ch[k ^ 1];
		if (t[x].ch[k ^ 1]) t[t[x].ch[k ^ 1]].p = y;
		t[x].ch[k ^ 1] = y;
		t[y].p = x;
		pull(y);
		pull(x);
	}

	void splay(int x) {
		vector<int> stk;
		int curr = x;
		stk.push_back(curr);
		while (!is_root(curr)) {
			curr = t[curr].p;
			stk.push_back(curr);
		}
		while (!stk.empty()) {
			push(stk.back());
			stk.pop_back();
		}
		while (!is_root(x)) {
			int y = t[x].p, z = t[y].p;
			if (!is_root(y)) {
				if ((t[y].ch[1] == x) ^ (t[z].ch[1] == y)) rotate(x);
				else rotate(y);
			}
			rotate(x);
		}
	}

	int access(int x) {
		int last = 0;
		for (int v = x; v; v = t[v].p) {
			splay(v);
			t[v].vir += t[t[v].ch[1]].sz;
			t[v].vir -= t[last].sz;
			t[v].ch[1] = last;
			pull(v);
			last = v;
		}
		splay(x);
		return last;
	}

	void make_root(int x) {
		access(x);
		t[x].rev ^= 1;
		push(x);
	}

	int find_root(int x) {
		access(x);
		while (t[x].ch[0]) {
			push(x);
			x = t[x].ch[0];
		}
		splay(x);
		return x;
	}

	bool connected(int u, int v) {
		return find_root(u) == find_root(v);
	}

	void link(int u, int v) {
		make_root(u);
		if (find_root(v) == u) return;
		access(v);
		splay(v);
		t[u].p = v;
		t[v].vir += t[u].sz;
		pull(v);
	}

	void cut(int u, int v) {
		make_root(u);
		access(v);
		splay(v);
		if (t[v].ch[0] == u && !t[u].ch[1]) {
			t[v].ch[0] = 0;
			t[u].p = 0;
			pull(v);
		}
	}

	int component_size(int x) {
		make_root(x);
		return t[x].sz;
	}

	int subtree_size(int u, int r) {
		make_root(r);
		access(u);
		return 1 + t[u].vir;
	}
};
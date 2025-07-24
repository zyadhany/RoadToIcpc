struct LinkCutTree {
    struct Node {
        int p = -1, ch[2] = {-1, -1};
        bool rev = false;
        ll val = 0, sub = 0;

        void set(int d, int x) { ch[d] = x; }
        int get(int x) const { return ch[x]; }
    };

    vector<Node> T;

    LinkCutTree(int n) {
        T.resize(n);
    }

    bool is_root(int x) {
        int p = T[x].p;
        return p == -1 || (T[p].ch[0] != x && T[p].ch[1] != x);
    }

    void push(int x) {
        if (T[x].rev) {
            swap(T[x].ch[0], T[x].ch[1]);
            for (int d = 0; d < 2; d++)
                if (T[x].ch[d] != -1)
                    T[T[x].ch[d]].rev ^= 1;
            T[x].rev = 0;
        }
    }

    void pull(int x) {
        T[x].sub = T[x].val;
        for (int d = 0; d < 2; d++)
            if (T[x].ch[d] != -1)
                T[x].sub += T[T[x].ch[d]].sub;
    }

    int dir(int x) {
        int p = T[x].p;
        return T[p].ch[1] == x;
    }

    void rotate(int x) {
        int p = T[x].p, d = dir(x);
        int b = T[x].ch[d ^ 1];
        if (!is_root(p)) T[T[p].p].ch[dir(p)] = x;
        T[x].p = T[p].p;

        T[x].ch[d ^ 1] = p;
        T[p].p = x;

        T[p].ch[d] = b;
        if (b != -1) T[b].p = p;

        pull(p);
        pull(x);
    }

    void splay(int x) {
        vector<int> stk;
        for (int y = x; !is_root(y); y = T[y].p)
            stk.push_back(T[y].p);
        while (!stk.empty()) push(stk.back()), stk.pop_back();
        push(x);

        while (!is_root(x)) {
            int p = T[x].p;
            if (!is_root(p))
                rotate(dir(p) == dir(x) ? p : x);
            rotate(x);
        }
    }

    int access(int x) {
		int last = -1;
		for (int y = x; y != -1; y = T[y].p) {
			splay(y);
			T[y].ch[1] = last;
			pull(y);
			last = y;
		}
		splay(x);
		return last;
	}

    void make_root(int x) {
        access(x);
        T[x].rev ^= 1;
    }

    void link(int u, int v) {
        make_root(u);
        T[u].p = v;
    }

    void cut(int u, int v) {
        make_root(u);
        access(v);
        if (T[v].ch[0] == u && T[u].p == v) {
            T[v].ch[0] = -1;
            T[u].p = -1;
            pull(v);
        }
    }

	int lca(int u, int v) {
    	if (u == v) return u;
		access(u);
		return access(v);
	}

    ll query(int u, int v) {
        make_root(u);
        access(v);
        return T[v].sub;
    }

    void add(int u, ll x) {
        access(u);
        T[u].val += x;
        pull(u);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

	LinkCutTree lc(n);
    for (int i = 0; i < n; i++) {
        ll v;
        cin >> v;
		lc.add(i, v);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
		lc.link(u, v);
    }

    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            lc.cut(u, v);
            lc.link(w, x);
        } else if (t == 1) {
            int p; ll x;
            cin >> p >> x;
            lc.add(p, x);
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;
            cout << lc.query(u, v) << "\n";
        }
    }

    return 0;
}

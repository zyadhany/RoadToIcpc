	template < typename T = int , int Base = 0 > struct LCT {
    struct Node {
        T val;
        Node *l, *r, *p;
        bool rev;

        Node(T v = 0) : val(v), l(nullptr), r(nullptr), p(nullptr), rev(false) {}

        // get the index of the node
        void push() {
            if (rev) {
                rev = false;
                swap(l, r);
                if (l) l -> rev = !l -> rev;
                if (r) r -> rev = !r -> rev;
            }
        }

        // check if the node is the root of the tree
        bool is_root() { return p == nullptr || (p -> l != this && this != p -> r); }
    };

	vector < Node > nodes;

	LCT(int n = 0) : nodes(n + 5) {
        for(int i = 0; i <= n; i++) 
            nodes[i].val = i;
    }

    LCT(int n, const vector < T > &v) : nodes(n + 5) {
        for(int i = 1; i <= n; i++) 
            nodes[i].val = v[i - !Base];
    }

    // rotate the node
	void rotate(Node *c) {
		auto p = c -> p;
		auto g = p -> p;
		if (!p -> is_root()) (g -> r == p ? g -> r : g -> l) = c;
		p -> push(), c -> push();
		if (p -> l == c) {  // rtr
			p -> l = c -> r;
			c -> r = p;
			if (p -> l) p -> l -> p = p;
		} else {  // rtl
			p -> r = c -> l;
			c -> l = p;
			if (p -> r) p -> r -> p = p;
		}
		p -> p = c;
		c -> p = g;
	}

    // splay the node
	void splay(Node *c) {
		while (!c -> is_root()) {
			auto p = c -> p;
			auto g = p -> p;
			if (!p -> is_root()) rotate((g -> r == p) == (p -> r == c) ? p : c);
			rotate(c);
		}
		c -> push();
	}

    // access the node
	Node *access(int v) {
		Node *last = 0, *curr = &nodes[v];
		for (Node *p = curr; p; p = p -> p) {
			splay(p);
			p -> r = last;
			last = p;
		}
		splay(curr);
		return last;
	}

    // make the node the root of the tree
	void make_root(int v) {
		access(v);
		auto *c = &nodes[v];
		if (c -> l) c -> l -> rev ^= true, c -> l = nullptr;
	}

    // find the root of the tree
    int find_root(int v) {
        Node *curr = access(v);
        while (curr -> l) curr = curr -> l;
        access(curr -> val);
        return curr -> val;
    }

    // link the edge between u and v
	void link(int u, int v) {
		make_root(v);
		Node *curr = &nodes[v];
		curr -> p = &nodes[u];
	}

    // cut the edge between u and v
	void cut(int u, int v) {
		make_root(u);
		access(v);
		if (nodes[v].l) {
			nodes[v].l -> p = nullptr;
			nodes[v].l = nullptr;
		}
	}

    // cut the edge between u and its parent
    void cut(int v) {
        int u = find_root(v);
        if(u != v) cut(u, v);
    }

    // find lca between two nodes
    int lca(int u, int v) {
        if(u == v) return u;
        access(u), access(v);
        splay(&nodes[u]);
        if(nodes[v].p) {
            auto *curr = &nodes[v];
            while(curr != nodes[u].l && curr != nodes[u].r) curr = curr -> p;
            if(curr == nodes[u].l) return v;
            else return u;
        }else 
            return nodes[u].p -> val;
    }

    // is there a path between u and v
    bool connected(int u, int v) {
        if(u == v) return true;
        access(u), access(v);
        return nodes[u].p;
    }

    // get the value of the node
    T get(int v) {
        access(v);
        return nodes[v].val;
    }

    // set the value of the node
    void set(int v, T val) {
        access(v);
        nodes[v].val = val;
    }

    // get the value of the edge between u and v
    T get(int u, int v) {
        make_root(u);
        access(v);
        return nodes[v].val;
    }

    // set the value of the edge between u and v
    void set(int u, int v, T val) {
        make_root(u);
        access(v);
        nodes[v].val = val;
    }
};

void solve(int tc) {
	ll n, q;
	cin >> n >> q;

	LCT<ll> lc(n);
	while (q--)
	{
		string opp;
		cin >> opp;
		if (opp == "lca") {
			ll u, v; cin >> u >> v;
			cout << lc.lca(u, v) << '\n';
		} else if (opp == "link") {
			ll u, v; cin >> u >> v;
			lc.link(v, u);
		} else {
			ll u; cin >> u;
			lc.cut(u);
		}
	}
}

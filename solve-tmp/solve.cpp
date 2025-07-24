#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

struct LCT {
    struct Node {
        int p = -1, ch[2] = {-1, -1};
        bool rev = false;
        long long val = 0, sum = 0;
    };

    vector<Node> T;

    LCT(int n) : T(n) {}

    // Utilities
    bool is_root(int x) {
        int p = T[x].p;
        return p == -1 || (T[p].ch[0] != x && T[p].ch[1] != x);
    }

    void push(int x) {
        if (T[x].rev) {
            swap(T[x].ch[0], T[x].ch[1]);
            for (int &c : T[x].ch)
                if (c != -1) T[c].rev ^= 1;
            T[x].rev = false;
        }
    }

    void pull(int x) {
        T[x].sum = T[x].val;
        for (int c : T[x].ch)
            if (c != -1) T[x].sum += T[c].sum;
    }

    void rotate(int x) {
        int p = T[x].p, g = T[p].p;
        bool isL = (T[p].ch[0] == x);
        int b = T[x].ch[isL ^ 1];

        if (!is_root(p)) T[g].ch[T[g].ch[1] == p] = x;
        T[x].p = g;

        T[x].ch[isL ^ 1] = p;
        T[p].p = x;

        T[p].ch[isL] = b;
        if (b != -1) T[b].p = p;

        pull(p);
        pull(x);
    }

    void splay(int x) {
        vector<int> path;
        for (int y = x; !is_root(y); y = T[y].p)
            path.push_back(T[y].p);
        reverse(path.begin(), path.end());
        for (int y : path) push(y);
        push(x);

        while (!is_root(x)) {
            int p = T[x].p, g = T[p].p;
            if (!is_root(p))
                rotate((T[p].ch[0] == x) == (T[g].ch[0] == p) ? p : x);
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
        int res = access(v);
        return get_root(u) == get_root(v) ? res : -1;
    }

    int get_root(int x) {
        access(x);
        while (T[x].ch[0] != -1) {
            x = T[x].ch[0];
            push(x);
        }
        splay(x);
        return x;
    }

    int get_parent(int x) {
        access(x);
        splay(x);
        if (T[x].ch[0] == -1) return -1;
        x = T[x].ch[0];
        push(x);
        while (T[x].ch[1] != -1) {
            x = T[x].ch[1];
            push(x);
        }
        splay(x);
        return x;
    }

    void set_val(int x, long long v) {
        access(x);
        T[x].val = v;
        pull(x);
    }

    void add(int x, long long v) {
        access(x);
        T[x].val += v;
        pull(x);
    }

    long long query(int x) {
        access(x);
        return T[x].sum;
    }
};


int main() {
	ll n, q;
	cin >> n >> q;

	LCT lc(n);

	while (q--)
	{
		string ty;
		cin >> ty;

		if (ty == "lca") {
			ll u, v; cin >> u >> v;
			cout << lc.lca(u, v) << '\n';
		} else if (ty == "link") {
			ll u, v; cin >> u >> v;
			lc.link(u, v);
		} else {
			ll u; cin >> u;
			// lc.cut(u, lc.get_parent(u));
		}
	}	
}

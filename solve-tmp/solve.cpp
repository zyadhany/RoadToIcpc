#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<ll>
#define vii vector<vi>
#define vc vector<char>
#define vcc vector<vc>
#define vp vector<pl>
#define mi map<ll,ll>
#define mc map<char,int>
#define sortx(X) sort(X.begin(),X.end());
#define all(X) X.begin(),X.end()
#define allr(X) X.rbegin(),X.rend()
#define ln '\n'
#define YES {cout << "YES\n"; return;}
#define NO {cout << "NO\n"; return;}
#define MUN {cout << "-1\n"; return;}

using namespace std;

const int MODE = 998244353;

class SparseSegtree {
  private:
  struct item {
    ll sum, mx;
    item() : sum(0), mx(0) {}
    item(ll sum, ll mx) : sum(sum), mx(mx) {}
  };
	struct Node {
		item val;
		ll lazy = MODE;
		int left = -1;
		int right = -1;
	};

	vector<Node> tree;
	const int n;
	int timer = 0;

	item comb(item a, item b) { 
        item res;
        res.sum = a.sum + b.sum;
        res.mx = max(a.mx, a.sum + b.mx);
        return res;
    }

	void apply(ll cur, ll len, ll laz) {
		if (laz == MODE) return;
        tree[cur].lazy = laz;
        tree[cur].val = item(laz * len, max(0LL, laz * len));
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
		tree[cur].lazy = MODE;
	}

	void range_set(int cur, int l, int r, int ql, int qr, int val) {
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

    // last index such summ from 0 -> ind <= k
    ll get(int cur, int l, int r, ll k) {
        if (l == r) return l;
        push_down(cur, l, r);
        int m = (l + r) / 2;
        push_down(tree[cur].left, l, m);
        push_down(tree[cur].right, m+1, r);
        if (tree[tree[cur].left].val.mx < k) return get(tree[cur].right, m+1, r, k - tree[tree[cur].left].val.sum);
        return get(tree[cur].left, l, m, k);
    }

  public:
	SparseSegtree(int n, int q = 0) : n(n) {
		if (q > 0) { tree.reserve(2 * q * (int)log2(n)); }
		tree.push_back(Node());
	}

	void range_set(int ql, int qr, int val) { range_set(0, 0, n - 1, ql, qr, val); }

	item range_sum(int ql, int qr) { return range_sum(0, 0, n - 1, ql, qr); }

    ll get(ll k) {return get(0, 0, n-1, k);}
};

void solve(int tc) {
    ll n;

    cin >> n;

    SparseSegtree seg(n + 2, 1e6);

    while (true)
    {
        char ty; cin >> ty;
        if (ty == 'E') break;
        else if (ty == 'I') {
            ll l, r, k; cin >> l >> r >> k;
            seg.range_set(l, r, k);
        } else {
            ll k; cin >> k;
            cout << seg.get(k+1)-1 << '\n';
        }
    }   
}
 
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("boards.in", "r", stdin);
    // freopen("boards.out", "w", stdout);

    // cin >> size;
    for (int i = 1; i <= size; i++)
        solve(i);
}
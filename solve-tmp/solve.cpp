#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
 
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<long long>
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
 
const int MODE = 1e9+7;


const ll INF = 1e16;

class SparseSegtree {
  private:
  typedef ll item;
	struct Node {
		item val = INF;
		ll lazy = 0;
		int left = -1;
		int right = -1;
	};
	vector<Node> tree;
	const int n;
	int timer = 0;

	item comb(item a, item b) { return min(a, b); }

	void apply(ll cur, ll len, ll laz) {
		if (!laz) return;
        if (!tree[cur].lazy) tree[cur].lazy = laz;
        else  tree[cur].lazy = min(tree[cur].lazy, laz);
        tree[cur].val = min(tree[cur].val, laz);
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

        if (ty) {
            if (tree[cur].lazy) apply(tree[cur].left, m - l + 1, tree[cur].lazy + r - m);
            else apply(tree[cur].left, m - l + 1, tree[cur].lazy);
            apply(tree[cur].right, r - m, tree[cur].lazy);    
        } else {
            apply(tree[cur].left, m - l + 1, tree[cur].lazy);
            if (tree[cur].lazy) apply(tree[cur].right, r - m, tree[cur].lazy + m - l + 1);
            else apply(tree[cur].right, r - m, tree[cur].lazy);
        }

		tree[cur].lazy = 0;
	}

	void range_set(int cur, int l, int r, int ql, int qr, ll val) {
		if (qr < l || ql > r) { return; }
		if (ql <= l && r <= qr) {
            if (ty) {
                apply(cur, r - l + 1, val+qr-r);
            } else {
                apply(cur, r - l + 1, val+l-ql);
            }
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
		if (qr < l || ql > r) { return INF; }
		if (ql <= l && r <= qr) { return tree[cur].val; }
		push_down(cur, l, r);
		int m = (l + r) / 2;
		return comb(range_sum(tree[cur].left, l, m, ql, qr),
		            range_sum(tree[cur].right, m + 1, r, ql, qr));
	}

  public:
    bool ty;
	SparseSegtree(int n, int q = 0, ll ty = 0) : n(n), ty(ty) {
		if (q > 0) { tree.reserve(2 * q * (int)log2(n)); }
		tree.push_back(Node());
	}

	void set(int ql, ll val) { range_set(0, 0, n - 1, ql, ql, val); }

	item get(int ql) { return range_sum(0, 0, n - 1, ql, ql); }
};


struct query
{
    ll l, r, x, ty;
    query(){}
    query(ll la, ll ra, ll xa, ll tya) {
        l = la;
        r = ra;
        x = xa;
        ty = tya;
    }
    bool operator<(const query& q) {
        if (l != q.l) return l < q.l;
        return ty < q.ty;
    }
};

const int MXN = 1e9+10;
 
void sol(vector<query> &Q, vi &res) {
    sortx(Q);
    SparseSegtree sgl(MXN), sgr(MXN, 0, 1);
    for (auto q : Q) {
        if (q.ty == 0) {
            sgl.set(q.r, q.x+q.r-q.l); 
            sgr.set(q.r,q.x+q.r-q.l);
        } else {
            ll re = min(sgl.get(q.r), sgr.get(q.r)) + q.l;
            res[q.x] = min(res[q.x], re);
        }
    } 
}

// void sol2(vector<query> &Q, vi &res) {
//     sortx(Q);
//     SparseSegtree sgl(MXN), sgr(MXN, 0, 1);
//     for (auto q : Q) {
//         if (q.ty == 0) {
//             ll w = q.x-q.l;
//             sgl.set(q.r, 1e9, w);
//             sgr.set(0, q.r, w);
//         } else {
//             ll re = min(sgl.get(q.r), sgr.get(q.r)) + q.l;
//             res[q.x] = min(res[q.x], re);
//         }
//     } 
// }


void solve(int tc) {
    ll n, m;
 
    cin >> n >> m;
 
    vector<query> Q;
    for (int i = 0; i < n; i++)
    {
        ll l, r, t; cin >> l >> r >> t;
        // if (r < l) swap(l, r);
        Q.push_back(query(l, r, t, 0));
    }

    vi res(m);
    for (int i = 0; i < m; i++)
    {
        ll l, r; cin >> l >> r;
        // if (r < l) swap(l, r);
        res[i] = abs(r - l);
        Q.push_back(query(l, r, i, 1));
    }

    sol(Q, res);
    for (auto &q : Q) {
        q.l = 1e9-q.l, q.r = 1e9-q.r;
        swap(q.l, q.r);
    }
    sol(Q, res);
    for (auto &q : Q) {
        swap(q.l, q.r);
    }
    // sol(Q, res);
    
    

    for (auto a : res) cout << a << '\n';
}
 
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;    
 
    freopen("slingshot.in", "r", stdin);
    freopen("slingshot.out", "w", stdout);
 
    // cin >> size;
    for (int i = 1; i <= size; i++) solve(i);
    return 0;
}

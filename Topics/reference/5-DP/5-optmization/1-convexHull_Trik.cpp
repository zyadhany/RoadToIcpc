/**
 * dp optimization in form dp[i] = max or min of (dp[j] + f(i,j)) for j < i
 * where f(i,j) = k*i + constant in j
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 */
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

long long N, A, B, C;
LineContainer lc;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> A >> B >> C;
	long long P = 0, a, dp = 0;
	for (int i = 1; i <= N; i++) {
		lc.add(-2 * A * P, dp + A * P * P - B * P);
		cin >> a;
		P += a;
		dp = lc.query(P) + A * P * P + B * P + C;
	}
	cout << dp << '\n';
}
/*
it's dp optimization solve dp in form of:
dp[i][j] = min(dp[k][j-1] + C(k, i)) for k <= i
where C(k, i) is a cost function that can be computed in O(1) time.

it work when C(k, i) is convex in k, and the cost function C(k, i) is monotonic in k.
for each i, we can find the optimal k that minimizes the cost function, opt[i] <= opt[i].

that can be checked by the following conditions:
C(a, c) + C(b, d) <= C(a, d) + C(b, c) for all a < b < c < d
*/


// cp algorithm
int m, n;
vector<long long> dp_before, dp_cur;

long long C(int i, int j);

// compute dp_cur[l], ... dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr) {
    if (l > r)
        return;

    int mid = (l + r) >> 1;
    pair<long long, int> best = {LLONG_MAX, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
        best = min(best, {(k ? dp_before[k - 1] : 0) + C(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}

long long solve() {
    dp_before.assign(n,0);
    dp_cur.assign(n,0);

    for (int i = 0; i < n; i++)
        dp_before[i] = C(0, i);

    for (int i = 1; i < m; i++) {
        compute(0, n - 1, 0, n - 1);
        dp_before = dp_cur;
    }

    return dp_before[n - 1];
}

// My implementation
const ll INF = 1e18;
const int MXN = 3e3 + 10;
ll dp[MXN][MXN];

void dac(vi &X, ll k, ll l, ll r, ll optl, ll optr) {
	if (l > r) return;
	ll mid = (l+r)>>1;

	pl best = {INF, optl};
	for (int i = optl; i <= min(mid, optr); i++)
	{
		ll c = X[mid]-X[i];
		best = min(best, pl(dp[i][k-1] + c*c, i));
	}
	
	dp[mid][k] = best.first;
	ll opt = best.second;
	dac(X, k, l, mid-1, optl, opt);
	dac(X, k, mid+1, r, opt, optr);
}

void solve(int tc) {
	ll n, k;
	cin >> n >> k;

	vi X(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> X[i];
		X[i]+=X[i-1];
	}
	
	for (int i = 1; i <= n; i++) dp[i][0] = INF;
	dp[0][0] = 0;
	
	for (int i = 1; i <= k; i++)
	{
		dac(X, i, 1, n, 0, n-1);
	}
	
	cout << dp[n][k] << '\n';
}

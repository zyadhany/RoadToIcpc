int bit[1001][1001];
int n;

void update(int x, int y, int val) {
	for (; x <= n; x += (x & (-x))) {
		for (int i = y; i <= n; i += (i & (-i))) { bit[x][i] += val; }
	}
}

int query(int x1, int y1, int x2, int y2) {
	int ans = 0;
	for (int i = x2; i; i -= (i & (-i))) {
		for (int j = y2; j; j -= (j & (-j))) { ans += bit[i][j]; }
	}
	for (int i = x2; i; i -= (i & (-i))) {
		for (int j = y1 - 1; j; j -= (j & (-j))) { ans -= bit[i][j]; }
	}
	for (int i = x1 - 1; i; i -= (i & (-i))) {
		for (int j = y2; j; j -= (j & (-j))) { ans -= bit[i][j]; }
	}
	for (int i = x1 - 1; i; i -= (i & (-i))) {
		for (int j = y1 - 1; j; j -= (j & (-j))) { ans += bit[i][j]; }
	}
	return ans;
}


////////////////////////// 2D Fenwick Tree //////////////////////////

ll rangequery(const vii &BIT, int l, int r) {
    ll summ = 0;

    for (int i = l; i > 0; i -= i & -i)
        for (int j = r; j > 0; j -= j & -j)
            summ = (summ + BIT[i][j]) % MODE;
    
    return summ;
}

ll rangequery(const vii& BIT, int l1, int r1, int l2, int r2) {
    ll res = 0;
    res += rangequery(BIT, l2, r2);
    res -= rangequery(BIT, l1 - 1, r2);
    res -= rangequery(BIT, l2, r1 - 1);
    res += rangequery(BIT, l1 - 1, r1 - 1);
    res = (res%MODE + MODE) % MODE;
    return res;
}

void updatepoint(vii& BIT, int l, int r, ll val) {
    for (int i = l; i < BIT.size(); i += i & -i)
        for (int j = r; j < BIT[0].size(); j += j & -j)
            BIT[i][j] = (BIT[i][j] + val) % MODE;
}

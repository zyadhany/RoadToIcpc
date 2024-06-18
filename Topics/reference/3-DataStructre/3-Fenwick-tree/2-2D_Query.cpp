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

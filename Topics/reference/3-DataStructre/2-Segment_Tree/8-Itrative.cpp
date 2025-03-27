const int MXN = 2e5+10;
int sgsize;
ll sgtree[MXN * 4];

void update(int idx, int val) {
	sgtree[idx += sgsize] = val;
	for (idx /= 2; idx; idx /= 2) sgtree[idx] = max(sgtree[2 * idx], sgtree[2 * idx + 1]);
}

int query(int lo, int hi) {
	int ra = 0, rb = 0;
	for (lo += sgsize, hi += sgsize + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = max(ra, sgtree[lo++]);
		if (hi & 1) rb = max(rb, sgtree[--hi]);
	}
	return max(ra, rb);
}

void build(vi &X) {
    sgsize = X.size();
    for (int i = 0; i < sgsize; i++) sgtree[i + sgsize] = X[i];
    for (int i = sgsize - 1; i > 0; i--) sgtree[i] = max(sgtree[2 * i], sgtree[2 * i + 1]);
}

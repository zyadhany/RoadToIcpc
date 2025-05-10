const int MXN = 2e5+10;
int sgsize;
typedef ll iteam;
iteam sgtree[MXN * 4];

iteam marge(iteam &a, iteam&b) {
    return a + b;
}

void update(int idx, ll val) {
	sgtree[idx += sgsize] = val;
	for (idx /= 2; idx; idx /= 2) sgtree[idx] = marge(sgtree[2 * idx], sgtree[2 * idx + 1]);
}

iteam query(int lo, int hi) {
	iteam ra, rb; ra = rb = iteam();
	for (lo += sgsize, hi += sgsize + 1; lo < hi; lo /= 2, hi /= 2) {
		if (lo & 1) ra = marge(ra, sgtree[lo++]);
		if (hi & 1) rb = marge(rb, sgtree[--hi]);
	}
	return marge(ra, rb);
}

void build(vi &X) {
    sgsize = X.size();
    for (int i = 0; i < sgsize; i++) sgtree[i + sgsize] = X[i];
    for (int i = sgsize - 1; i > 0; i--) sgtree[i] = marge(sgtree[2 * i], sgtree[2 * i + 1]);
}

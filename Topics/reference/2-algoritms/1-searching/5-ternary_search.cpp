template <typename F> int find_min(int l, int r, const F &f) {
	while (r - l > 3) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;
		f(m1) > f(m2) ? l = m1 : r = m2;
	}

	int res = l;
	for (int i = l + 1; i <= r; i++) {
		if (f(i) < f(res)) { res = i; }
	}

	return res;
}

// we can speed up by storing the value of f(m1) and f(m2).
// better with double than binery search
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l); //return the maximum of f(x) in [l, r]
}

// area of rectangle
ll RecArea(vi &A) {
    return (A[2] - A[0]) * (A[3] - A[1]);
}

// common rectengle insde 2 other, -1 it not exist.
vi commonEdge(vi &A, vi &B) {
    ll x1 = max(A[0], B[0]);
    ll x2 = min(A[2], B[2]);
    ll y1 = max(A[1], B[1]);
    ll y2 = min(A[3], B[3]);

    if (x1 > x2 || y1 > y2) return vi(4, -1);
    return {x1, y1, x2, y2};
}

/**
 * Common Area of 2 rectangles.
 * A is vector:
 * [0 , 2 -> low, high x]
 * [1 , 3 -> low, high y]
 */
ll commonArea(vi &A, vi &B) {
    vi rec = commonEdge(A, B);
    return RecArea(rec);
}


// point x, y exist inside rectangle
bool covered(int x, int y, int x1, int y1, int x2, int y2) {
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}

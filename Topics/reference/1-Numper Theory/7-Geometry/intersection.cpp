const double EPS = 1E-9;

struct Point {
	double x, y;

	bool operator<(const Point &p) const {
		return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
	}
    bool operator==(const Point &p) const {
        return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
    }
    bool operator!=(const Point &p) const {
        return !(*this == p);
    }
};

struct Line {
	double a, b, c;

	Line() {}
	Line(Point p, Point q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
		norm();
	}

	void norm() {
		double z = sqrt(a * a + b * b);
		if (abs(z) > EPS) { a /= z, b /= z, c /= z; }
	}

	double dist(Point p) const { return a * p.x + b * p.y + c; }
};

double det(double a, double b, double c, double d) { return a * d - b * c; }

inline bool betw(double l, double r, double x) {
	return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(double a, double b, double c, double d) {
	if (a > b) { swap(a, b); }
	if (c > d) { swap(c, d); }
	return max(a, c) <= min(b, d) + EPS;
}

// get intersection of 2 lines a, b and c, d
// return false if no intersection, true if intersection
// left, right is the intersection point of 2 lines
bool intersect(Point a, Point b, Point c, Point d, Point &left, Point &right) {
	if (!intersect_1d(a.x, b.x, c.x, d.x) || !intersect_1d(a.y, b.y, c.y, d.y)) {
		return false;
	}
	Line m(a, b);
	Line n(c, d);
	double zn = det(m.a, m.b, n.a, n.b);
	if (abs(zn) < EPS) {
		if (abs(m.dist(c)) > EPS || abs(n.dist(a)) > EPS) { return false; }
		if (b < a) { swap(a, b); }
		if (d < c) { swap(c, d); }
		left = max(a, c);
		right = min(b, d);
		return true;
	} else {
		double det_x = det(m.c, m.b, n.c, n.b) / zn;
		double det_y = det(m.a, m.c, n.a, n.c) / zn;
		left.x = right.x = (det_x == 0 ? 0 : -det_x);
		left.y = right.y = (det_y == 0 ? 0 : -det_y);
		return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
		       betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
	}
}

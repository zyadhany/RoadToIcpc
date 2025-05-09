/*
  Area of 4 points
  x1 y2 − x2 y1 + x2 y3 − x3 y2 + x3 y4 − x4 y3 + x4 y1 − x1 y4  
*/

/*
Cross product of 2 vectors
A x B = A.x * B.y - A.y * B.x
A x B = |A| * |B| * sin(theta)

if postive, A is counter-clockwise to B
if negative, A is clockwise to B
if 0, A is parallel to B    
*/
ll CrossPrduct(pl a, pl b) {
    return a.first * b.second - a.second * b.first;
}

// shortest angle between a and b.
ld angleBetweenPoint(pl a, pl b) {
    return atan2(CrossPrduct(a, b), a.first * b.first + a.second * b.second) * 180 / PI;
}

/*
Point Location:
line from A to B, point C
calculate (C - A) x (C - B)
if > 0, C is left of line AB
if < 0, C is right of line AB
if = 0, C is on line AB
*/
int PointLocation(pl a, pl b, pl c) {
    ll res = CrossPrduct({c.first-a.first, c.second-a.second}, {c.first-b.first, c.second-b.second});
    if (res > 0) return 1; // LEFT
    else if (res < 0) return -1; // RIGHT
    return 0; // TOUCH
}

// check if point c in line a > b.
bool online(pl a, pl b, pl c) {
    ll re = PointLocation(a, b, c);
    return (re == 0 && c.first >= min(a.first, b.first) && c.first <= max(a.first, b.first) && c.second >= min(a.second, b.second) && c.second <= max(a.second, b.second));
}

/*
Line intersection:
A1 + t * (A2 - A1) = B1 + s * (B2 - B1)
t = (B1 - A1) x (B2 - B1) / ((A2 - A1) x (B2 - B1))
s = (B1 - A1) x (A2 - A1) / ((A2 - A1) x (B2 - B1))
if 0 <= t <= 1 and 0 <= s <= 1, lines intersect at A1 + t * (A2 - A1)
if t < 0 or t > 1, lines are parallel
if s < 0 or s > 1, lines are parallel

another way.
3 cases:
- infinite intersection: A1, A2, B1, B2 are collinear, check if A1, A2, B1, B2 are on the same line.
- intersection C = {A1, A2, B1, B2}.
- intersection not point so we check B1, B2 are on different side of A1, A2, and A1, A2 are on different side of B1, B2.
*/
bool intersect(pl a1, pl a2, pl b1, pl b2) {
    if (online(a1, a2, b1) || online(a1, a2, b2) ||
        online(b1, b2, a1) || online(b1, b2, a2)) return 1;

    int d1 = PointLocation(a1, a2, b1);
    int d2 = PointLocation(a1, a2, b2);
    int d3 = PointLocation(b1, b2, a1);
    int d4 = PointLocation(b1, b2, a2);

    return (d1 * d2 < 0 && d3 * d4 < 0);
}
bool intersect(pl a1, pl a2, pl b1, pl b2) {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = min(a1.first, a2.first), x2 = max(a1.first, a2.first);
	y1 = min(a1.second, a2.second), y2 = max(a1.second, a2.second);
	x3 = min(b1.first, b2.first), x4 = max(b1.first, b2.first);
	y3 = min(b1.second, b2.second), y4 = max(b1.second, b2.second);
	if ((x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1)) return 0;

    int d1 = PointLocation(a1, a2, b1);
    int d2 = PointLocation(a1, a2, b2);
    int d3 = PointLocation(b1, b2, a1);
    int d4 = PointLocation(b1, b2, a2);

    return (d1 * d2 <= 0 && d3 * d4 <= 0);
}

/*
Point Distance from line:
d = |(A2 - A1) x (A1 - P)| / |A2 - A1|  -> (cross product)
 */

/*
Given point and polygon, check if point is inside polygon.
send ray from point to right, count how many times it intersects with polygon.
if odd, point is inside polygon.
if even, point is outside polygon.
*/
int isInside(vp &X, pl p) {
    ll cnt = 0;
    pl p2 = {p.first+1, INT32_MAX}; // No int point between p and p2
    for (int i = 0; i < X.size(); i++) {
        cnt += intersect(X[i], X[(i + 1) % X.size()], p, p2);
        if (online(X[i], X[(i + 1) % X.size()], p)) return 0; // TOUCH
    }
    if (cnt % 2) return 1; // INSIDE
    return -1; // OUTSIDE
}


/*
Area of Polygon of n vertex:
Area = 1/2 * |x1y2 + x2y3 + ... + xn-1yn + xn-1y1 - (y1x2 + y2x3 + ... + yn-1xn + yn-1x1)|

Pick's Theorem:
Area = I + B/2 - 1
I = number of interior intiger points (points inside polygon)
B = number of boundary intiger points (points on the edge of polygon)
2 * Area = 2 * I + B - 2
I = (2 * Area - B + 2) / 2

To get B, for each segment B is gcd(x2 - x1, y2 - y1) + 1
B = sum(gcd(x2 - x1, y2 - y1) + 1) - n
*/

// Return Twice the area of polygon, make sure to divide by 2
ll AreaOfPolygon(vp &X) {
    ll area = 0;
    for (int i = 0; i < X.size(); i++) {
        area += X[i].first * X[(i + 1) % X.size()].second - X[i].second * X[(i + 1) % X.size()].first;
    }
    return abs(area); // 2 * area;
}

// return pair {I, B}, I = inside points, B = boundary points
pl cntLatticePoints(vp &X) {
    ll area = AreaOfPolygon(X); // That is 2 * area
    ll B = 0;
    for (int i = 0; i < X.size(); i++)
    {
        B += gcd(abs(X[i].first - X[(i + 1) % X.size()].first), abs(X[i].second - X[(i + 1) % X.size()].second));   
    }
    ll I = (area - B + 2) / 2;
    return {I, B};
}


/*
Maximum Manhattan distance of 2 points:
d = |x1 - x2| + |y1 - y2|
we make 45 degree rotation of the coordinate system.
x1 = x1 + y1
y1 = y1 - x1

d = max(|x1 - x2|, |y1 - y2|)
*/

// sort points by angle anticlockwise starting from 3rd quadrant (-x, -y).
bool compare(pl &a, pl &b) {
    return atan2l(a.second, a.first) < atan2l(b.second, b.first);
}

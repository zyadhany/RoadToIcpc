#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// CONVEX HULL & 2D GEOMETRY BLACK-BOX TEMPLATE FOR COMPETITIVE PROGRAMMING
// ============================================================================

using T = long long; // Change to double for floating point geometry if needed

struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(T c) const { return Point(x * c, y * c); }
    Point operator/(T c) const { return Point(x / c, y / c); }

    bool operator<(const Point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

T cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
T cross(Point o, Point a, Point b) { return cross(a - o, b - o); }
T dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
T dot(Point o, Point a, Point b) { return dot(a - o, b - o); }
T dist2(Point a, Point b) { return dot(a - b, a - b); }
double dist(Point a, Point b) { return sqrt(dist2(a, b)); }

/*
 * ============================================================================
 * FUNCTION: convex_hull
 * WHAT IT DOES:
 *   Computes the 2D Convex Hull of a given set of points using Monotone Chain.
 *   Returns the hull vertices ordered Counter-Clockwise (CCW).
 * HOW TO USE:
 *   vector<Point> hull = convex_hull(pts, include_collinear);
 *   - include_collinear = false: (default) Strictly minimal hull (no collinear points on edges).
 *   - include_collinear = true : Includes collinear points lying on boundary edges.
 * TIME COMPLEXITY: O(N log N)
 * ============================================================================
 */
vector<Point> convex_hull(vector<Point> pts, bool include_collinear = false) {
    int n = pts.size();
    if (n <= 1) return pts;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    n = pts.size();
    if (n <= 2) return pts;

    vector<Point> h;
    auto check = [&](Point a, Point b, Point c) {
        T crs = cross(a, b, c);
        if (include_collinear) return crs < 0;
        return crs <= 0;
    };

    // Lower hull
    for (int i = 0; i < n; i++) {
        while (h.size() >= 2 && check(h[h.size() - 2], h.back(), pts[i]))
            h.pop_back();
        h.push_back(pts[i]);
    }

    // Upper hull
    int l = h.size();
    for (int i = n - 2; i >= 0; i--) {
        while (h.size() > l && check(h[h.size() - 2], h.back(), pts[i]))
            h.pop_back();
        h.push_back(pts[i]);
    }

    h.pop_back();
    return h;
}

/*
 * ============================================================================
 * FUNCTION: is_convex
 * WHAT IT DOES:
 *   Checks if a polygon given as a vector of points in order is convex.
 * HOW TO USE:
 *   bool ok = is_convex(poly);
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
bool is_convex(const vector<Point>& p) {
    int n = p.size();
    if (n < 3) return false;
    bool has_pos = false, has_neg = false;
    for (int i = 0; i < n; i++) {
        T crs = cross(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (crs > 0) has_pos = true;
        if (crs < 0) has_neg = true;
        if (has_pos && has_neg) return false;
    }
    return true;
}

/*
 * ============================================================================
 * FUNCTION: point_in_convex
 * WHAT IT DOES:
 *   Determines whether a point `pt` lies inside, on boundary, or outside a convex polygon.
 * HOW TO USE:
 *   int loc = point_in_convex(P, pt);
 * RETURN VALUES:
 *   1  : Strictly inside
 *   2  : On the boundary
 *   0  : Strictly outside
 * PRECONDITION:
 *   Polygon `P` MUST be convex, strictly Counter-Clockwise (CCW) oriented, size >= 3.
 * TIME COMPLEXITY: O(log N)
 * ============================================================================
 */
int point_in_convex(const vector<Point>& P, Point pt) {
    int n = P.size();
    if (n < 3) return 0;
    T c1 = cross(P[1] - P[0], pt - P[0]);
    T cn = cross(P[n - 1] - P[0], pt - P[0]);

    if (c1 < 0 || cn > 0) return 0;
    if (c1 == 0) {
        if (dot(P[1] - P[0], pt - P[0]) >= 0 && dot(P[0] - P[1], pt - P[1]) >= 0) return 2;
        return 0;
    }
    if (cn == 0) {
        if (dot(P[n - 1] - P[0], pt - P[0]) >= 0 && dot(P[0] - P[n - 1], pt - P[n - 1]) >= 0) return 2;
        return 0;
    }

    int l = 1, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (cross(P[mid] - P[0], pt - P[0]) >= 0) l = mid;
        else r = mid;
    }

    T c = cross(P[l + 1] - P[l], pt - P[l]);
    if (c > 0) return 1;
    if (c == 0) return 2;
    return 0;
}

/*
 * ============================================================================
 * FUNCTION: polygon_area2
 * WHAT IT DOES:
 *   Computes twice the signed area of a polygon (2 * Area).
 * HOW TO USE:
 *   T double_area = polygon_area2(poly);
 *   double exact_area = double_area / 2.0;
 * RETURN VALUE:
 *   Positive if CCW, negative if CW. Magnitude is 2 * Area.
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
T polygon_area2(const vector<Point>& p) {
    T area = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return area;
}

/*
 * ============================================================================
 * FUNCTION: polygon_perimeter
 * WHAT IT DOES:
 *   Computes the total perimeter of a polygon.
 * HOW TO USE:
 *   double perim = polygon_perimeter(poly);
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
double polygon_perimeter(const vector<Point>& p) {
    double perim = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        perim += dist(p[i], p[(i + 1) % n]);
    }
    return perim;
}

/*
 * ============================================================================
 * FUNCTION: rotating_calipers_diameter
 * WHAT IT DOES:
 *   Finds the maximum squared distance between any pair of points in a convex hull/polygon (Diameter).
 * HOW TO USE:
 *   auto [max_dist2, p1_idx, p2_idx] = rotating_calipers_diameter(hull);
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
tuple<T, int, int> rotating_calipers_diameter(const vector<Point>& P) {
    int n = P.size();
    if (n == 1) return {0, 0, 0};
    if (n == 2) return {dist2(P[0], P[1]), 0, 1};

    T max_d2 = 0;
    int best_i = 0, best_j = 0;
    int k = 1;

    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        while (true) {
            int nk = (k + 1) % n;
            T area1 = abs(cross(P[ni] - P[i], P[k] - P[i]));
            T area2 = abs(cross(P[ni] - P[i], P[nk] - P[i]));
            if (area2 > area1) {
                k = nk;
            } else break;
        }

        T d1 = dist2(P[i], P[k]);
        T d2 = dist2(P[ni], P[k]);
        if (d1 > max_d2) { max_d2 = d1; best_i = i; best_j = k; }
        if (d2 > max_d2) { max_d2 = d2; best_i = ni; best_j = k; }
    }
    return {max_d2, best_i, best_j};
}

/*
 * ============================================================================
 * FUNCTION: minkowski_sum
 * WHAT IT DOES:
 *   Computes the Minkowski Sum (A + B) of two convex polygons A and B.
 * HOW TO USE:
 *   vector<Point> C = minkowski_sum(A, B);
 * PRECONDITION:
 *   Polygons A and B MUST be convex and CCW ordered.
 * TIME COMPLEXITY: O(N + M)
 * ============================================================================
 */
vector<Point> minkowski_sum(vector<Point> A, vector<Point> B) {
    auto reorder = [](vector<Point>& P) {
        int pos = 0;
        for (int i = 1; i < (int)P.size(); i++) {
            if (P[i].y < P[pos].y || (P[i].y == P[pos].y && P[i].x < P[pos].x))
                pos = i;
        }
        rotate(P.begin(), P.begin() + pos, P.end());
    };

    reorder(A);
    reorder(B);
    int n = A.size(), m = B.size();
    A.push_back(A[0]); A.push_back(A[1]);
    B.push_back(B[0]); B.push_back(B[1]);

    vector<Point> result;
    int i = 0, j = 0;
    while (i < n || j < m) {
        result.push_back(A[i] + B[j]);
        T crs = cross(A[i + 1] - A[i], B[j + 1] - B[j]);
        if (crs >= 0 && i < n) i++;
        if (crs <= 0 && j < m) j++;
    }
    return convex_hull(result);
}

/*
 * ============================================================================
 * FUNCTION: expand_convex_hull
 * WHAT IT DOES:
 *   Expands a convex hull outward by radius `r` discrete steps to create a safe enclosing boundary.
 * HOW TO USE:
 *   vector<Point> expanded_hull = expand_convex_hull(hull, r);
 * TIME COMPLEXITY: O(N log N)
 * ============================================================================
 */
vector<Point> expand_convex_hull(const vector<Point>& H, T r) {
    vector<Point> Q = {
        {r, 0}, {r, r}, {0, r}, {-r, r},
        {-r, 0}, {-r, -r}, {0, -r}, {r, -r}
    };
    vector<Point> pts;
    for (auto& p : H) {
        for (auto& q : Q) {
            pts.push_back(p + q);
        }
    }
    return convex_hull(pts);
}

/*
 * ============================================================================
 * FUNCTION: tangents_from_point
 * WHAT IT DOES:
 *   Finds the two tangent points on a convex polygon `P` from an external point `pt`.
 * HOW TO USE:
 *   auto [left_idx, right_idx] = tangents_from_point(P, pt);
 * PRECONDITION:
 *   `pt` MUST lie strictly outside polygon `P`.
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
pair<int, int> tangents_from_point(const vector<Point>& P, Point pt) {
    int n = P.size();
    int left_idx = 0, right_idx = 0;
    for (int i = 1; i < n; i++) {
        if (cross(pt, P[left_idx], P[i]) > 0) left_idx = i;
        if (cross(pt, P[right_idx], P[i]) < 0) right_idx = i;
    }
    return {left_idx, right_idx};
}

/*
 * ============================================================================
 * FUNCTION: point_in_general_polygon
 * WHAT IT DOES:
 *   Winding number algorithm to check if point `pt` is inside ANY polygon (convex or non-convex).
 * HOW TO USE:
 *   int loc = point_in_general_polygon(P, pt);
 * RETURN VALUES:
 *   1  : Inside
 *   2  : On boundary
 *   0  : Outside
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
int point_in_general_polygon(const vector<Point>& P, Point pt) {
    int n = P.size();
    int winding = 0;
    for (int i = 0; i < n; i++) {
        Point a = P[i], b = P[(i + 1) % n];
        if (cross(a - pt, b - pt) == 0 && dot(a - pt, b - pt) <= 0) return 2;
        if (a.y <= pt.y) {
            if (b.y > pt.y && cross(b - a, pt - a) > 0) winding++;
        } else {
            if (b.y <= pt.y && cross(b - a, pt - a) < 0) winding--;
        }
    }
    return winding != 0 ? 1 : 0;
}

/*
 * ============================================================================
 * FUNCTION: reverse_clockwise
 * WHAT IT DOES:
 *   Ensures the polygon is strictly Clockwise (CW) ordered.
 *   If it is Counter-Clockwise (CCW), it reverses the vertices.
 * HOW TO USE:
 *   reverse_clockwise(poly);
 * TIME COMPLEXITY: O(N)
 * ============================================================================
 */
void reverse_clockwise(vector<Point>& P) {
    if (polygon_area2(P) > 0) {
        reverse(P.begin(), P.end());
    }
}

/*
 * ============================================================================
 * FUNCTION: fullyContains
 * WHAT IT DOES:
 *   Checks if Convex Polygon A fully contains Polygon B.
 * HOW TO USE:
 *   bool ok = fullyContains(A, B);
 * PRECONDITION:
 *   Polygon A MUST be convex and CCW. Polygon B can be any shape.
 * TIME COMPLEXITY: O(M log N) where N = |A|, M = |B|
 * ============================================================================
 */
bool fullyContains(const vector<Point>& A, const vector<Point>& B) {
    for (const auto& pt : B) {
        if (point_in_convex(A, pt) == 0) return false;
    }
    return true;
}

/*
 * ============================================================================
 * FUNCTION: CPolygonsInter
 * WHAT IT DOES:
 *   Computes the intersection polygon of two CCW convex polygons using the
 *   Sutherland-Hodgman algorithm.
 * HOW TO USE:
 *   vector<Point> inter = CPolygonsInter(A, B);
 *   if (inter.empty()) { // No intersection }
 * PRECONDITION:
 *   A and B MUST be convex and CCW.
 *   IMPORTANT: To get exact intersection coordinates, you MUST change
 *   `using T = long long;` to `using T = double;` in the main template.
 * TIME COMPLEXITY: O(N * M)
 * ============================================================================
 */
vector<Point> CPolygonsInter(vector<Point> A, const vector<Point>& B) {
    for (int i = 0; i < (int)B.size(); i++) {
        Point p1 = B[i], p2 = B[(i + 1) % B.size()];
        vector<Point> next_A;
        for (int j = 0; j < (int)A.size(); j++) {
            Point q1 = A[j], q2 = A[(j + 1) % A.size()];
            T c1 = cross(p1, p2, q1);
            T c2 = cross(p1, p2, q2);
            if (c1 >= 0) next_A.push_back(q1);
            if ((c1 >= 0 && c2 < 0) || (c1 < 0 && c2 >= 0)) {
                T a1 = p2.y - p1.y, b1 = p1.x - p2.x, c_1 = a1 * p1.x + b1 * p1.y;
                T a2 = q2.y - q1.y, b2 = q1.x - q2.x, c_2 = a2 * q1.x + b2 * q1.y;
                T det = a1 * b2 - a2 * b1;
                if (det != 0) {
                    next_A.push_back(Point((c_1 * b2 - c_2 * b1) / det, (a1 * c_2 - a2 * c_1) / det));
                }
            }
        }
        A = next_A;
        if (A.empty()) break;
    }
    return A;
}

/*
 * ============================================================================
 * FUNCTION: segments_intersect
 * WHAT IT DOES:
 *   Checks if two line segments (a-b) and (c-d) intersect.
 *   Includes collinear overlap checks.
 * HOW TO USE:
 *   bool ok = segments_intersect(a, b, c, d);
 * TIME COMPLEXITY: O(1)
 * ============================================================================
 */
bool on_segment(Point p, Point a, Point b) {
    return cross(a - p, b - p) == 0 && dot(a - p, b - p) <= 0;
}

bool segments_intersect(Point a, Point b, Point c, Point d) {
    T cp1 = cross(b - a, c - a), cp2 = cross(b - a, d - a);
    T cp3 = cross(d - c, a - c), cp4 = cross(d - c, b - c);
    if (((cp1 > 0 && cp2 < 0) || (cp1 < 0 && cp2 > 0)) &&
        ((cp3 > 0 && cp4 < 0) || (cp3 < 0 && cp4 > 0))) return true;
    if (on_segment(c, a, b) || on_segment(d, a, b) ||
        on_segment(a, c, d) || on_segment(b, c, d)) return true;
    return false;
}

/*
 * ============================================================================
 * FUNCTION: general_polygons_intersect
 * WHAT IT DOES:
 *   Checks if ANY two polygons (convex or concave) intersect.
 *   Checks for any edge intersections, or if one is strictly inside the other.
 * HOW TO USE:
 *   bool ok = general_polygons_intersect(A, B);
 * TIME COMPLEXITY: O(N * M)
 * ============================================================================
 */
bool general_polygons_intersect(const vector<Point>& A, const vector<Point>& B) {
    int n = A.size(), m = B.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (segments_intersect(A[i], A[(i + 1) % n], B[j], B[(j + 1) % m])) 
                return true;
        }
    }
    if (point_in_general_polygon(A, B[0]) != 0) return true;
    if (point_in_general_polygon(B, A[0]) != 0) return true;
    return false;
}

/*
 * ============================================================================
 * FUNCTION: convex_polygons_intersect
 * WHAT IT DOES:
 *   Checks if two convex polygons intersect in linear time.
 *   Uses a Grandmaster trick: A and B intersect iff the origin (0,0) 
 *   lies inside the Minkowski Sum of A and (-B).
 * HOW TO USE:
 *   bool ok = convex_polygons_intersect(A, B);
 * PRECONDITION:
 *   A and B MUST be convex and CCW ordered.
 * TIME COMPLEXITY: O(N + M)
 * ============================================================================
 */
bool convex_polygons_intersect(const vector<Point>& A, const vector<Point>& B) {
    vector<Point> negB = B;
    for (auto& p : negB) {
        p.x = -p.x;
        p.y = -p.y;
    }
    vector<Point> M = minkowski_sum(A, negB);
    return point_in_convex(M, Point(0, 0)) != 0;
}
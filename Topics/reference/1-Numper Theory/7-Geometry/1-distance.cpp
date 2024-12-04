// given segment from a to b find closest point and distance to point p.
ld distToSegment(pair<ld, ld> a, pair<ld, ld> b, pair<ld, ld> p) {
    ld dx = b.first - a.first;
    ld dy = b.second - a.second;

    // Vector projection scalar t
    ld t = ((p.first - a.first) * dx + (p.second - a.second) * dy) / (dx * dx + dy * dy);

    // Clamp t to [0, 1] to restrict to the segment
    t = max(0.0L, min(1.0L, t));

    // Closest point on segment
    pair<ld, ld> closest = {a.first + t * dx, a.second + t * dy};

    // Distance from P to the closest point
    ld x = p.first - closest.first;
    ld y = p.second - closest.second;
    return sqrt(x * x + y * y);
}
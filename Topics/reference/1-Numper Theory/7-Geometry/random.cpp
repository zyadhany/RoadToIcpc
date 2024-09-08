
int distSq(pl p, pl q)
{
    return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
}
 
// This function returns true if (p1, p2, p3, p4) form a
// square, otherwise false
bool isSquare(vector<pair<ll, ll>> &X)
{
    pl p1, p2, p3, p4;
    p1 = X[0];
    p2 = X[1];
    p3 = X[2];
    p4 = X[3];
    int d2 = distSq(p1, p2); // from p1 to p2
    int d3 = distSq(p1, p3); // from p1 to p3
    int d4 = distSq(p1, p4); // from p1 to p4
 
    if (d2 == 0 || d3 == 0 || d4 == 0)
        return false;

    if (d2 == d3 && 2 * d2 == d4
        && 2 * distSq(p2, p4) == distSq(p2, p3)) {
        return true;
    }
 
    // The below two cases are similar to above case
    if (d3 == d4 && 2 * d3 == d2
        && 2 * distSq(p3, p2) == distSq(p3, p4)) {
        return true;
    }
    if (d2 == d4 && 2 * d2 == d3
        && 2 * distSq(p2, p3) == distSq(p2, p4)) {
        return true;
    }
 
    return false;
}

// rotate point b 90 degree around a
pl rotate_90(const pl& a, const pl& b) {
    int dx = b.first - a.first;
    int dy = b.second - a.second;

    int k_x = a.first - dy;
    int k_y = a.second + dx;

    return make_pair(k_x, k_y);
}



// get sin on angle
const double PI = 3.14159265358979323846264338327950288419716939937510;
sin(angle * PI / 180);


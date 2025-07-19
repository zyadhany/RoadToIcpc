#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

struct Circle {
    pair<ld, ld> center;
    ld radius2;
};

// Helper: convert pair<ll, ll> to pair<ld, ld>
pair<ld, ld> to_ld(pll p) {
    return { (ld)p.first, (ld)p.second };
}

Circle findCircleThroughThreePoints(pll A, pll B, pll C) {
    auto [x1, y1] = to_ld(A);
    auto [x2, y2] = to_ld(B);
    auto [x3, y3] = to_ld(C);

    ld a1 = x2 - x1, b1 = y2 - y1;
    ld a2 = x3 - x1, b2 = y3 - y1;

    ld d = 2 * (a1 * b2 - a2 * b1);
    if (abs(d) < 1e-9) {
        throw runtime_error("Points are collinear");
    }

    ld c1 = a1 * (x1 + x2) + b1 * (y1 + y2);
    ld c2 = a2 * (x1 + x3) + b2 * (y1 + y3);

    ld cx = (b2 * c1 - b1 * c2) / d;
    ld cy = (a1 * c2 - a2 * c1) / d;

    ld dx = cx - x1, dy = cy - y1;
    ld r2 = dx * dx + dy * dy;

    return { {cx, cy}, r2 };
}

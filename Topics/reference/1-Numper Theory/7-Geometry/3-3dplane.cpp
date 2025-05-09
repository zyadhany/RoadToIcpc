const ld PI = acos(-1);

struct point3d {
    ld x, y, z;
};

ld distance(point3d a, point3d b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) +
                 (a.y - b.y) * (a.y - b.y) +
                 (a.z - b.z) * (a.z - b.z));
}

ld angleBetween(point3d a, point3d b) {
    ld dot = a.x * b.x + a.y * b.y + a.z * b.z;
    ld mag_a = sqrtl(a.x * a.x + a.y * a.y + a.z * a.z);
    ld mag_b = sqrtl(b.x * b.x + b.y * b.y + b.z * b.z);
    ld costheta = dot / (mag_a * mag_b);
    return acosl(max((ld)-1, min((ld)1, costheta))) * 180.0 / PI;
}

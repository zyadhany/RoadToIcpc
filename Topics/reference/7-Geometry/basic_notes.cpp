/*
for regular polygon, with n points.
    - angle of each vertex = (n - 2) * 180 / n
    - tottal area = (n * a^2) / (4 * tan(PI / n))   (a = side length)
    - tottal area = (n * r^2 * sin(2 * PI / n)) / 2   (r = circumcircle radius)
    - tottal area = (n * r^2 * tan(PI / n)) / 2   (r = incircle radius)
    - tottal area = (n * R^2 * sin(PI / n) * cos(PI / n))   (R = circumcircle radius)
*/
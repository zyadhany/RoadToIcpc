// Rotating Calipers - Finding the diameter of a convex polygon
ld RotatinCalipers(vp &CH) {
    ll n = CH.size();
    ld mx = 0;

    for (int i = 0, j = 0; i < n; i++)
    {
        ld cur = dis(CH[i], CH[j]);
        while (dis(CH[i], CH[(j + 1) % n]) > cur) {
            j = (j + 1) % n;
            cur = dis(CH[i], CH[j]);
        }
        mx = max(mx, cur);
    }

    return mx;
}

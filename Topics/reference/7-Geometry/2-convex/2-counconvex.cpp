ll count_convex_quadrilaterals(vector<P> &v) {
    ll n = v.size();
    ll c = 0;
    
    // For each point as pivot
    for (int i = 0; i < n; i++) {
        vector<P> hold;
        // Translate points relative to pivot
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            hold.push_back(v[j] - v[i]);
        }
        
        // Sort by polar angle
        sort(hold.begin(), hold.end(), polar_cmp);
        
        int sz = hold.size();
        for (int j = 0; j < sz; j++) {
            // Ensure we have a full circle by duplicating points
            hold.push_back(hold[j]);
        }
        // Sweep to count convex quadrilaterals
        ll k = 1, s = 0;
        for (int j = 0; j < sz; j++) {
            k = max(k, j + 1ll);
            // Find points in same or next half-plane (convex condition)
            while (hold[j] * hold[k] > 0) s++, k++;
            c += (s * (s - 1)) / 2; // Choose 2 points for quadrilateral
            s = max(0ll, s - 1); // Reset for next iteration
        }
    }
    // Each quadrilateral is counted 4 times (once per vertex)
    return c;
}
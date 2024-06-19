// for each node calculate number of node it it's subtree.
ll CountSubTree(vi &count, int n, int p) {
    ll &res = count[n];
    if (res) return (res);
    
    res = 1;
    for (auto neg : adj[n]) {
        if (neg == p) continue;
        CountSubTree(count, neg, n);
        res += count[neg];
    }

    return (res);
}

/**
 * Diameter of Tree.
 * Case 1: two node in same subtree not including (n).
 * Case 2: node in anoters subtree so diameter include (n).
*/

/**
 * another approch:
 * we can take node a and find the farthest node of it (a).
 * the find the farthest node of (a) -> (b): that the diameter.
 */
ll DiameterOfTree(vii &Z, int n, int p) {
    ll &res = Z[n][1];
    if (res) return (res);
    Z[n][0] = 1;
    res = 1;
    
    vi X(2, 0);
    for (auto neg : adj[n]) {
        if (neg == p) continue;
        DiemeterOfTree(Z, neg, n);
        Z[n][0] = max(Z[n][0], Z[neg][0] + 1);
        X.push_back(Z[neg][0]);
        res = max(res, Z[neg][1]);
    }

    sort(X.rbegin(), X.rend());
    res = max(res, X[0] + X[1] + 1);
    return (res);
}

/**
 * All longest paths:
 * for each node find longest path from it to leaf.
 */
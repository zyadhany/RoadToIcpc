// conut the numper of spaning tree with n node : n^(n-2)
ll cntspanningtree(ll n) {
    if (n == 1) return 1;
    return fastpower(n, n-2);
}

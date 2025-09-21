ll k;
vector<viii> dp;
// given l, k: find count number from 1 to l it's summtion fo digit = k
ll reqsumm(vector<viii> &dp, string &s, ll pos, ll summ, ll sml, ll zer) {
    if (pos == s.size()) return summ == k; // add bestcase condtion
    ll &res = dp[pos][summ][sml][zer];
    if (~res) return (res);
    res = 0;

    if (zer) res = reqsumm(dp, s, pos + 1, summ, 1 ,0);

    for (int i = zer; i <= (sml? 9 : s[pos] - '0'); i++)
        res += reqsumm(dp, s, pos + 1, summ + i, sml | i < (s[pos] - '0'), 0);
    return (res);
}
req(dp, s, 0, 1, 0, 1);

/**
 * get in range lcm = k
 * add only 1,2,3,..9: 10,20,30...90
 */
ll req(vector<viii> &dp, string &s, ll pos, ll lc, ll sml, ll zer) {
    if (pos == s.size()) return (lc == k);
    ll &res = dp[pos][lc][sml][zer];
    if (~res) return (res);
    res = 0;
    if (zer) res = req(dp, s, pos + 1, lc, 1, zer);

    ll lim = 9;
    if (!sml) lim = s[pos] - '0';

    for (int i = 1; i <= lim; i++)
        res += req(dp, s, pos + 1, lcm(lc, i), sml | i < lim, 0);
    
    if (pos < s.size() - 1)
    for (int i = 10; i <= lim * 10; i+=10) {
        int xsml = sml;
        if (i < lim * 10 || s[pos + 1] != '0') xsml = 1;
        res += req(dp, s, pos + 2, lcm(lc, i), xsml, 0);
    }
    
    return (res);
}

ll sol(ll n) {
    string s = to_string(n);
    dp.assign(10, viii(25201, vii(2, vi(2, -1))));
    return req(dp, s, 0, 1, 0, 1);
}

void solve(int tc) {
    ll l, r, res;
    cin >> l >> r >> k;
    res = sol(r) - sol(l - 1);
    cout << res << '\n';
}

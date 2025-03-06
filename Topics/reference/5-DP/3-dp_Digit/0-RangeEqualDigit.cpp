/*
    in range from 1 to n, how much numbers that the count of it's digist equal to d is atleast half size of number,
*/

// ind, k's digits, leading zer, greater therhod.
ll dp[20][20][2][2];
ll req(string &s, ll ind, ll k, ll zer, ll grt, ll v) {
    ll &res = dp[ind][k][zer][grt];
    if (res != -1) return res;

    ll haf = (s.size() + 1) / 2;
    if (ind == s.size()) return res = (k>=haf);

    res = 0;
    ll st = 0;
    ll lim = 10;
    ll at = s[ind] - '0';
    ll ad = 0;

    if (!zer) {
        res += req(s, ind + 1, k, 0, 1, v);
        ll nd = (s.size() - ind + 1) / 2;
        ad = haf - nd;
        st = 1;
    }

    if (!grt) {
        res += req(s, ind + 1, k + (at == v) + ad, 1, 0, v);
        lim = at;
    }

    for (int i = st; i < lim; i++)
        res += req(s, ind + 1, k + (i == v) + ad, 1, 1, v);        

    return res;
}

void reset() {
    for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
    for (int j2 = 0; j2 < 2; j2++)
    for (int j3 = 0; j3 < 2; j3++)
        dp[i][j][j2][j3] = -1;
}

ll sol(ll n, ll d) {
    string s = to_string(n);
    ll res = 0;
    reset();
    res = req(s, 0, 0, 0, 0, d);
    return res;
}

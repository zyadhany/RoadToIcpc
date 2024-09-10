
vi dx = {-1, 0, 1, 0};
vi dy = {0, -1, 0, 1};

// travel in Spirale way: t for clock and anti clock
void SpiraleTravels(vii &X, ll n, ll m, ll a, ll b, ll t) {
    X[a][b] = 1;

    ll cnt = 1;
    ll cell = 1;
    ll l = a, r = b;

    ll rnd = 0;
    ll len = 0;
    while (cell < n * m)
    {
        len += (rnd % 2 == 0);
        ll div = ((rnd % 4) + 4) % 4;
        for (int i = 0; i < len; i++)
        {
            cnt++;
            l = l + dx[div];
            r = r + dy[div];
            if (l >= 1 && l <= n && r >= 1 && r <= m) {
                X[l][r] = min(X[l][r], cnt);
                cell++;
            }
        }

        rnd+=t;
    }
}

/*
given board 15*15
you can move to (x-2,y-1), (x-2,y+1), (x-1,y-2), (x+1,y-2)
you have k coins at (x_i,y_i)
determine if the first player wins
*/

ll dp[16][16];
ll grundy(ll x, ll y) {
    if (x <= 0 || x > 15 || y <= 0 || y > 15) return INT32_MAX; // invalid position
    ll &res = dp[x][y];
    if (res != -1) return res;

    vi X = {grundy(x-2,y-1), grundy(x-2,y+1), grundy(x-1, y-2), grundy(x+1,y-2)};
    sortx(X);
    X.erase(unique(all(X)), X.end());
    for (int i = 0; i < X.size(); i++)
        if (i != X[i]) return res = i;    
    return res = X.size();
}

void solve(int tc) {
    ll n;
    cin >> n;

    ll v = 0;
    for (int i = 0; i < n; i++)
    {
        ll x, y; cin >> x >> y;
        v ^= grundy(x, y);
    }
    
    if (!v) cout << "Second\n";
    else cout << "First\n";
}

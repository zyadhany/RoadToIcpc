// given M contraints that substring [l, l+k-1] must equal to [r, r+k-1]. find the number of different string of (a..z) that satisfy the constraints. 

struct DSU {
    vi P, R;
    ll get(ll n) {
        if (P[n] != n) return P[n] = get(P[n]);
        return n;
    }
    void add(ll u, ll v) {
        u = get(u), v = get(v);
        if (u == v) return;
        if (R[u] < R[v]) swap(u, v);
        R[u] += (R[u] == R[v]);
        P[v] = u;
    } 
    DSU(ll n=0) : P(n), R(n){
        for (int i = 0; i < n; i++) P[i] = i, R[i] = 0;        
    };
};

void solve(int tc) {
    ll n, m;

    cin >> n >> m;

    vector<DSU> D(20, DSU(n));

    while (m--)
    {
        ll i, j, k; cin >> i >> j >> k; i--, j--;
        for (int p = 20 - 1; p >= 0; p--)
        {
            if (!((1ll << p)&k)) continue;
            D[p].add(i, j);
            i += (1ll << p);
            j += (1ll << p);
        }
    }
    for (int j = 20 - 1; j > 0; j--)
    {
        for (int i = 0; i + (1ll << j) <= n; i++)
        {
            ll p = D[j].get(i);
            if (i == p) continue;
            D[j-1].add(i, p);
            D[j-1].add(i + (1ll << (j-1)), p + (1ll << (j-1)));
        }
    }
        
    ll cn = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == D[0].get(i)) cn++;
    }
    
    ll sol = 1;
    for (int i = 0; i < cn; i++)
    {
        sol = (sol * 26) % MODE;
    }
    cout << sol << '\n';
}

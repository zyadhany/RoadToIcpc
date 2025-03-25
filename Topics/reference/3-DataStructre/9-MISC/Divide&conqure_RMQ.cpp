const int MX = 2e5 + 5; // Adjust as needed
int n, q, x[MX], dat[18][MX], mask[MX]; 

void build(int l, int r, int lev) {
    if (l == r) return;
    int m = (l + r) / 2;
    
    dat[lev][m] = x[m];
    for (int i = m - 1; i >= l; i--) 
        dat[lev][i] = min(x[i], dat[lev][i + 1]);

    dat[lev][m + 1] = x[m + 1];
    for (int i = m + 2; i <= r; i++) 
        dat[lev][i] = min(dat[lev][i - 1], x[i]);

    for (int i = m + 1; i <= r; i++) 
        mask[i] ^= (1 << lev);
    
    build(l, m, lev + 1);
    build(m + 1, r, lev + 1);
}

int query(int a, int b) {
    if (a == b) return x[a];
    int bits = __builtin_ctz(mask[a] ^ mask[b]);
    return min(dat[bits][a], dat[bits][b]);
}

void INIT(ll n) {
    memset(mask, 0, n * sizeof(mask[0]));
    build(0, n - 1, 0);
}

void solve(int tc) {
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> x[i];

    INIT(n);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a - 1, b - 1) << "\n";
    }
}

/** **/
const int maxn = 1e6;
const int logn = 21;
const int maxq = 2e7;
int P;

int v[maxn];
int dvc[logn][maxn];
int b[(int)5e5];

int ADD(int a, int b) { return (a + b) % P; }
int MULT(int a, int b) { return (a * b) % P; }

void init(int lvl, int l, int r) {
    if (l == r) {
        dvc[lvl][l] = v[l];
        return;
    }
    int m = (l + r) >> 1;
    dvc[lvl][m] = v[m], dvc[lvl][m + 1] = v[m + 1];
    for (int i = m - 1; i >= l; i--) dvc[lvl][i] = MULT(v[i], dvc[lvl][i + 1]);
    for (int i = m + 2; i <= r; i++) dvc[lvl][i] = MULT(dvc[lvl][i - 1], v[i]);
    
    init(lvl + 1, l, m);
    init(lvl + 1, m + 1, r);
}

int qry(int lvl, int l, int r, int L, int R) {
    if (l == r) { return v[l]; }
    int m = (l + r) >> 1;
    if (R <= m) return qry(lvl + 1, l, m, L, R);
    if (L >= m+1) return qry(lvl + 1, m + 1, r, L, R);
    return MULT(dvc[lvl][L], dvc[lvl][R]);
}
// init(0, 0, n - 1);
// cout << qry(0, 0, n - 1, l, r) << '\n';

// bool take 1 byte not 1 bit
// we can make 1 byte intiger and make it work for 8 bits as bool.
uint8_t G[13][5005][(5005 + 7) / 8];
inline void set_bit(int i, int j, int k, bool val) {
    if (val)
        G[i][j][k / 8] |= (1 << (k % 8));
    else
        G[i][j][k / 8] &= ~(1 << (k % 8));
}
inline bool get_bit(int i, int j, int k) {
    return (G[i][j][k / 8] >> (k % 8)) & 1;
}


// if want bitset with variable size
const int N = 2e5+10;
template<int mxn>
ll solve(ll n, ll k) {
    if (mxn <= n) {
        return solve<min(mxn*2, N)>(n, k);
    }
    bitset<mxn> bt;
    return mxn;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int size = 1;

    // freopen("boards.in", "r", stdin);
    // freopen("boards.out", "w", stdout);

    cin >> size;
    for (int i = 1; i <= size; i++) {
        int n, k; cin >> n >> k;
        cout << solve<1>(n, k) << '\n';
    }
}
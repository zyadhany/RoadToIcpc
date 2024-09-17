// prefix summ 1-d array,
// summ(a, b) = pref[b] - pref[a- 1]
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
    prefixSum[0] = arr[0];
    // Adding present element with previous element
    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];
}


/**
 * 2-D Array
 * summ({a-b},{c,d})=pref[a][b]+pref[c-1][d-1]-pref[a][d-1]-pref[b-1][b]
 */
void solve(ll tc) {
    ll n, q;

    cin >> n >> q;

    vcc X(n + 1, vc(n + 1));
    vii Z(n + 1, vi(n + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> X[i][j];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            Z[i][j] = (X[i][j] == '*');
            Z[i][j] += Z[i - 1][j] + Z[i][j - 1];
            Z[i][j] -= Z[i - 1][j - 1];            
        }
    }
    
    while (q--)
    {
        ll lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        if (lx > rx) swap(lx, rx);
        if (ly > ry) swap(ly, ry);

        cout << Z[rx][ry] - Z[rx][ly - 1]
                -Z[lx - 1][ry] + Z[lx - 1][ly - 1] << '\n';
    }
    
}


/**
 * Given Diamond Shape convert it to squere
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * ===>>>
 * 0 0 1 0 0 
 * 0 4 0 2 0 
 * 7 0 5 0 3 
 * 0 8 0 6 0 
 * 0 0 9 0 0 
 */
vii ConverDiamondToMatix(vii &X) {
    ll n = X.size();
    vii Z(n * 2 - 1, vi(2 * n - 1));
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Z[i + j][n - i + j - 1] = X[i][j];
    return Z;    
}

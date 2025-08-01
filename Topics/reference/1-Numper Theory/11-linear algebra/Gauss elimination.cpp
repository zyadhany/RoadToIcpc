const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

// Time : O(n^3)
// The function returns the number of solutions of the system  $(0, 1, infty)$ . If at least one solution exists, then it is returned in the vector ans.
int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

// Solve modular SLAE 
// Time : O(n^3 / 64)
int gauss (vector < bitset<N> > a, int n, int m, bitset<N> & ans) {
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        for (int i=row; i<n; ++i)
            if (a[i][col]) {
                swap (a[i], a[row]);
                break;
            }
        if (! a[row][col])
            continue;
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row && a[i][col])
                a[i] ^= a[row];
        ++row;
    }
        // The rest of implementation is the same as above
}



vi gauss(vii A, vi b) {
    int n = A.size();
    vi where(n, -1);  // where[i] = row where variable i was used as pivot

    for (int col = 0, row = 0; col < n && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i) {
            if (A[i][col]) {
                sel = i;
                break;
            }
        }

        if (A[sel][col] == 0) continue;

        swap(A[sel], A[row]);
        swap(b[sel], b[row]);
        where[col] = row;

        ll inv_pivot = inv(A[row][col]);
        for (int j = col; j < n; ++j)
            A[row][j] = A[row][j] * inv_pivot % MODE;
        b[row] = b[row] * inv_pivot % MODE;

        for (int i = 0; i < n; ++i) {
            if (i != row && A[i][col]) {
                ll factor = A[i][col];
                for (int j = col; j < n; ++j)
                    A[i][j] = (A[i][j] - factor * A[row][j] % MODE + MODE) % MODE;
                b[i] = (b[i] - factor * b[row] % MODE + MODE) % MODE;
            }
        }
        row++;
    }

    // check for inconsistency
    for (int i = 0; i < n; ++i) {
        bool all_zero = true;
        for (int j = 0; j < n; ++j)
            if (A[i][j]) all_zero = false;
        if (all_zero && b[i] != 0) {
            // cout << "No solution\n";
            return {};
        }
    }

    // construct solution (free variables = 0)
    vi ans(n);
    for (int i = 0; i < n; ++i) {
        if (where[i] != -1)
            ans[i] = b[where[i]];
        else
            ans[i] = 0; // free variable set to 0
    }
    return ans;
}

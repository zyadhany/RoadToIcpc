// Fenwick Tree array
vi Z;

// Initialize Fenwick Tree with size n+1 (1-based index)
void initialize(int n) {
    Z.assign(n + 1, 0);
}

// Add k at index i
void update(int i, ll k) {
    for (; i < Z.size(); i += i & -i) {
        Z[i] += k;
    }
}

// Get sum of elements in the range [1, r]
ll getsum(int r) {
    ll sum = 0;
    for (; r > 0; r -= r & -r) {
        sum += Z[r];
    }
    return sum;
}

// Get sum of elements in the range [l, r]
ll range_sum(int l, int r) {
    return getsum(r) - getsum(l - 1);
}

void solve() {
    int n, q;
    cin >> n >> q;

    // Initialize Fenwick Tree
    initialize(n);

    // Read initial values and update Fenwick Tree
    for (int i = 1; i <= n; i++) {
        ll val;
        cin >> val;
        update(i, val);
    }

    // Process queries
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        ll result = range_sum(a, b);
        cout << result << endl;
    }
}

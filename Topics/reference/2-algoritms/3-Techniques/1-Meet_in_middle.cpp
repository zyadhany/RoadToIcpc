// https://codeforces.com/blog/entry/95571

// when the solution is very large so split it into 2sets

// Given Array of n <= 40 find how many subset = x
void solve(ll tc) {
    ll n, l, r, summ, re, x;
    
    cin >> n >> x;

    summ = 0;
    l = n / 2; r = l + n % 2;
    vi X(n);
    unordered_map<ll, int> Y;
    Y.reserve(1<<(l));

    for (int i = 0; i < n; i++)
        cin >> X[i];

    for (int i = 0; i < (1 << l); i++)
    {
        re = 0;
        for (int j = 0; j < l; j++)
            if (i & (1 << j)) re += X[j];
        Y[re]++; 
    }
    
    for (int i = 0; i < (1 << r); i++)
    {
        re = 0;
        for (int j = l; j < n; j++)
            if (i & (1 << (j - l))) re += X[j];
        if(re <= x && Y.find(x - re) != Y.end())
            summ += Y[x - re];
    }
    
    cout << summ << '\n';
}
